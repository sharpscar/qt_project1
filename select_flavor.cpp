#include "select_flavor.h"
#include "ui_select_flavor.h"

select_flavor::select_flavor(QWidget *parent, QString flavorname)
    : QWidget(parent)
    , ui(new Ui::select_flavor)
{
    ui->setupUi(this);


}

select_flavor::~select_flavor()
{
    delete ui;
}
