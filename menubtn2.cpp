#include "menubtn2.h"
#include "ui_menubtn2.h"

menubtn2::menubtn2(QWidget *parent, QString menu_name, QString img_path, QString price)
    : QWidget(parent)
    , ui(new Ui::MenuBtn2)
{
    ui->setupUi(this);
    ui->label_text2->setText(menu_name);
    ui->label_img2->setStyleSheet(QString("border-image: url(%1);").arg(img_path));
    ui->label_price2->setText(price);

}

void menubtn2::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        emit clicked();
    }
    QWidget::mousePressEvent(e);
}

QString menubtn2::get_menu_name(){
    return ui->label_text2->text();
}


menubtn2::~menubtn2()
{
    delete ui;
}
