#include "cart_concup.h"
#include "ui_cart_concup.h"
#include "select_menu.h"

cart_concup::cart_concup(QWidget *parent, QString imagePath)
    : QWidget(parent)
    , ui(new Ui::cart_concup)
{
    ui->setupUi(this);
    // connect(ui->btn_goback_optiontype_concup, &QPushButton::clicked, this, &menu::go_to_select_menu);




    // QString imagePath;
    ui->img_btn->setStyleSheet(QString("border-image: url(%1);").arg(imagePath));
    ui->img_btn->setFixedSize(50,50);









}

cart_concup::~cart_concup()
{
    delete ui;
}
