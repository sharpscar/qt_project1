#ifndef SELECT_MENU_H
#define SELECT_MENU_H

#include <QWidget>
#include <QString>
#include <option.h>

// typedef struct Options {
//     QString optino_name;
//     QString category;
//     int quentity;
//     int price;
// } Ops;


namespace Ui {
class select_menu;
}

class select_menu : public QWidget
{
    Q_OBJECT

//요기 수정 0519
public:
    explicit select_menu(QWidget *parent = nullptr, QString img_path = "", QString menu_cnt ="", int imgId = 0);
    ~select_menu();

    QVector<Option> options;

    QString menu_cnt_str = "1";
    int imgId;
    int menu_cnt;
    void menu_plus();
    void menu_minus();
    void menu_delete();

private:
    Ui::select_menu *ui;

signals:
    void send_data(QString data);

};

#endif // SELECT_MENU_H
