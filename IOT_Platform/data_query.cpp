#include "data_query.h"
#include "ui_data_query.h"

data_query::data_query(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::data_query)
{
    ui->setupUi(this);
}

data_query::~data_query()
{
    delete ui;
}
