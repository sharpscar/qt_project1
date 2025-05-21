#include "select_menu.h"
#include "ui_select_menu.h"

select_menu::select_menu(QWidget *parent, QString img_path, QString menu_cnt, int imgId)
    : QWidget(parent)
    , ui(new Ui::select_menu)
{
    ui->setupUi(this);

    connect(ui->pushButton_menu_plus,&QPushButton::clicked, this, &select_menu::menu_plus);
    connect(ui->pushButton_menu_minus,&QPushButton::clicked, this, &select_menu::menu_minus);
    connect(ui->pushButton_delete, &QPushButton::clicked, this, &select_menu::menu_delete);
    ui->pushButton_img->setStyleSheet(QString("border-image: url(%1);").arg(img_path));
    ui->label_menu_cnt->setText(menu_cnt);
}

void select_menu::menu_plus() {
    menu_cnt = menu_cnt_str.toInt(); //QString을 int로 변환해서 int형 변수에 담아욧
    menu_cnt++;  //수 증가
    menu_cnt_str = QString::number(menu_cnt);  //int를 QString으로 변환해서 QString형 변수에 담아욧
    ui->label_menu_cnt->setText(menu_cnt_str);  //라벨에 QString 작성해줌
    // qDebug() << "개수" << menu_cnt;

}

void select_menu::menu_minus() {
    menu_cnt = menu_cnt_str.toInt(); //QString을 int로 변환해서 int형 변수에 담아욧

    if(menu_cnt>=2){
        menu_cnt--;  //수 감소
    }
    menu_cnt_str = QString::number(menu_cnt);  //int를 QString으로 변환해서 QString형 변수에 담아욧
    ui->label_menu_cnt->setText(menu_cnt_str);  //라벨에 QString 작성해줌
    // qDebug() << "개수" << menu_cnt;
}


void select_menu::menu_delete(){
    emit send_data(this->objectName()); //객체의 이름을 보내라!
}

select_menu::~select_menu()
{
    delete ui;
}

