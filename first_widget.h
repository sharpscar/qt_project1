#ifndef FIRST_WIDGET_H
#define FIRST_WIDGET_H

#include <QWidget>

namespace Ui {
class first_widget;
}

class first_widget : public QWidget
{
    Q_OBJECT

public:
    explicit first_widget(QWidget *parent = nullptr);
    ~first_widget();

private:
    Ui::first_widget *ui;
};

#endif // FIRST_WIDGET_H
