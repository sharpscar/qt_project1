#include "popup_order_method.h"
#include "ui_popup_order_method.h"

popup_order_method::popup_order_method(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::popup_order_method)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);  // 입력 막기
    ui->textEdit->setTextInteractionFlags(Qt::NoTextInteraction);  // 선택도 불가
    ui->textEdit->setFocusPolicy(Qt::NoFocus);  // 포커스도 안 받기

    connect(ui->exit_btn, &QPushButton::clicked, this, &popup_order_method::exit);
    connect(ui->take_btn, &QPushButton::clicked, this, &popup_order_method::changewindow_take);
    connect(ui->takeout_btn, &QPushButton::clicked, this, &popup_order_method::changewindow_takeout);
}

void popup_order_method::closeEvent(QCloseEvent *event)
{
    emit popupClosed();  // 팝업이 닫힐 때 시그널 발생
    QWidget::closeEvent(event);
}

void popup_order_method::exit()
{
    close();
}

void popup_order_method::changewindow_take()
{
    emit select_take();
    close();
}

void popup_order_method::changewindow_takeout()
{
    emit select_takeout();
    close();
}

popup_order_method::~popup_order_method()
{
    delete ui;
}
