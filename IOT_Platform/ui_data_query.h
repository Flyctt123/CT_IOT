/********************************************************************************
** Form generated from reading UI file 'data_query.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_QUERY_H
#define UI_DATA_QUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_data_query
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QWidget *tab_2;

    void setupUi(QWidget *data_query)
    {
        if (data_query->objectName().isEmpty())
            data_query->setObjectName(QString::fromUtf8("data_query"));
        data_query->resize(800, 480);
        gridLayout = new QGridLayout(data_query);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(data_query);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(data_query);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(data_query);
    } // setupUi

    void retranslateUi(QWidget *data_query)
    {
        data_query->setWindowTitle(QApplication::translate("data_query", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("data_query", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("data_query", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class data_query: public Ui_data_query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_QUERY_H
