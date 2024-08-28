#include "device_monitor.h"
#include "ui_device_monitor.h"
#include <QtCharts>

device_monitor::device_monitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::device_monitor)
{
    ui->setupUi(this);

    /*柱状图*/
    QBarSet *set0 = new QBarSet("A区");
    QBarSet *set1 = new QBarSet("B区");
    QBarSet *set2 = new QBarSet("C区");

    *set0 << 1 << 2 << 3 << 4;
    *set1 << 5 << 0 << 0 << 4;
    *set2 << 3 << 5 << 8 << 13;

    series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("月度能量消耗");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    chart->createDefaultAxes();//设置坐标轴
    chart->setTheme(QChart::ChartThemeBlueCerulean);//设置画面主题

    QChartView *chartView = new QChartView();
    chartView->setChart(chart);
    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addWidget(chartView);
    ui->groupBox_5->setLayout(vLayout);

    /*曲线*/
    // 创建数据系列
    series1 = new QSplineSeries();//曲线
    series2 = new QSplineSeries();//曲线
    series3 = new QSplineSeries();//曲线
    //QLineSeries *series1 = new QLineSeries();//折线

    series1->setName("A区");
    series1->append(0, 6);
    series1->append(1, 4);
    series1->append(2, 7);
    series1->append(3, 1);
    series1->append(4, 5);
    series1->append(5, 2);
    series1->append(6, 6);
    series1->append(7, 4);
    series1->append(8, 7);
    series1->append(9, 1);
    series1->append(10, 5);
    series1->append(11, 2);

    series2->setName("B区");
    series2->append(0, 1);
    series2->append(1, 6);
    series2->append(2, 3);
    series2->append(3, 2);
    series2->append(4, 7);
    series2->append(5, 6);
    series2->append(6, 1);
    series2->append(7, 6);
    series2->append(8, 3);
    series2->append(9, 2);
    series2->append(10, 7);
    series2->append(11, 6);

    series3->setName("C区");
    series3->append(0, 6);
    series3->append(1, 4);
    series3->append(2, 7);
    series3->append(3, 4);
    series3->append(4, 5);
    series3->append(5, 6);
    series3->append(6, 6);
    series3->append(7, 4);
    series3->append(8, 7);
    series3->append(9, 4);
    series3->append(10, 5);
    series3->append(11, 6);

    // 创建图表并添加数据系列
    chart1 = new QChart();
    //chart1->legend()->hide();//表头隐藏
    chart1->addSeries(series1);
    chart1->addSeries(series2);
    chart1->addSeries(series3);

    chart1->createDefaultAxes(); //创建坐标轴
    chart1->axes(Qt::Horizontal).first()->setRange(0, 11);//横坐标
    chart1->axes(Qt::Vertical).first()->setRange(0, 8);//纵坐标
    chart1->setTitle("月度省电量");
    chart1->setTheme(QChart::ChartThemeBlueCerulean);//设置画面主题
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    // 创建图表视图并显示图表
    QChartView *chartView1 = new QChartView(chart1);
    chartView1->setRenderHint(QPainter::Antialiasing);//优化锯齿状

    QVBoxLayout* vLayout1 = new QVBoxLayout();
    vLayout1->addWidget(chartView1);
    ui->groupBox_9->setLayout(vLayout1);

    /*饼状图*/
    my_pieSeries = new QPieSeries();
    //中间圆与大圆的比例
    my_pieSeries->setHoleSize(0.35);
    //扇形及数据
    pieSlice_running = new QPieSlice();
    pieSlice_running->setValue(25);//扇形占整个圆的百分比
    pieSlice_running->setLabel("A区25%");
    pieSlice_running->setLabelVisible();//设置标签可见,缺省不可见
    my_pieSeries->append(pieSlice_running);

    pieSlice_noconnect = new QPieSlice();
    pieSlice_noconnect->setValue(25);
    pieSlice_noconnect->setLabel("B区25%");
    pieSlice_noconnect->setLabelVisible();
    my_pieSeries->append(pieSlice_noconnect);

    pieSlice_idle = new QPieSlice();
    pieSlice_idle->setValue(50);
    pieSlice_idle->setLabel("C区50%");
    pieSlice_idle->setLabelVisible();
    my_pieSeries->append(pieSlice_idle);
    // 图表视图
    chart3 = new QChart();
    chart3->setTitle("综合耗电量占比");
    chart3->addSeries(my_pieSeries);
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->setTheme(QChart::ChartThemeBlueCerulean);//设置画面主题
    chartView3 = new QChartView();
    chartView3->setRenderHint(QPainter::Antialiasing);
    chartView3->setChart(chart3);

    QVBoxLayout* vLayout3 = new QVBoxLayout();
    vLayout3->addWidget(chartView3);
    ui->groupBox_3->setLayout(vLayout3);

    resource_Time = new QTimer(this);
    connect(resource_Time, &QTimer::timeout, this, &device_monitor::timeUpdate);
    resource_Time->start(1000);
}

