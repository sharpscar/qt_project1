#include "first_widget.h"
#include "ui_first_widget.h"

first_widget::first_widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::first_widget)
{
    ui->setupUi(this);
}

first_widget::~first_widget()
{
    delete ui;
}
