#include "first.h"
#include "ui_first.h"

first::first(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::first_window)
{
    ui->setupUi(this);
    this->clicked_happy_order();
    this->clicked_take_order();
}

void first::clicked_happy_order()
{
    connect(ui->happy_order, &QPushButton::clicked, this, [this]() {
        //  first 위에 덮을 반투명 오버레이 생성 (부모는 this == first)
        //  overlay 생성 (first 기준)
        QWidget *overlay = new QWidget(this);
        overlay->setGeometry(this->rect());
        overlay->setStyleSheet("background-color: rgba(0, 0, 0, 128);");
        overlay->setAttribute(Qt::WA_TransparentForMouseEvents, false);
        overlay->show();

        //  popup_happy 생성
        popup_happy *popup_h = new popup_happy(this);
        popup_h->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        popup_h->setAttribute(Qt::WA_ShowWithoutActivating, false);

        //  중앙 위치 잡기
        QPoint globalPos = this->mapToGlobal(QPoint(0, 0));
        QRect firstGlobalRect(globalPos, this->size());
        QPoint popupPos = firstGlobalRect.center() - QPoint(popup_h->width() / 2, popup_h->height() / 2);
        popup_h->move(popupPos);

        //  popup 닫힐 때 오버레이 제거
        connect(popup_h, &popup_happy::popupClosed, this, [overlay]() {
            overlay->deleteLater();  // 팝업 닫히면 오버레이도 제거
        });

        popup_h->show();
    });
}

void first::clicked_take_order()
{
    connect(ui->take_order, &QPushButton::clicked, this, [this]() {
        //  first 위에 덮을 반투명 오버레이 생성 (부모는 this == first)
        //  overlay 생성 (first 기준)
        QWidget *overlay = new QWidget(this);
        overlay->setGeometry(this->rect());
        overlay->setStyleSheet("background-color: rgba(0, 0, 0, 128);");
        overlay->setAttribute(Qt::WA_TransparentForMouseEvents, false);
        overlay->show();

        //
        popup_order_method *popup_o = new popup_order_method(this);
        popup_o->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        popup_o->setAttribute(Qt::WA_ShowWithoutActivating, false);

        //  중앙 위치 잡기
        QPoint globalPos = this->mapToGlobal(QPoint(0, 0));
        QRect firstGlobalRect(globalPos, this->size());
        QPoint popupPos = firstGlobalRect.center() - QPoint(popup_o->width() / 2, popup_o->height() / 2);
        popup_o->move(popupPos);

        //  popup 닫힐 때 오버레이 제거
        connect(popup_o, &popup_order_method::popupClosed, this, [overlay]() {
            overlay->deleteLater();  // 팝업 닫히면 오버레이도 제거
        });

        popup_o->show();

        connect(popup_o, &popup_order_method::select_take, this, &first::main_select_take);
        connect(popup_o, &popup_order_method::select_takeout, this, &first::main_select_takeout);
    });
}


first::~first()
{
    delete ui;
}
