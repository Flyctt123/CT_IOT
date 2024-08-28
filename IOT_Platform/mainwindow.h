#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDesktopWidget>
#include <QDateTime>
#include <QTimer>
#include <QStackedWidget>
#include <QToolButton>
#include <device_monitor.h>
#include <data_query.h>
#include <QLocalSocket>
#include <QLocalServer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //获取主屏分辨率
    QDesktopWidget *desktopwidget;
    QLocalServer *local_server;
    QString exe_dirPath;//可执行文件路径
private slots:

    void on_Window_close_clicked();
    void on_Window_min_clicked(void);
    void external_Window_inlay();//外部窗口嵌入
    void timeUpdate(void);
    void sleepMs(int msec);
    void RunTime_Process_Start_Slot(void);
    void RunTime_Process_Stop_Slot(void);
    void RunTime_Process_Error_Slot(void);
    void RunTime_Process_Read_Slot(void);

    void MQTT_Client_Process_Read_Slot(void);

    void LoaclServer_newConnection();
    void LoaclServer_Receive();
    bool LoaclServer_FirstConnect(QLocalSocket *newsocket);


    void button_init();
    void button_normal_set(QToolButton *toolButton);
    void button_press_set(QToolButton *toolButton);

    void on_device_monitor_clicked();
    void on_data_query_clicked();
    void on_parameter_set_clicked();
    void on_system_set_clicked();
    void on_restart_clicked();

    void on_net_info_clicked();
    void on_configuration_clicked();
    void on_video_monitor_clicked();

private:
    Ui::MainWindow *ui;

    QList<QToolButton *> toolButtonList;

    device_monitor *device_monitor_page;
    data_query *data_query_page;

    QDateTime dateTime;
    QTimer *timer_sysTime;

    QProcess *RunTime_Process;
    QProcess *MQTT_Client_Process;

    QList<QLocalSocket *> local_sockets;//利用Qlist来存储新连接
signals:
    void signal_device_monitor(int);
};
#endif // MAINWINDOW_H
