#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMqtt/qmqttclient.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void subscribed(QString,quint8);
private slots:
    void mqtt_connect_success();

    void mqtt_disconnect();

    void receiveMess(const QByteArray &msg,const QMqttTopicName topic);

    void on_buttonConnect_clicked();

    void on_buttonPublish_clicked();

    void on_buttonSubscribe_clicked();

private:
    Ui::MainWindow *ui;

    QMqttClient *mqtt;
};
#endif // MAINWINDOW_H
