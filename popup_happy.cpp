#include "popup_happy.h"
#include "ui_popup_happy.h"
#include <QDebug>

popup_happy::popup_happy(QWidget *parent)
    : QWidget(parent, Qt::Tool | Qt::FramelessWindowHint) //테두리없는 팝업
    , ui(new Ui::popup_happy)
{
    ui->setupUi(this);
    this->startsetting();
    ui->phone_number_output->setText("010");  // 초기 텍스트 설정

    QString user_phone_num;
    this->make_untouchable();
    this->popup_happy_window_change();
    this->insert_num();
    this->backspace_num();
    this->delete_num();
    connect(ui->exit_btn, &QPushButton::clicked, this, &popup_happy::exit);
    connect(ui->exit_btn_2, &QPushButton::clicked, this, &popup_happy::exit);
}

void popup_happy::startsetting()
{
    ui->stackedWidget_happy->setCurrentWidget(ui->page_happy_selected);
    ui->stackedWidget_happyuse->setCurrentWidget(ui->page_happyuse_non);
    ui->stackedWidget_main->setCurrentWidget(ui->page_cellphone);
}

void popup_happy::insert_num()
{
    QPushButton* num_arr[10];
    for (int i = 0; i < 10; i++)
    {
        QString objName = QString("num_%1").arg(i);    //"num_%1" 은 형식 문자열, %1은 자리표시자 .arg(i)를 쓰면 %1에 i가 들어간다.
        num_arr[i] = findChild<QPushButton*>(objName); // Qt는 위젯 계층 구조(Tree)로 되어 있다.
                                                       //this (보통 현재 윈도우 위젯) 의 자식 중에서 "num_0"
                                                       //이름을 가진 QPushButton 포인터를 찾아줘 라는 뜻이다.
        if (num_arr[i] != nullptr)
        {
            connect(num_arr[i], &QPushButton::clicked, this, [this, i]() {
                if (user_phone_num.size() < 10)
                {
                    if(user_phone_num.size()==0)
                    {
                        ui->phone_number_output->insert("-");
                        user_phone_num.append("-");
                    }
                    else if(user_phone_num.size()==5)
                    {
                        ui->phone_number_output->insert("-");
                        user_phone_num.append("-");
                    }
                    ui->phone_number_output->insert(QString::number(i));
                    user_phone_num.append(QString::number(i));
                }
                if (user_phone_num.size()==10)
                {
                    ui->stackedWidget_login->setCurrentWidget(ui->page_turnon);
                }
                else
                    ui->stackedWidget_login->setCurrentWidget(ui->page_turnoff);
            });
        }
    }
}

void popup_happy::backspace_num()
{
    connect(ui->num_backspace, &QPushButton::clicked, this, [this]() {
        if (user_phone_num.size()>0)
        {
            if(user_phone_num.size()==2||user_phone_num.size()==7)
            {
                ui->phone_number_output->backspace();
                user_phone_num.erase(user_phone_num.begin()+user_phone_num.size()-1);
                ui->phone_number_output->backspace();
                user_phone_num.erase(user_phone_num.begin()+user_phone_num.size()-1);
            }
            else
            {
                ui->phone_number_output->backspace();
                user_phone_num.erase(user_phone_num.begin()+user_phone_num.size()-1);
            }
            if (user_phone_num.size()!=10)
            {
                ui->stackedWidget_login->setCurrentWidget(ui->page_turnoff);
            }
        }
    });
}

void popup_happy::delete_num()
{
    connect(ui->num_delete, &QPushButton::clicked, this, [this](){
        ui->phone_number_output->clear();
        user_phone_num.clear();
        ui->phone_number_output->setText("010");
        ui->stackedWidget_login->setCurrentWidget(ui->page_turnoff);
    });
}

void popup_happy::closeEvent(QCloseEvent *event)
{
    emit popupClosed();  // 팝업이 닫힐 때 시그널 발생
    QWidget::closeEvent(event);
}

void popup_happy::exit()
{
    close();
}

void popup_happy::popup_happy_window_change()
{
    connect(ui->happyuse_nonselected_btn, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_happyuse->setCurrentWidget(ui->page_happyuse_sel);
        ui->stackedWidget_happy->setCurrentWidget(ui->page_happy_nonselected);
        ui->stackedWidget_main->setCurrentWidget(ui->page_barcode);
    });
    connect(ui->happy_nonselected_btn, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_happyuse->setCurrentWidget(ui->page_happyuse_non);
        ui->stackedWidget_happy->setCurrentWidget(ui->page_happy_selected);
        ui->stackedWidget_main->setCurrentWidget(ui->page_cellphone);
    });
    //추후 DB랑 확인하여 핸드폰 번호 일치하는지 조건 넣어야함
    connect(ui->login_turnon, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_main->setCurrentWidget(ui->page_logined);
    });
    connect(ui->login_ok, &QPushButton::clicked, this, &popup_happy::exit);
}

void popup_happy::make_untouchable()
{
    ui->textEdit->setReadOnly(true);  // 입력 막기
    ui->textEdit->setTextInteractionFlags(Qt::NoTextInteraction);  // 선택도 불가
    ui->textEdit->setFocusPolicy(Qt::NoFocus);  // 포커스도 안 받기

    ui->textEdit_2->setReadOnly(true);  // 입력 막기
    ui->textEdit_2->setTextInteractionFlags(Qt::NoTextInteraction);  // 선택도 불가
    ui->textEdit_2->setFocusPolicy(Qt::NoFocus);  // 포커스도 안 받기

    ui->textEdit_3->setReadOnly(true);  // 입력 막기
    ui->textEdit_3->setTextInteractionFlags(Qt::NoTextInteraction);  // 선택도 불가
    ui->textEdit_3->setFocusPolicy(Qt::NoFocus);  // 포커스도 안 받기
}

popup_happy::~popup_happy()
{
    delete ui;
}
