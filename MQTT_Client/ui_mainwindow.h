/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QLabel *textBrowser;
    QLineEdit *lineEditport;
    QLabel *label_5;
    QLineEdit *lineEdit_name;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_password;
    QPushButton *buttonConnect;
    QLabel *label;
    QLineEdit *lineEditHost;
    QLabel *label_2;
    QLineEdit *lineEditTopic;
    QLabel *label_3;
    QPushButton *buttonPublish;
    QPushButton *buttonSubscribe;
    QLabel *label_4;
    QLineEdit *lineEditMessage;
    QPlainTextEdit *receive_msg;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 272);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textBrowser = new QLabel(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(60, 105, 111, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(8);
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QString::fromUtf8("color: rgb(97, 120, 202);"));
        lineEditport = new QLineEdit(centralWidget);
        lineEditport->setObjectName(QString::fromUtf8("lineEditport"));
        lineEditport->setGeometry(QRect(50, 30, 341, 21));
        lineEditport->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 105, 40, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(97, 120, 202);"));
        lineEdit_name = new QLineEdit(centralWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(50, 54, 341, 21));
        lineEdit_name->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(13, 56, 40, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(13, 80, 40, 16));
        label_7->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        lineEdit_password = new QLineEdit(centralWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(50, 80, 341, 21));
        lineEdit_password->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        buttonConnect = new QPushButton(centralWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));
        buttonConnect->setGeometry(QRect(400, 10, 71, 81));
        buttonConnect->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(13, 10, 40, 16));
        label->setFont(font);
        lineEditHost = new QLineEdit(centralWidget);
        lineEditHost->setObjectName(QString::fromUtf8("lineEditHost"));
        lineEditHost->setGeometry(QRect(50, 6, 341, 21));
        lineEditHost->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(13, 31, 40, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        lineEditTopic = new QLineEdit(centralWidget);
        lineEditTopic->setObjectName(QString::fromUtf8("lineEditTopic"));
        lineEditTopic->setGeometry(QRect(83, 135, 311, 21));
        lineEditTopic->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(12, 136, 48, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        buttonPublish = new QPushButton(centralWidget);
        buttonPublish->setObjectName(QString::fromUtf8("buttonPublish"));
        buttonPublish->setGeometry(QRect(400, 160, 71, 28));
        buttonPublish->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        buttonSubscribe = new QPushButton(centralWidget);
        buttonSubscribe->setObjectName(QString::fromUtf8("buttonSubscribe"));
        buttonSubscribe->setGeometry(QRect(400, 130, 71, 28));
        buttonSubscribe->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(12, 160, 64, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        lineEditMessage = new QLineEdit(centralWidget);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));
        lineEditMessage->setGeometry(QRect(83, 160, 311, 21));
        lineEditMessage->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        receive_msg = new QPlainTextEdit(centralWidget);
        receive_msg->setObjectName(QString::fromUtf8("receive_msg"));
        receive_msg->setGeometry(QRect(10, 190, 461, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        receive_msg->setFont(font1);
        receive_msg->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\256\213\344\275\223\";"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        textBrowser->setText(QString());
        lineEditport->setText(QApplication::translate("MainWindow", "1883", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\217\220\347\244\272:", nullptr));
        lineEdit_name->setText(QApplication::translate("MainWindow", "device0&a1uEFOvKWyp", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201:", nullptr));
        lineEdit_password->setText(QApplication::translate("MainWindow", "d966bd0269b388f4fd161fa625d8f8fea934f0ebe7a9855b889611ff86826cbc", nullptr));
        buttonConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label->setText(QApplication::translate("MainWindow", "IP:", nullptr));
        lineEditHost->setText(QApplication::translate("MainWindow", "a1uEFOvKWyp.iot-as-mqtt.cn-shanghai.aliyuncs.com", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Port:", nullptr));
        lineEditTopic->setText(QApplication::translate("MainWindow", "/sys/a1uEFOvKWyp/device0/thing/event/property/post", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Topic:", nullptr));
        buttonPublish->setText(QApplication::translate("MainWindow", "\345\217\221\345\270\203", nullptr));
        buttonSubscribe->setText(QApplication::translate("MainWindow", "\350\256\242\351\230\205", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Message:", nullptr));
        lineEditMessage->setText(QApplication::translate("MainWindow", "This is a test message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
