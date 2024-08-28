/********************************************************************************
** Form generated from reading UI file 'device_monitor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_MONITOR_H
#define UI_DEVICE_MONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_device_monitor
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_5;
    QLabel *label;
    QGroupBox *groupBox_3;
    QLabel *label_title;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_10;
    QGroupBox *groupBox_9;

    void setupUi(QWidget *device_monitor)
    {
        if (device_monitor->objectName().isEmpty())
            device_monitor->setObjectName(QString::fromUtf8("device_monitor"));
        device_monitor->resize(800, 480);
        device_monitor->setStyleSheet(QString::fromUtf8("background-color: rgb(93, 196, 216);"));
        gridLayout = new QGridLayout(device_monitor);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_5 = new QGroupBox(device_monitor);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox{margin-top:0px;}\n"
"QGroupBox:title{margin-top: 0px;}"));
        groupBox_5->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(groupBox_5, 1, 0, 1, 1);

        label = new QLabel(device_monitor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/00001.png);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(device_monitor);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox{margin-top:0px;}\n"
"QGroupBox::title{\n"
"margin-top: 0px;\n"
"font-size: 10px;\n"
"font-weight: bold;\n"
"color: rgb(16, 90, 154);\n"
"}"));
        groupBox_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(groupBox_3, 1, 2, 1, 1);

        label_title = new QLabel(device_monitor);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setStyleSheet(QString::fromUtf8("border-image: url(:/icon/101341FA(2).png);"));
        label_title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_title, 0, 1, 1, 1);

        groupBox_8 = new QGroupBox(device_monitor);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setStyleSheet(QString::fromUtf8("QGroupBox{margin-top:0px;}\n"
"QGroupBox::title{\n"
"font-size: 10px;\n"
"font-weight: bold;\n"
"color: rgb(16, 90, 154);\n"
"}"));
        groupBox_8->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox_8);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 2, -1, -1);
        label_3 = new QLabel(groupBox_8);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 87 10pt \"Arial Black\";"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 87 10pt \"Arial Black\";"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(groupBox_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 87 10pt \"Arial Black\";"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_8, 0, 2, 1, 1);

        groupBox_10 = new QGroupBox(device_monitor);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setStyleSheet(QString::fromUtf8("QGroupBox{margin-top:0px;}\n"
"QGroupBox::title{\n"
"margin-top: 0px;\n"
"font-size: 10px;\n"
"font-weight: bold;\n"
"color: rgb(16, 90, 154);\n"
"}"));
        groupBox_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(groupBox_10, 0, 0, 1, 1);

        groupBox_9 = new QGroupBox(device_monitor);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setStyleSheet(QString::fromUtf8("QGroupBox{margin-top:0px;}\n"
"QGroupBox::title{\n"
"margin-top: 0px;\n"
"font-size: 10px;\n"
"font-weight: bold;\n"
"color: rgb(16, 90, 154);\n"
"}"));
        groupBox_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(groupBox_9, 2, 0, 1, 3);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 4);
        gridLayout->setRowStretch(2, 2);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);
        groupBox_5->raise();
        groupBox_8->raise();
        label->raise();
        label_title->raise();
        groupBox_3->raise();
        groupBox_9->raise();
        groupBox_10->raise();

        retranslateUi(device_monitor);

        QMetaObject::connectSlotsByName(device_monitor);
    } // setupUi

    void retranslateUi(QWidget *device_monitor)
    {
        device_monitor->setWindowTitle(QApplication::translate("device_monitor", "Form", nullptr));
        groupBox_5->setTitle(QString());
        label->setText(QString());
        groupBox_3->setTitle(QString());
        label_title->setText(QString());
        groupBox_8->setTitle(QApplication::translate("device_monitor", "\347\263\273\347\273\237\350\265\204\346\272\220\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("device_monitor", "TextLabel", nullptr));
        label_4->setText(QApplication::translate("device_monitor", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("device_monitor", "TextLabel", nullptr));
        groupBox_10->setTitle(QString());
        groupBox_9->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class device_monitor: public Ui_device_monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_MONITOR_H
