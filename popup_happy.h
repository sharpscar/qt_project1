#ifndef POPUP_HAPPY_H
#define POPUP_HAPPY_H

#include <QWidget>
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

namespace Ui {
class popup_happy;
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
}

class popup_happy : public QWidget
{
    Q_OBJECT

public:
    explicit popup_happy(QWidget *parent = nullptr);
    QString user_phone_num;
    void startsetting();
    void insert_num();
    void backspace_num();
    void delete_num();
    void exit();
    void popup_happy_window_change();
    void make_untouchable();

    ~popup_happy();

private:
    Ui::popup_happy *ui;

signals:
    void popupClosed();

protected:
    void closeEvent(QCloseEvent *event) override;

};


#endif // POPUP_HAPPY_H
