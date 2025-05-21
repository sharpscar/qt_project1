#ifndef CART_CONCUP_H
#define CART_CONCUP_H

#include <QWidget>

namespace Ui {
class cart_concup;
}

class cart_concup : public QWidget
{
    Q_OBJECT

public:

    explicit cart_concup(QWidget *parent = nullptr, QString imagePath="");
    ~cart_concup();

private:
    Ui::cart_concup *ui;
};

#endif // CART_CONCUP_H
