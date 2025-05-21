#include "second_widget.h"
#include "ui_second_widget.h"

second_widget::second_widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::second_widget)
{
    ui->setupUi(this);
}

second_widget::~second_widget()
{
    delete ui;
}
