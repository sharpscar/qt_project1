#include "mw.h"
#include "ui_mw.h"


MW::MW(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MW)
{
    ui->setupUi(this);
    this->load_ui();


}

void MW::connectsetting()
{

}

void MW::load_ui()
{
    //레이아웃 생성
    QVBoxLayout *layout_first = new QVBoxLayout();
    layout_first->setContentsMargins(0, 0, 0, 0); // 패딩 없애기
    layout_first->setSpacing(0); // 위젯 간 여백 없애기
    //first ui 생성
    first *show_first = new first(this);
    show_first->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 레이아웃에  추가
    layout_first->addWidget(show_first);
    //스택트 page_first에 레이아웃 추가
    ui->page_first->setLayout(layout_first);



    //레이아웃 생성
    QVBoxLayout *layout_menu = new QVBoxLayout();
    layout_menu->setContentsMargins(0, 0, 0, 0); // 패딩 없애기
    layout_menu->setSpacing(0); // 위젯 간 여백 없애기
    //first ui 생성
    menu *show_menu = new menu(this);
    show_menu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 레이아웃에  추가
    layout_menu->addWidget(show_menu);
    //스택트 page_first에 레이아웃 추가
    ui->page_menu->setLayout(layout_menu);


    //첫 화면 표시
    ui->stackedWidget->setCurrentWidget(ui->page_first);

    connect(show_first,&first::main_select_take, this, [this, show_menu](){
        ui->stackedWidget->setCurrentWidget(ui->page_menu);
        show_menu->changewindow_take();
    });
    connect(show_first,&first::main_select_takeout, this, [this, show_menu](){
        ui->stackedWidget->setCurrentWidget(ui->page_menu);
        show_menu->changewindow_takeout();
    });

    connect(show_menu, &menu::gohome, this, [this](){
        ui->stackedWidget->setCurrentWidget(ui->page_first);
    });

}

void MW::changewindow_take()
{

}

MW::~MW()
{
    delete ui;
}
