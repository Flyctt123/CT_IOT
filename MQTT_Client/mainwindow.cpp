#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonConnect_clicked()
{
    mqtt = new QMqttClient();
    mqtt->setHostname(ui->lineEditHost->text());
    mqtt->setPort(ui->lineEditport->text().toUInt());//端口
    connect(mqtt, SIGNAL(connected()), this, SLOT(mqtt_connect_success()));
    connect(mqtt, SIGNAL(disconnected()), this, SLOT(mqtt_disconnect()));
    connect(mqtt, SIGNAL(messageReceived(QByteArray,QMqttTopicName)), this, SLOT(receiveMess(QByteArray,QMqttTopicName)));

    mqtt->setClientId("a1uEFOvKWyp.device0|securemode=2,signmethod=hmacsha256,timestamp=1715677486951|");
    mqtt->setUsername(ui->lineEdit_name->text());
    mqtt->setPassword(ui->lineEdit_password->text());

    /*当"Clean Session"会话标志，设置为true时，表示每次连接都是一个新的会话，之前的订阅、发布等状态都会被清除。
                    设置为false时，表示客户端与代理断开连接后，会话状态会被保留，包括之前的订阅和发布消息。*/
    mqtt->setCleanSession(true);
    mqtt->setKeepAlive(60);                        // 设置保持连接时间
    mqtt->connectToHost(); //连接mqtt
}

void MainWindow::mqtt_connect_success()
{
    ui->textBrowser->setText(QObject::tr("连接成功"));
}

void MainWindow::mqtt_disconnect()
{
    ui->textBrowser->setText("连接断开");
}

/*接收数据*/
void MainWindow::receiveMess(const QByteArray &msg,const QMqttTopicName topic)
{
    QString content;
    content += QLatin1String(" Received Topic: ") + topic.name() + QLatin1Char('\n');
    content += QLatin1String(" Message: ") + msg + QLatin1Char('\n');
    ui->receive_msg->setPlainText(content);

}

void MainWindow::on_buttonPublish_clicked()
{
    mqtt->publish(QMqttTopicName(ui->lineEditTopic->text()), ui->lineEditMessage->text().toLocal8Bit(),1,true);//发布等级qos=1
}

void MainWindow::on_buttonSubscribe_clicked()//订阅
{
    QMqttSubscription *substate = mqtt->subscribe(ui->lineEditTopic->text(),1);

    QEventLoop loop;
    QTimer::singleShot(200, &loop, &QEventLoop::quit);//延迟50ms
    loop.exec();

    if(substate->state() == QMqttSubscription::Subscribed)//订阅成功
       ui->textBrowser->setText("订阅成功");
}
