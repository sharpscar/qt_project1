#ifndef POPUP_ORDER_METHOD_H
#define POPUP_ORDER_METHOD_H

#include <QWidget>

namespace Ui {
class popup_order_method;
}

class popup_order_method : public QWidget
{
    Q_OBJECT

public:
    explicit popup_order_method(QWidget *parent = nullptr);

    void exit();
    void changewindow_take();
    void changewindow_takeout();
    ~popup_order_method();

private:
    Ui::popup_order_method *ui;

signals:
    void popupClosed();
    void select_take();
    void select_takeout();

protected:
    void closeEvent(QCloseEvent *event) override;

};

#endif // POPUP_ORDER_METHOD_H
