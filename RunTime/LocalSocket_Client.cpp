#include "localSocket_Client.h"

localSocket_Client::localSocket_Client(QObject *parent) : QObject(parent)
{
    reconnect_timer = new QTimer(this);
    connect(reconnect_timer,SIGNAL(timeout()),this,SLOT(reconnect_to_server()));

    m_socket = new QLocalSocket(this);

    connect(m_socket,SIGNAL(error(QLocalSocket::LocalSocketError)),this,SLOT(connect_error(QLocalSocket::LocalSocketError))); //数据接收
    connect(m_socket,SIGNAL(connected()),this,SLOT(connect_success()));  //数据接收
    connect(m_socket,SIGNAL(disconnected()),this,SLOT(disconnect_from_server()));  //连接断开
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(receive_data_from_server()));  //数据接收
    m_socket->connectToServer("comm_server");  //连接到服务器
}

void localSocket_Client::reconnect_to_server()
{
    reconnect_timer->stop();
    if(m_socket)
        m_socket->connectToServer("comm_server");
}

void localSocket_Client::connect_error()
{
    m_socket->close();
    reconnect_timer->start(1000);  //1s后重连
}

void localSocket_Client::connect_success()
{
    cout<<"localSocket connect!"<<endl;
    QByteArray send_data;
    send_data.resize(4);
    send_data[0] = 0x01;
    send_data[1] = 0x02;
    send_data[2] = 0x03;
    send_data[3] = 0x04;
    m_socket->write(send_data);
}

void localSocket_Client::disconnect_from_server()
{
   cout<<"localSocket disconnect!"<<endl;
}

void localSocket_Client::receive_data_from_server()
{
    QByteArray receive_data = m_socket->readAll();
    cout<<"local_client receive_data:"<<receive_data.data()<<endl;
}
