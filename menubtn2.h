#ifndef MENUBTN2_H
#define MENUBTN2_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class MenuBtn2;
}

class menubtn2 : public QWidget
{
    Q_OBJECT

public:
    explicit menubtn2(QWidget *parent = nullptr, QString menu_name="", QString img_path="", QString price="");
    ~menubtn2();


public:
    void mousePressEvent(QMouseEvent *e) override;
    QString getName();
    QString getPath(); //경로를 가져온다


signals:
    void clicked();

private:
    Ui::MenuBtn2 *ui;
};

#endif // MENUBTN2_H
