#ifndef SECOND_WIDGET_H
#define SECOND_WIDGET_H

#include <QWidget>

namespace Ui {
class second_widget;
}

class second_widget : public QWidget
{
    Q_OBJECT

public:
    explicit second_widget(QWidget *parent = nullptr);
    ~second_widget();

private:
    Ui::second_widget *ui;
};

#endif // SECOND_WIDGET_H
