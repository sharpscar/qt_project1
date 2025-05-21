#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QMainWindow>
#include <iostream>
#include <QVector>
#include <stdlib.h>
#include <QTableWidgetItem>
#include <QStringList>
#include <QString>
#include <QFile>
#include <QVBoxLayout>
#include <QLabel>
#include <QEvent>
#include <QString>
#include <option.h>

#include "menubtn.h"
#include "menubtn2.h"
#include "select_menu.h"
#include "select_flavor.h"
#include "cart_concup.h"

namespace Ui {
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    QList<MenuBtn*> btns;  //아이스크림 맛 메뉴 출력용 위젯
    QList<menubtn2*> btns2; //메뉴판 출력용 위젯
    QList<select_menu*> btn_cart; //메뉴 장바구니
    QList<select_flavor*> btn_flavor_cart; //맛 장바구니
    QList <QString> add_menu_name; //중복 메뉴 검사하기 위해 생성, 메뉴이름 append

    Option opt1, opt2, opt3, opt4, opt5;
    QVector<Option> options;

    QString menuName; //메뉴명 담는 변수
    QString flavor_name; //맛 이름 담는 변수
    QString imgPath; //이미지 경로 담는 변수(쿼리에 사용)
    QString menu_cnt = "1";

    int e = 0;
    int f = 0;
    int col_ = 0;
    int col_flavor = 0;
    int total_cnt = 0;
    int menusize = 0;
    int icecream_flag = 0;
    int imgId;

    //위젯 생성 및 세팅
    void clicked_setting(); //클릭 이벤트 연결 람다
    // void flavor_get_object_name(); //맛 선택 객체 번호 부여
    void reorder_objectname(); //삭제시 객체 번호 재부여
    void reorder_flavor_objectname(); //맛 객체 삭제시 번호 재부여
    void connectdb(); //db연결
    void bringmenu(); //메뉴판 로드
    void handle_clicked(int index); //클릭 핸들링
    void handle_clicked_flavor(int index); //맛 선택 클릭 핸들링
    bool is_menu_added(const QString &menuName); //중복 메뉴 검사
    void load_image(const QString &menuName); //이미지 경로 불러서 위젯 추가
    void size_of_flavor(); //창 넘기는 즉시 위젯 추가
    void load_image_flavor(const QString &flavor_name);

    //옵션
    int check_icecream(const QString &menuName); //0520
    int con_count = 0; //초기 세팅에다 넣어둔 이유가 있는지 궁금해용
    int cup_count = 0;
    int select_flag = 0;
    void select_flavor_page(); //맛 선택 화면으로 보내기

    int bigcandle_count;
    int smallcandle_count;
    int dryice_count;
    int spoon_count_cake;
    int spoon_count_singleitem;

    //맛 선택
    int flavorId;
    QList <int> flavorIdList;

    //ui 조작
    void startsetting();
    void option_startsetting(); ////
    void concup_plus_minus();
    void gohome_signalf();
    void connectsetting();
    void option_btn_control();
    void bottom_btn_control();
    void type_menu_btn_control();
    void flavor_menu_btn_control();
    void changewindow_take();
    void changewindow_takeout();
    int toggle_select_complete();
    void go_to_select_flavor(); /////
    void go_to_select_menu();///////

    //옵션 - 아이스크림 컵 크기
    enum SIZE{
        single_ = 1,
        double_,
        pint,
        quater,
        family,
        halfgallon
    };

    ~menu();

private:
    Ui::menu *ui;
    QSqlDatabase db;

    int flavor_select_num;

signals:
    void gohome();

private slots:
    void recv_data(QString data);  //삭제 시그널 받아옴
    void recv_data_flavor(QString data); //요기 0520
    void on_btn_gofirst_clicked();
    void on_btn_select_turnoff_clicked();
    void on_btn_goback_optiontype_concup_clicked();

};

#endif // MENU_H
