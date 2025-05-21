#include "extra_select.h"
#include "ui_extra_select.h"

extra_select::extra_select(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::extra_select)
{
    ui->setupUi(this);
}

extra_select::~extra_select()
{
    delete ui;
}
