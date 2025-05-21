#ifndef EXTRA_SELECT_H
#define EXTRA_SELECT_H

#include <QWidget>

namespace Ui {
class extra_select;
}

class extra_select : public QWidget
{
    Q_OBJECT

public:
    explicit extra_select(QWidget *parent = nullptr);
    ~extra_select();

private:
    Ui::extra_select *ui;
};

#endif // EXTRA_SELECT_H
