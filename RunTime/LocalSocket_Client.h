#ifndef LOCALSOCKET_CLIENT_H
#define LOCALSOCKET_CLIENT_H

#include <QObject>
#include <QTimer>
#include <QLocalSocket>
#include <QLocalServer>
#include <iostream>
using namespace std;

class localSocket_Client : public QObject
{
    Q_OBJECT
public:
    explicit localSocket_Client(QObject *parent = nullptr);

private slots:
    void reconnect_to_server();
    void connect_error();
    void connect_success();
    void disconnect_from_server();
    void receive_data_from_server();

private:
    QLocalSocket *m_socket;
    QTimer *reconnect_timer;
signals:

};

#endif // LOCALSOCKET_CLIENT_H