device_monitor::~device_monitor()
{
    delete ui;
}

void device_monitor::intdata()
{

}

QString device_monitor::getCpu()
{
    // FILETIME 是一个用两个32位字节表示时间值的结构体
    //  dwLowDateTime 低位32位时间值。
    //  dwHighDateTime 高位32位时间值
    static FILETIME preidleTime;
    static FILETIME prekernelTime;
    static FILETIME preuserTime;

    FILETIME idleTime;
    FILETIME kernelTime;
    FILETIME userTime;

    // 三个参数分别为 cpu空闲时间 内核进程占用时间 用户进程占用时间
    GetSystemTimes(&idleTime, &kernelTime, &userTime);

    quint64 x, y;
    int idle, kernel, user;

    x = (preidleTime.dwHighDateTime << 31) | preidleTime.dwLowDateTime;
    y = (idleTime.dwHighDateTime << 31) | idleTime.dwLowDateTime;
    idle = y - x;

    x = (prekernelTime.dwHighDateTime << 31) | prekernelTime.dwLowDateTime;
    y = (kernelTime.dwHighDateTime << 31) | kernelTime.dwLowDateTime;
    kernel = y - x;

    x = (preuserTime.dwHighDateTime << 31) | preuserTime.dwLowDateTime;
    y = (userTime.dwHighDateTime << 31) | userTime.dwLowDateTime;
    user = y - x;

    int cpuPercent = (kernel + user - idle) * 100 / (kernel + user);

    preidleTime = idleTime;
    prekernelTime = kernelTime;
    preuserTime = userTime;

    QString msg = QString("CPU Usage Rate: %1%")
        .arg(cpuPercent);
    return msg;
}

void device_monitor::getMemory()
{
    statusex.dwLength=sizeof(statusex);
    GlobalMemoryStatusEx(&statusex);
    float memory = float(statusex.ullTotalPhys/1024/1024) / 1024;
    ui->label_4->setText("Total Memory: " + QString::number(memory,'f', 2) + "G");
    ui->label_5->setText("Memory Usage Rate: " + QString::number(statusex.dwMemoryLoad) + "%");
}

void device_monitor::timeUpdate()
{
    ui->label_3->setText(getCpu());
    getMemory();
}

void device_monitor::data_ReFresh()
{
    /*柱状图*/
    series->clear();

    QBarSet *set0 = new QBarSet("A区");
    QBarSet *set1 = new QBarSet("B区");
    QBarSet *set2 = new QBarSet("C区");

    *set0 << 1 << 2 << 3 << 4;
    *set1 << 5 << 0 << 0 << 4;
    *set2 << 3 << 5 << 8 << 13;

    series->append(set0);
    series->append(set1);
    series->append(set2);

    /*曲线*/
    series1->clear();
    series2->clear();
    series3->clear();

    series1->append(0, 6);
    series1->append(1, 4);
    series1->append(2, 7);
    series1->append(3, 1);
    series1->append(4, 5);
    series1->append(5, 2);
    series1->append(6, 6);
    series1->append(7, 4);
    series1->append(8, 7);
    series1->append(9, 1);
    series1->append(10, 5);
    series1->append(11, 2);

    series2->append(0, 1);
    series2->append(1, 6);
    series2->append(2, 3);
    series2->append(3, 2);
    series2->append(4, 7);
    series2->append(5, 6);
    series2->append(6, 1);
    series2->append(7, 6);
    series2->append(8, 3);
    series2->append(9, 2);
    series2->append(10, 7);
    series2->append(11, 6);

    series3->append(0, 6);
    series3->append(1, 4);
    series3->append(2, 7);
    series3->append(3, 4);
    series3->append(4, 5);
    series3->append(5, 6);
    series3->append(6, 6);
    series3->append(7, 4);
    series3->append(8, 7);
    series3->append(9, 4);
    series3->append(10, 5);
    series3->append(11, 6);

    /*饼状图*/
    pieSlice_running->setValue(0);
    pieSlice_noconnect->setValue(0);
    pieSlice_idle->setValue(0);

    pieSlice_running->setValue(25);//扇形占整个圆的百分比
    my_pieSeries->append(pieSlice_running);

    pieSlice_noconnect->setValue(25);
    my_pieSeries->append(pieSlice_noconnect);

    pieSlice_idle->setValue(50);
    my_pieSeries->append(pieSlice_idle);
}
