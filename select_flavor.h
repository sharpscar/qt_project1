#ifndef SELECT_FLAVOR_H
#define SELECT_FLAVOR_H

#include <QWidget>

namespace Ui {
class select_flavor;
}

class select_flavor : public QWidget
{
    Q_OBJECT

public:
    explicit select_flavor(QWidget *parent = nullptr, QString imgpath = "");

    void change_path(QString imgpath);

    ~select_flavor();

private:
    Ui::select_flavor *ui;

signals:
    void send_data_flavor(QString data); //요기 추가 0521
};

#endif // SELECT_FLAVOR_H
