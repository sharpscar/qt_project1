#ifndef FIRST_H
#define FIRST_H

#include <QMainWindow>
#include <QWidget>
#include "popup_happy.h"
#include "popup_order_method.h"
#include <iostream>
#include <QVector>
#include <stdlib.h>
#include <QTableWidgetItem>
#include <QStringList>
#include <QString>
#include <QFile>
#include <QVBoxLayout>
#include <QApplication>
#include <QScreen>
#include <QRect>
#include <QPoint>
#include <QEventLoop>
#include <QDebug>


namespace Ui {
class first_window;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
}

class first : public QWidget
{
    Q_OBJECT

public:
    explicit first(QWidget *parent = nullptr);
    void clicked_happy_order();
    void clicked_take_order();
    ~first();

    popup_happy *popup_h;
    popup_order_method *popup_o;

private:
    Ui::first_window *ui;

signals:
    void main_select_take();
    void main_select_takeout();
};

#endif // FIRST_H
