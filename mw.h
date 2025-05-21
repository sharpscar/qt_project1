#ifndef MW_H
#define MW_H

#include <QMainWindow>
#include <first.h>
#include <menu.h>
#include <popup_happy.h>
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
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MW;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
}
QT_END_NAMESPACE

class MW : public QMainWindow
{
    Q_OBJECT

public:
    MW(QWidget *parent = nullptr);
    void connectsetting();
    void load_ui();
    void changewindow_take();
    ~MW();

private:
    Ui::MW *ui;

};
#endif // MW_H
