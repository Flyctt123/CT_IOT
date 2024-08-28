#ifndef DATA_QUERY_H
#define DATA_QUERY_H

#include <QWidget>

namespace Ui {
class data_query;
}

class data_query : public QWidget
{
    Q_OBJECT

public:
    explicit data_query(QWidget *parent = nullptr);
    ~data_query();
    Ui::data_query *ui;
private:

};

#endif // DATA_QUERY_H
