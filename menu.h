#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QMainWindow>
#include <iostream>
#include <QVector>
#include <stdlib.h>
#include <QTableWidgetItem>
#include <QStringList>
#include <QString>
#include <QFile>
#include <QVBoxLayout>
#include <QLabel>
#include <QEvent>
#include <QString>
#include <option.h>

#include "menubtn.h"
#include "menubtn2.h"

namespace Ui {
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    QList<MenuBtn*> btns;  //맛 메뉴 위젯
    QList<menubtn2*> btns2; //메뉴판 위젯
    QString flavorName;
    QVector<Option> options;
    Option opt1,opt2, opt3, opt4, opt5;

    int con_count;
    int cup_count;
    int bigcandle_count;
    int smallcandle_count;
    int dryice_count;
    int spoon_count_cake;
    int spoon_count_singleitem;
    int pojang_status;      // 0, 1, 2
    int beveragecup_status; // 0, 1
    int extrashot_status;   // 0, 1
    int coffeecup_status;   // 0, 1



    void startsetting();
    void option_startsetting();
    void connectdb();
    void bringmenu();
    void concup_plus_minus();
    void gohome_signalf();
    void connectsetting();
    void option_btn_control();
    void bottom_btn_control();
    void type_menu_btn_control();
    void flavor_menu_btn_control();
    void changewindow_take();
    void changewindow_takeout();
    ~menu();

private:
    Ui::menu *ui;
    QSqlDatabase db;

signals:
    void gohome();
};

#endif // MENU_H
