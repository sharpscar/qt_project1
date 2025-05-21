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
    explicit select_flavor(QWidget *parent = nullptr, QString flavorname = "");
    ~select_flavor();

private:
    Ui::select_flavor *ui;
};

#endif // SELECT_FLAVOR_H
