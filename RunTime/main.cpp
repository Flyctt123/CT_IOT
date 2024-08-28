#include <QCoreApplication>
#include <QDebug>
#include <QLocalSocket>
#include <QLocalServer>
#include <QTimer>
#include "localSocket_Client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout<<"test"<<endl;//QProcess只能识别到cout或者printf的打印，不能用qDebug
    localSocket_Client *localSocket_client = new localSocket_Client();
    (void)localSocket_client;

    return a.exec();
}
