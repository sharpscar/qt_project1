#include "select_flavor.h"
#include "ui_select_flavor.h"

select_flavor::select_flavor(QWidget *parent, QString imgpath) //0521수정, 헤더도 이름 빠짐
    : QWidget(parent)
    , ui(new Ui::select_flavor)
{
    ui->setupUi(this);
    ui->pushButton_img->setStyleSheet(QString("border-image: url(%1);").arg(imgpath));
}

void select_flavor::change_path(QString imgpath){
    ui->pushButton_img->setStyleSheet(QString("border-image: url(%1);").arg(imgpath));
}

select_flavor::~select_flavor()
{
    delete ui;
}
