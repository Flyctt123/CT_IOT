#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_data_query.h"
#include "device_monitor.h"
#include <QProcess>

#include <iostream>
#include <list>
#include <stdlib.h>
#include <QWindow>

#define windows
//#define linux

//嵌入外部程序界面
#ifdef windows

#include <windows.h>
WId Pid2Wid(quint64 procID, const char *lpszClassName)
{
    char szBuf[256];
    HWND hWnd = GetTopWindow(GetDesktopWindow());
    while (hWnd)
    {
        DWORD wndProcID = 0;
        GetWindowThreadProcessId(hWnd, &wndProcID);
        if (wndProcID == procID)
        {
            GetClassName(hWnd, szBuf, sizeof(szBuf));
            if (strcmp(szBuf, lpszClassName) == 0)
            {
                return (WId)hWnd;
            }
        }
        hWnd = GetNextWindow(hWnd, GW_HWNDNEXT);
    }
    return 0;
}

#else

#include <X11/Xlib.h>
#include <X11/Xatom.h>

class WindowsMatchingPid
{
    public:
    WindowsMatchingPid(Display *display, Window wRoot, unsigned long pid)
    : _display(display)
    , _pid(pid)
    {
        // Get the PID property atom.
        _atomPID = XInternAtom(display, "_NET_WM_PID", True);
        if (_atomPID == None)
        {
            cout << "No such atom" << endl;
            return;
        }

        search(wRoot);
    }

    inline const list<Window> &result() const { return _result; }

    private:
    unsigned long  _pid;
    Atom           _atomPID;
    Display       *_display;
    list<Window>   _result;

    private:
    void search(Window w)
    {
        // Get the PID for the current Window.
        Atom           type;
        int            format;
        unsigned long  nItems;
        unsigned long  bytesAfter;
        unsigned char *propPID = 0;
        if (Success == XGetWindowProperty(_display,
        w,
        _atomPID,
        0,
        1,
        False,
        XA_CARDINAL,
        &type,
        &format,
        &nItems,
        &bytesAfter,
        &propPID))
        {
            if (propPID != 0)
            {
                // If the PID matches, add this window to the result set.
                if (_pid == *((unsigned long *)propPID))
                _result.push_back(w);
                XFree(propPID);
            }
        }

        // Recurse into child windows.
        Window    wRoot;
        Window    wParent;
        Window   *wChild;
        unsigned  nChildren;

        if (0 != XQueryTree(_display, w, &wRoot, &wParent, &wChild, &nChildren))
        {
            for (unsigned i = 0; i < nChildren; i++)
            search(wChild[i]);
        }
    }
};

int Pid2Wid(int nPid)
{
    // Start with the root window.
    char *pDsp = getenv("DISPLAY");
    Display *display = XOpenDisplay(pDsp);

    if (display == NULL)
    {
        return 0;
    }

    WindowsMatchingPid match(display, XDefaultRootWindow(display), nPid);
    const list<Window> &result = match.result();
    if (result.size())
    {
        return (unsigned long)(*result.begin());
    }
    else
    {
        return 0;
    }
}

