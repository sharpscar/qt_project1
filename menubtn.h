#ifndef MENUBTN_H
#define MENUBTN_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class MenuBtn;
}

class MenuBtn : public QWidget
{
    Q_OBJECT

public:
    explicit MenuBtn(QWidget *parent = nullptr, QString menu_name="", QString img_path="");
    ~MenuBtn();

    void mousePressEvent(QMouseEvent *e) override; //마우스 프레스에 대한 이벤트 오버라이딩
    QString getName(); //이름을 가져온다
    QString getPath(); //경로를 가져온다
    void cart();


signals:
    void clicked();


private:
    Ui::MenuBtn *ui;
};

#endif // MENUBTN_H
