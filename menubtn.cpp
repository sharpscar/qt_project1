#include "menubtn.h"
#include "ui_menubtn.h"

MenuBtn::MenuBtn(QWidget *parent, QString menu_name, QString img_path) //count 숫자를 받아서 한번에 정의하자
    : QWidget(parent)
    , ui(new Ui::MenuBtn)
{
    ui->setupUi(this);
    ui->label_text->setText(menu_name);
    ui->label_img->setStyleSheet(QString("border-image: url(%1);").arg(img_path));
}

void MenuBtn::mousePressEvent(QMouseEvent *e){  //위젯 클릭시 발생하는 이벤트
    if(e->button() == Qt::LeftButton){  //마우스 이벤트가 왼쪽버튼이면
        emit clicked();    //클릭 발생
    }
    QWidget::mousePressEvent(e);  //위젯에 클릭 연결함.
}

QString MenuBtn::getName(){
    return ui->label_text->text();
}

void MenuBtn::cart(){

}

MenuBtn::~MenuBtn()
{
    delete ui;
}