#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取主屏分辨率
    desktopwidget = QApplication::desktop();
    this->setGeometry(0,0,desktopwidget->width(),desktopwidget->height());
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);//取消标题栏

    toolButtonList.append(ui->device_monitor);
    toolButtonList.append(ui->data_query);
    toolButtonList.append(ui->parameter_set);
    toolButtonList.append(ui->system_set);
    toolButtonList.append(ui->restart);
    toolButtonList.append(ui->net_info);
    toolButtonList.append(ui->video_monitor);
    toolButtonList.append(ui->configuration);
    button_init();

    device_monitor_page  = new device_monitor();
    data_query_page  = new data_query();
    ui->stackedWidget->addWidget(device_monitor_page);
    ui->stackedWidget->addWidget(data_query_page);
    ui->stackedWidget->setCurrentWidget(device_monitor_page);
    button_press_set(ui->device_monitor);

    timer_sysTime = new QTimer(this);
    connect(timer_sysTime, &QTimer::timeout, this, &MainWindow::timeUpdate);
    timer_sysTime->start(1000);

    connect(this,SIGNAL(signal_device_monitor(int)),device_monitor_page,SLOT(data_ReFresh(void)));

    // 创建QProcess对象
    RunTime_Process = new QProcess(this);
    connect(RunTime_Process, SIGNAL(started()), this, SLOT(RunTime_Process_Start_Slot()));
    connect(RunTime_Process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(RunTime_Process_Stop_Slot()));
    connect(RunTime_Process, SIGNAL(readyReadStandardError()), this, SLOT(RunTime_Process_Error_Slot()));//链接信号到槽函数，处理错误
    connect(RunTime_Process, SIGNAL(readyRead()), this, SLOT(RunTime_Process_Read_Slot()));

    MQTT_Client_Process = new QProcess(this);
    connect(MQTT_Client_Process, SIGNAL(readyRead()), this, SLOT(RunTime_Process_Read_Slot()));

    QString currentPath = QDir::currentPath();
    //返回上一级目录的路径
    QDir dir(currentPath);
    if (dir.cdUp())
    {
        exe_dirPath = dir.absolutePath();//绝对路径
        RunTime_Process->start(exe_dirPath + "/RunTime/debug/RunTime.exe");
    }
    else
    {
        qDebug() << "Failed to return to previous level";
    }

    local_server = new QLocalServer(this);
    local_server->removeServer("comm_server");//先删除再创建
    if(local_server->listen("comm_server") ) //监听
    {
       connect(local_server,SIGNAL(newConnection()),this,SLOT(LoaclServer_newConnection()));
       printf("comm_server listen success!!\n");
    }
    else
       printf("comm_server listen fail\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Window_min_clicked()
{
    this->showMinimized();
}

void MainWindow::external_Window_inlay()
{
    MQTT_Client_Process->setProcessChannelMode(QProcess::ForwardedErrorChannel);//将标准错误通道合并至标准输出通道。
#ifdef windows
    MQTT_Client_Process->start(exe_dirPath + "/MQTT_Client/debug/MQTT_Client.exe");
    MQTT_Client_Process->waitForFinished(1000);
    WId wid = Pid2Wid(MQTT_Client_Process->processId(), "Qt5QWindowIcon");//获取进程ID
#else
    pProc->start("xterm");// X11自带的xterm、xclock可以正确地被嵌入启动，xedit等能够被启动，不能得到窗口ID，故不能被正确嵌入。Qt编写的程序应该均能被正确嵌入。
    pProc->waitForFinished(1000);
    WId wid = Pid2Wid(pProc->processId());
#endif
    QWindow *pWin = QWindow::fromWinId(wid);
    qDebug()<<(int)MQTT_Client_Process->processId()<<pWin<<(int)wid;
    if (pWin != NULL)
    {
        QWidget *pWid = QWidget::createWindowContainer(pWin, this);//获取一个子进程窗口的widget
        ui->stackedWidget->addWidget(pWid);
        ui->stackedWidget->setCurrentWidget(pWid);
    }
}

void MainWindow::on_Window_close_clicked()
{
    this->close();
    if(nullptr != RunTime_Process)
        RunTime_Process->close();
}

void MainWindow::timeUpdate()
{
    dateTime = QDateTime::currentDateTime();
    ui->label_sysTime->setText(dateTime.toString("yyyy-MM-dd \nHH:mm:ss"));
}

void MainWindow::RunTime_Process_Start_Slot()
{
    qDebug()<<"RunTime Start OK!";
}

void MainWindow::RunTime_Process_Stop_Slot()
{
    qDebug()<<"RunTime Stop!";
}

void MainWindow::RunTime_Process_Error_Slot()
{
    qDebug()<<"RunTime Start Error!";
}

void MainWindow::RunTime_Process_Read_Slot()
{
    qDebug()<<"RunTime log:" << RunTime_Process->readAll();
}

void MainWindow::MQTT_Client_Process_Read_Slot()
{
    qDebug()<<"MQTT_Client log:" << MQTT_Client_Process->readAll();
}

void MainWindow::LoaclServer_newConnection()
{
    qDebug()<<"LoaclServer NewConnection!";
    QLocalSocket *newsocket = local_server->nextPendingConnection();  //获取连接上的客户端句柄
    connect(newsocket, SIGNAL(readyRead()), this, SLOT(LoaclServer_Receive())); //关联数据接收槽函数
}

void MainWindow::LoaclServer_Receive()
{
    QLocalSocket *local = static_cast<QLocalSocket *>(sender());//对应接收socket
    if (!local)
        return;

    QByteArray local_receive_data = local->readAll();
    qDebug()<<"local_server receive_data:"<<local_receive_data;

    if(LoaclServer_FirstConnect(local))
    {
        local->write(QString("welcome local server!").toUtf8());
    }
    else
    {
        local->write(local_receive_data);//接收数据回传
    }
}

bool MainWindow::LoaclServer_FirstConnect(QLocalSocket *newsocket)
{
    int len = local_sockets.length();
    for(int i=0; i<len; i++)
    {
        if(newsocket == (QLocalSocket *)local_sockets.at(i))
            return false;
    }
    local_sockets.append(newsocket);
    return true;
}

void MainWindow::button_init()
{
    for(uint8_t i=0; i<toolButtonList.size(); i++)
    {
        button_normal_set(toolButtonList.at(i));
    }
}

void MainWindow::button_normal_set(QToolButton *toolButton)
{
    toolButton->setStyleSheet(/**正常情况下样式**/
                               "QToolButton{"
                                   "font: bold;"
                                   "color: #105a9a;"
                                   "border-radius: 15px;"
                                   "border-style: solid;"
                                   "border-width: 2px;"
                                   "padding: 5px;"
                               "}");
}

void MainWindow::button_press_set(QToolButton *toolButton)
{
    button_init();
    toolButton->setStyleSheet("QToolButton{"
                              "font: bold;"
                              "color: #105a9a;"
                              "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #306cb9, stop:1 #76e7ec);"
                              "border-radius: 15px;"
                              "border-style: solid;"
                              "border-width: 2px;"
                              "padding: 5px;"
                           "}");
}

void MainWindow::on_device_monitor_clicked()
{
    emit signal_device_monitor(1);
    ui->stackedWidget->setCurrentWidget(device_monitor_page);
    button_press_set(ui->device_monitor);
}

void MainWindow::on_data_query_clicked()
{
    ui->stackedWidget->setCurrentWidget(data_query_page);
    button_press_set(ui->data_query);
    external_Window_inlay();
}

void MainWindow::on_parameter_set_clicked()
{
    button_press_set(ui->parameter_set);
}

void MainWindow::on_system_set_clicked()
{
    button_press_set(ui->system_set);
}

void MainWindow::on_restart_clicked()
{
    button_press_set(ui->restart);
}

void MainWindow::on_net_info_clicked()
{
    button_press_set(ui->net_info);
}

void MainWindow::on_configuration_clicked()
{
    button_press_set(ui->configuration);
}

void MainWindow::on_video_monitor_clicked()
{
    button_press_set(ui->video_monitor);
}

//延时函数 ms
void MainWindow::sleepMs(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100); //非阻塞式
}
