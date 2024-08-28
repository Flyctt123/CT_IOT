#ifndef DEVICE_MONITOR_H
#define DEVICE_MONITOR_H

#include <windows.h>
#include <QSysInfo>
#include <QWidget>
#include <QtCharts>

namespace Ui {
class device_monitor;
}

class device_monitor : public QWidget
{
    Q_OBJECT

public:
    explicit device_monitor(QWidget *parent = nullptr);
    ~device_monitor();

private slots:
    void intdata();
    QString getCpu();
    void getMemory();
    void timeUpdate();
    void data_ReFresh();
private:
    Ui::device_monitor *ui;
    QTimer *resource_Time;

    /*柱状图*/
    QChart *chart;
    QBarSeries *series;

    /*曲线*/
    QSplineSeries *series1;
    QSplineSeries *series2;
    QSplineSeries *series3;
    QChart *chart1;

    /*饼状图*/
    QPieSeries * my_pieSeries;
    QPieSlice *pieSlice_running;
    QPieSlice *pieSlice_noconnect;
    QPieSlice *pieSlice_idle;
    QChart *chart3;
    QChartView *chartView3;

    MEMORYSTATUSEX statusex;
};

#endif // DEVICE_MONITOR_H
