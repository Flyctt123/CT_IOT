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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QToolButton *device_monitor;
    QToolButton *net_info;
    QToolButton *parameter_set;
    QToolButton *system_set;
    QToolButton *restart;
    QGridLayout *gridLayout_2;
    QToolButton *Window_min;
    QLabel *label_sysTime;
    QToolButton *Window_close;
    QVBoxLayout *verticalLayout_2;
    QToolButton *configuration;
    QToolButton *video_monitor;
    QToolButton *data_query;
    QLabel *label_4;
    QStackedWidget *stackedWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 244, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(100, 100));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/iot_platform.png);"));

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 10, -1, 10);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"color: rgb(16, 90, 154);"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Times New Roman\";\n"
"color: rgb(16, 90, 154);"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        device_monitor = new QToolButton(centralwidget);
        device_monitor->setObjectName(QString::fromUtf8("device_monitor"));
        device_monitor->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"font: bold;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/device_monitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        device_monitor->setIcon(icon);
        device_monitor->setIconSize(QSize(40, 40));
        device_monitor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        device_monitor->setAutoRaise(true);

        horizontalLayout->addWidget(device_monitor);

        net_info = new QToolButton(centralwidget);
        net_info->setObjectName(QString::fromUtf8("net_info"));
        net_info->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"font: bold;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/net_info.png"), QSize(), QIcon::Normal, QIcon::Off);
        net_info->setIcon(icon1);
        net_info->setIconSize(QSize(40, 40));
        net_info->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        net_info->setAutoRaise(true);

        horizontalLayout->addWidget(net_info);

        parameter_set = new QToolButton(centralwidget);
        parameter_set->setObjectName(QString::fromUtf8("parameter_set"));
        parameter_set->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"font: bold"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/parameter_set.png"), QSize(), QIcon::Normal, QIcon::Off);
        parameter_set->setIcon(icon2);
        parameter_set->setIconSize(QSize(40, 40));
        parameter_set->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        parameter_set->setAutoRaise(true);

        horizontalLayout->addWidget(parameter_set);

        system_set = new QToolButton(centralwidget);
        system_set->setObjectName(QString::fromUtf8("system_set"));
        system_set->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"font: bold"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/system_set.png"), QSize(), QIcon::Normal, QIcon::Off);
        system_set->setIcon(icon3);
        system_set->setIconSize(QSize(40, 40));
        system_set->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        system_set->setAutoRaise(true);

        horizontalLayout->addWidget(system_set);

        restart = new QToolButton(centralwidget);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"font: bold"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        restart->setIcon(icon4);
        restart->setIconSize(QSize(40, 40));
        restart->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        restart->setAutoRaise(true);

        horizontalLayout->addWidget(restart);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 1);

        horizontalLayout_2->addLayout(horizontalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Window_min = new QToolButton(centralwidget);
        Window_min->setObjectName(QString::fromUtf8("Window_min"));
        Window_min->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/window_min.png"), QSize(), QIcon::Normal, QIcon::Off);
        Window_min->setIcon(icon5);
        Window_min->setIconSize(QSize(25, 25));
        Window_min->setAutoRaise(true);

        gridLayout_2->addWidget(Window_min, 0, 0, 1, 1);

        label_sysTime = new QLabel(centralwidget);
        label_sysTime->setObjectName(QString::fromUtf8("label_sysTime"));
        label_sysTime->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"/*border:2px solid rgb(16, 90, 154);*/\n"
"font: bold\n"
""));

        gridLayout_2->addWidget(label_sysTime, 1, 0, 1, 2);

        Window_close = new QToolButton(centralwidget);
        Window_close->setObjectName(QString::fromUtf8("Window_close"));
        Window_close->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/window_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        Window_close->setIcon(icon6);
        Window_close->setIconSize(QSize(25, 25));
        Window_close->setAutoRaise(true);

        gridLayout_2->addWidget(Window_close, 0, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 10, -1, -1);
        configuration = new QToolButton(centralwidget);
        configuration->setObjectName(QString::fromUtf8("configuration"));
        configuration->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"font: bold;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/configuration.png"), QSize(), QIcon::Normal, QIcon::Off);
        configuration->setIcon(icon7);
        configuration->setIconSize(QSize(40, 40));
        configuration->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        configuration->setAutoRaise(true);

        verticalLayout_2->addWidget(configuration);

        video_monitor = new QToolButton(centralwidget);
        video_monitor->setObjectName(QString::fromUtf8("video_monitor"));
        video_monitor->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"font: bold;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/video_monitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        video_monitor->setIcon(icon8);
        video_monitor->setIconSize(QSize(40, 40));
        video_monitor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        video_monitor->setAutoRaise(true);

        verticalLayout_2->addWidget(video_monitor);

        data_query = new QToolButton(centralwidget);
        data_query->setObjectName(QString::fromUtf8("data_query"));
        data_query->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(16, 90, 154);\n"
"font: bold"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/data_query.png"), QSize(), QIcon::Normal, QIcon::Off);
        data_query->setIcon(icon9);
        data_query->setIconSize(QSize(40, 40));
        data_query->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        data_query->setAutoRaise(true);

        verticalLayout_2->addWidget(data_query);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        verticalLayout_2->setStretch(3, 3);

        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(16, 90, 154);"));

        gridLayout->addWidget(stackedWidget, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\347\211\251\350\201\224\347\275\221\347\273\274\345\220\210\347\256\241\347\220\206\345\271\263\345\217\260", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "IOT Integrated Management Platform", nullptr));
        device_monitor->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\233\221\346\265\213", nullptr));
        net_info->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\344\277\241\346\201\257", nullptr));
        parameter_set->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        system_set->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        restart->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\351\207\215\345\220\257", nullptr));
        Window_min->setText(QString());
        label_sysTime->setText(QString());
        Window_close->setText(QString());
        configuration->setText(QApplication::translate("MainWindow", "\351\200\232\344\277\241\347\273\204\346\200\201", nullptr));
        video_monitor->setText(QApplication::translate("MainWindow", "\350\247\206\351\242\221\347\233\221\346\216\247", nullptr));
        data_query->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\237\245\350\257\242", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
