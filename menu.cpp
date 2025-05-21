#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    this->connectsetting();
    this->connectdb();
    this->bringmenu();
    this->startsetting();
    this->option_btn_control();
    this->option_startsetting();
    this->type_menu_btn_control();
    this->flavor_menu_btn_control();
    this->concup_plus_minus();
    this->flavor_select_num = 0; //요기 !
    this->clicked_setting();
    ui->stackedWidget_select_btn->setCurrentWidget(ui->btn_select_turnoff);
    ui->stackedWidget_con_btn->setCurrentWidget(ui->page_conquantity_turnoff_btn);
    ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnoff_btn);

    connect(ui->btn_select_turnon_optiontype_concup, &QPushButton::clicked, this, &menu::go_to_select_flavor);
    connect(ui->btn_goback_optiontype_concup, &QPushButton::clicked, this, &menu::go_to_select_menu);

}

void menu::startsetting()
{
    ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu);
    ui->stackedWidget_leftmenu->setCurrentWidget(ui->page_typemenu);
    ui->stackedWidget_arraytype->setCurrentWidget(ui->page_array_icecreamcake);
    ui->stackedWidget_turn->setCurrentWidget(ui->page_turn_menu);
    ui->stackedWidget_icecreamcake_btn->setCurrentWidget(ui->page_icecreamcake_turnon);
    ui->stackedWidget_icecream_btn->setCurrentWidget(ui->page_icecream_turnoff);
    ui->stackedWidget_readypack_btn->setCurrentWidget(ui->page_readypack_turnoff);
    ui->stackedWidget_coffee_btn->setCurrentWidget(ui->page_coffee_turnoff);
    ui->stackedWidget_beverage_btn->setCurrentWidget(ui->page_beverage_turnoff);
    ui->stackedWidget_dessert_btn->setCurrentWidget(ui->page_dessert_turnoff);

    //콘컵 옵션ui 초기세팅
    ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnoff_btn);
    ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnoff_btn);
    ui->stackedWidget_select_optiontype_concup->setCurrentWidget(ui->page_select_turnoff_optiontype_concup);
    //케이크 옵션ui 초기세팅
    ui->stackedWidget_bigcandle->setCurrentWidget(ui->page_bigcandle_turnoff);
    ui->stackedWidget_smallcandle->setCurrentWidget(ui->page_smallcandle_turnoff);
    ui->stackedWidget_dryice->setCurrentWidget(ui->page_dryice_turnoff);
    ui->stackedWidget_dryice_notneed->setCurrentWidget(ui->page_dryice_notneed_turnoff);
    ui->stackedWidget_normalpojang->setCurrentWidget(ui->page_normalpojang_turnon);
    ui->stackedWidget_cakebag->setCurrentWidget(ui->page_cakebag_turnoff);
    ui->stackedWidget_pojang_notneed->setCurrentWidget(ui->page_pojang_notneed_turnoff);
    ui->stackedWidget_spoon_notneed->setCurrentWidget(ui->page_spoon_notneed_turnon);
    ui->stackedWidget_spoon->setCurrentWidget(ui->page_spoon_turnoff);
    //음료 옵션ui 초기세팅
    ui->stackedWidget_normalcup_beverage->setCurrentWidget(ui->page_normalcup_turnon_beverage);
    ui->stackedWidget_privatecup_beverage->setCurrentWidget(ui->page_privatecup_turnoff_beverage);
    //커피 옵션ui 초기세팅
    ui->stackedWidget_extrashot->setCurrentWidget(ui->page_extrashot_turnoff);
    ui->stackedWidget_extrashot_notneed->setCurrentWidget(ui->page_extrashot_notneed_turnon);
    ui->stackedWidget_normalcup->setCurrentWidget(ui->page_normalcup_turnon);
    ui->stackedWidget_privatecup->setCurrentWidget(ui->page_privatecup_turnoff);
    //단품 옵션ui 초기세팅
    ui->stackedWidget_spoon_notneed_singleitem->setCurrentWidget(ui->page_spoon_notneed_turnon_singleitem);
    ui->stackedWidget_spoon_singleitem->setCurrentWidget(ui->page_spoon_turnoff_singleitem);

    this->con_count = 0;
    this->cup_count = 0;
}

void menu::connectdb()
{
    this->db = QSqlDatabase::addDatabase("QMYSQL");
    this->db.setHostName("10.10.20.116");
    this->db.setPort(3306);
    this->db.setDatabaseName("scar_db");
    this->db.setUserName("scar");
    this->db.setPassword("1234");
    this->db.open();
}

void menu::option_startsetting()
{
    //콘컵 옵션ui 초기세팅
    ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnoff_btn);
    ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnoff_btn);
    ui->stackedWidget_select_optiontype_concup->setCurrentWidget(ui->page_select_turnoff_optiontype_concup);
    //케이크 옵션ui 초기세팅
    ui->stackedWidget_bigcandle->setCurrentWidget(ui->page_bigcandle_turnoff);
    ui->stackedWidget_smallcandle->setCurrentWidget(ui->page_smallcandle_turnoff);
    ui->stackedWidget_dryice->setCurrentWidget(ui->page_dryice_turnoff);
    ui->stackedWidget_dryice_notneed->setCurrentWidget(ui->page_dryice_notneed_turnoff);
    ui->stackedWidget_normalpojang->setCurrentWidget(ui->page_normalpojang_turnon);
    ui->stackedWidget_cakebag->setCurrentWidget(ui->page_cakebag_turnoff);
    ui->stackedWidget_pojang_notneed->setCurrentWidget(ui->page_pojang_notneed_turnoff);
    ui->stackedWidget_spoon_notneed->setCurrentWidget(ui->page_spoon_notneed_turnon);
    ui->stackedWidget_spoon->setCurrentWidget(ui->page_spoon_turnoff);
    //음료 옵션ui 초기세팅
    ui->stackedWidget_normalcup_beverage->setCurrentWidget(ui->page_normalcup_turnon_beverage);
    ui->stackedWidget_privatecup_beverage->setCurrentWidget(ui->page_privatecup_turnoff_beverage);
    //커피 옵션ui 초기세팅
    ui->stackedWidget_extrashot->setCurrentWidget(ui->page_extrashot_turnoff);
    ui->stackedWidget_extrashot_notneed->setCurrentWidget(ui->page_extrashot_notneed_turnon);
    ui->stackedWidget_normalcup->setCurrentWidget(ui->page_normalcup_turnon);
    ui->stackedWidget_privatecup->setCurrentWidget(ui->page_privatecup_turnoff);
    //단품 옵션ui 초기세팅
    ui->stackedWidget_spoon_notneed_singleitem->setCurrentWidget(ui->page_spoon_notneed_turnon_singleitem);
    ui->stackedWidget_spoon_singleitem->setCurrentWidget(ui->page_spoon_turnoff_singleitem);

    this->con_count = 0;
    this->cup_count = 0;
    this->bigcandle_count=0;
    this->smallcandle_count=0;
    this->dryice_count=0;
    this->spoon_count_cake=0;
    this->spoon_count_singleitem=0;
}

void menu::bringmenu()
{
    QSqlQuery query(this->db);
    QString sql_icecream = "select menu_name, menu_file_path, price from menus where menu_id between 0 AND 29;"; // -> 케이크 가져오는 쿼리
    if (!query.exec(sql_icecream)) {
        return;
    }
    while (query.next()) {
        QString menuName = query.value(0).toString();
        QString menuFilePath = query.value(1).toString();
        QString menuPrice = query.value(2).toString();
        this->btns2.append(new menubtn2 (this, menuName, menuFilePath, menuPrice));
    }

    int d = 0;
    for (int row = 0; row < (int)(this->btns2.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (d >= this->btns2.size()) break;
            ui->gridLayout_icecreamcake->addWidget(this->btns2[d], row, col);
            d++;
        }
    }

    /*  메뉴 선택 -> 커피 30~44 */

    QString sql_coffee = "select menu_name, menu_file_path, price from menus where menu_id between 30 AND 44;"; // -> 커피 가져오는 쿼리
    if (!query.exec(sql_coffee)) {
        return;
    }
    while (query.next()) {
        QString menuName = query.value(0).toString();
        QString menuFilePath = query.value(1).toString();
        QString menuPrice = query.value(2).toString();
        this->btns2.append(new menubtn2 (this, menuName, menuFilePath, menuPrice));
    }

    for (int row = 0; row < (int)(this->btns2.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (d >= this->btns2.size()) break;
            ui->gridLayout_coffee->addWidget(this->btns2[d], row, col);
            d++;
        }
    }

    /*  메뉴 선택 ->  디저트 45~86 */
    QString sql_dessert = "select menu_name, menu_file_path, price from menus where menu_id between 45 AND 86;"; // -> 음료/블라스트 가져오는 쿼리
    if (!query.exec(sql_dessert)) {
        return;
    }
    while (query.next()) {
        QString menuName = query.value(0).toString();
        QString menuFilePath = query.value(1).toString();
        QString menuPrice = query.value(2).toString();
        this->btns2.append(new menubtn2 (this, menuName, menuFilePath, menuPrice));
    }

    for (int row = 0; row < (int)(this->btns2.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (d >= this->btns2.size()) break;
            ui->gridLayout_dessert->addWidget(this->btns2[d], row, col);
            d++;
        }
    }

    /*  메뉴 선택 -> 레디팩 140~165 */
    QString sql_readypack = "select menu_name, menu_file_path, price from menus where menu_id between 140 AND 165;"; // -> 레디팩 가져오는 쿼리
    if (!query.exec(sql_readypack)) {
        return;
    }
    while (query.next()) {
        QString menuName = query.value(0).toString();
        QString menuFilePath = query.value(1).toString();
        QString menuPrice = query.value(2).toString();
        this->btns2.append(new menubtn2 (this, menuName, menuFilePath, menuPrice));
    }

    for (int row = 0; row < (int)(this->btns2.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (d >= this->btns2.size()) break;
            ui->gridLayout_readypack->addWidget(this->btns2[d], row, col);
            d++;
        }
    }



    /*  메뉴 선택 ->  음료 블라스트 120~139 */
    QString sql_blast = "select menu_name, menu_file_path, price from menus where menu_id between 120 AND 139;"; // -> 음료/블라스트 가져오는 쿼리
    if (!query.exec(sql_blast)) {
        return;
    }
    while (query.next()) {
        QString menuName = query.value(0).toString();
        QString menuFilePath = query.value(1).toString();
        QString menuPrice = query.value(2).toString();
        this->btns2.append(new menubtn2 (this, menuName, menuFilePath, menuPrice));
    }

    for (int row = 0; row < (int)(this->btns2.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (d >= this->btns2.size()) break;
            ui->gridLayout_beverage->addWidget(this->btns2[d], row, col);
            d++;
        }
    }

    /*  메뉴 선택 ->  아이스크림 166~175 */
    QString sql_size = "select menu_name, menu_file_path, price from menus where menu_id between 166 AND 175;"; // -> 아이스크림 메뉴 가져오는 쿼리
    if (!query.exec(sql_size)) {
        return;
    }
    while (query.next()) {
        QString menuName = query.value(0).toString();
        QString menuFilePath = query.value(1).toString();
        QString menuPrice = query.value(2).toString();
        this->btns2.append(new menubtn2 (this, menuName, menuFilePath, menuPrice));
    }

    for (int row = 0; row < (int)(this->btns2.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (d >= this->btns2.size()) break;
            ui->gridLayout_icecream->addWidget(this->btns2[d], row, col);
            d++;
        }
    }


    /* 맛 선택 */
    /*  flavor 선택 -> all  87~119*/
    QString sql_all = "select menu_name, menu_file_path from menus where menu_id between 87 AND 119;";  //-> 아이스크림 가져오는 쿼리
    if (!query.exec(sql_all)) {
        return;
    }

    while (query.next()) {
        QString menuName = query.value(0).toString();
        QString menuFilePath = query.value(1).toString();
        qDebug() << "menu_name:" << menuName << ", menu_file_path:" << menuFilePath;

        this->btns.append(new MenuBtn(this, menuName, menuFilePath));
    }


    int c = 0;
    for (int row = 0; row < (int)(this->btns.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (c >= this->btns.size()) break;
            ui->gridLayout_all->addWidget(this->btns[c], row, col);
            c++;
        }
    }

    /*  flavor 선택 -> pick  */
    this->btns.append(new MenuBtn(this, "봄날의 곰을 좋아하세요?", ":/image/icecream/ice_strawberry_banana_and_bear_jelly"));
    this->btns.append(new MenuBtn(this, "치토스 밀크셰이크 아이스크림",":/image/icecream/chitos_milkshake_icecream"));
    this->btns.append(new MenuBtn(this, "아이스 칸탈로프 멜론",":/image/icecream/ice_cantaloupe_melon"));
    this->btns.append(new MenuBtn(this, "아이 원-츄!",":/image/icecream/iwantchu"));

    this->btns.append(new MenuBtn(this, "소금 우유 아이스크림",":/image/icecream/salt_milk_icecream"));
    this->btns.append(new MenuBtn(this, "블루베리 파나코타",":/image/icecream/blueberry_panacota"));
    this->btns.append(new MenuBtn(this, "오레오 쿠앤크",":/image/icecream/oreo_cookie_and_cream"));
    this->btns.append(new MenuBtn(this, "민트 초콜릿 칩",":/image/icecream/mint_chocolate_chip"));

    for (int row = 0; row < (int)(this->btns.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (c >= this->btns.size()) break;
            ui->gridLayout_recommand->addWidget(this->btns[c], row, col);
            c++;
        }
    }

    //빈 아이콘 생성하여 위로 붙임
    for (int row =2; row <3; row++){
        for (int col =0; col<4; col++){
            this->btns.append(new MenuBtn(this, "",""));
            ui->gridLayout_recommand->addWidget(this->btns[c++], row, col);
        }
    }


    /*  flavor 선택 -> 과일  */
    this->btns.append(new MenuBtn(this, "봄날의 곰을 좋아하세요?", ":/image/icecream/ice_strawberry_banana_and_bear_jelly"));
    this->btns.append(new MenuBtn(this, "레인보우 샤베트",":/image/icecream/rainbow_sharbet"));
    this->btns.append(new MenuBtn(this, "아이스 칸탈로프 멜론",":/image/icecream/ice_cantaloupe_melon"));
    this->btns.append(new MenuBtn(this, "아이스 메론빵",":/image/icecream/ice_mellonbread"));

    this->btns.append(new MenuBtn(this, "애플 민트",":/image/icecream/apple_mint"));
    this->btns.append(new MenuBtn(this, "베리베리 스트로베리",":/image/icecream/berryberry_strawberry"));
    this->btns.append(new MenuBtn(this, "블랙 소르베",":/image/icecream/black_sorbet"));
    this->btns.append(new MenuBtn(this, "블루베리 파나코타",":/image/icecream/blueberry_panacota"));

    this->btns.append(new MenuBtn(this, "블루베리 요거트",":/image/icecream/blueberry_yogurt"));
    this->btns.append(new MenuBtn(this, "체리쥬빌레",":/image/icecream/cheeries_jubilee"));
    this->btns.append(new MenuBtn(this, "디노 젤리",":/image/icecream/dino_jelly"));
    this->btns.append(new MenuBtn(this, "바람과 함께 사라지다",":/image/icecream/gonewiththewind"));

    this->btns.append(new MenuBtn(this, "청포도 샤베트",":/image/icecream/greengrape_sherbet"));
    this->btns.append(new MenuBtn(this, "망고 탱고",":/image/icecream/mango_tango"));
    this->btns.append(new MenuBtn(this, "피치 요거트",":/image/icecream/peach_yogurt"));
    this->btns.append(new MenuBtn(this, "슈팅스타",":/image/icecream/shootingstar"));

    for (int row = 0; row < (int)(this->btns.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (c >= this->btns.size()) break;
            ui->gridLayout_fruit->addWidget(this->btns[c], row, col);
            c++;
        }
    }

    /*  flavor 선택 -> 초코  */
    this->btns.append(new MenuBtn(this, "엄마는 외계인",":/image/icecream/mom_is_alien"));
    this->btns.append(new MenuBtn(this, "민트 초콜릿 칩",":/image/icecream/mint_chocolate_chip"));
    this->btns.append(new MenuBtn(this, "초콜릿",":/image/icecream/chocolate"));
    this->btns.append(new MenuBtn(this, "초콜릿 무스",":/image/icecream/chocolate_mousse"));

    for (int row = 0; row < (int)(this->btns.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (c >= this->btns.size()) break;
            ui->gridLayout_choco->addWidget(this->btns[c], row, col);
            c++;
        }
    }

    //빈 아이콘 생성하여 위로 붙임
    for (int row =1; row <3; row++){
        for (int col =0; col<4; col++){
            this->btns.append(new MenuBtn(this, "",""));
            ui->gridLayout_choco->addWidget(this->btns[c++], row, col);
        }
    }

    /*  flavor 선택 -> 우유 치즈 */
    this->btns.append(new MenuBtn(this, "피치 요거트",":/image/icecream/peach_yogurt"));
    this->btns.append(new MenuBtn(this, "바람과 함께 사라지다",":/image/icecream/gonewiththewind"));
    this->btns.append(new MenuBtn(this, "31 요거트",":/image/icecream/31yogurt"));
    this->btns.append(new MenuBtn(this, "오레오 쿠앤크",":/image/icecream/oreo_cookie_and_cream"));
    this->btns.append(new MenuBtn(this, "소금 우유 아이스크림",":/image/icecream/salt_milk_icecream"));
    this->btns.append(new MenuBtn(this, "블루베리 파나코타",":/image/icecream/blueberry_panacota"));
    this->btns.append(new MenuBtn(this, "이상한 나라의 솜사탕",":/image/icecream/wired_land_candy"));
    this->btns.append(new MenuBtn(this, "블루베리 요거트",":/image/icecream/blueberry_yogurt"));
    this->btns.append(new MenuBtn(this, "치토스 밀크셰이크 아이스크림",":/image/icecream/chitos_milkshake_icecream"));

    for (int row = 0; row < (int)(this->btns.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (c >= this->btns.size()) break;
            ui->gridLayout_milk->addWidget(this->btns[c], row, col);
            c++;
        }
    }

    //빈 아이콘 생성하여 위로 붙임
    for (int row =2; row <3; row++){
        for (int col =1; col<4; col++){
            this->btns.append(new MenuBtn(this, "",""));
            ui->gridLayout_milk->addWidget(this->btns[c++], row, col);
        }
    }



    /*  flavor 선택 -> 커피 카라멜 티 */
    this->btns.append(new MenuBtn(this, "자모카 아몬드 훠지",":/image/icecream/jamoca_almond_fudge"));
    this->btns.append(new MenuBtn(this, "그린티",":/image/icecream/greentea"));

    for (int row = 0; row < (int)(this->btns.size()+3) / 4; row++) {
        for (int col = 0; col < 3; col++ ) {
            if (c >= this->btns.size()) break;
            ui->gridLayout_caramel->addWidget(this->btns[c], row, col);
            c++;
        }
    }

    //빈 버튼 추가
    this->btns.append(new MenuBtn(this, "",""));
    ui->gridLayout_caramel->addWidget(this->btns[c++], 0, 2);
    this->btns.append(new MenuBtn(this, "",""));
    ui->gridLayout_caramel->addWidget(this->btns[c++], 0, 3);
    this->btns.append(new MenuBtn(this, "",""));
    ui->gridLayout_caramel->addWidget(this->btns[c++], 1, 0);
    this->btns.append(new MenuBtn(this, "",""));
    ui->gridLayout_caramel->addWidget(this->btns[c++], 2, 0);
    this->btns.append(new MenuBtn(this, "",""));
    ui->gridLayout_caramel->addWidget(this->btns[c++], 3, 0);




    /*  flavor 선택 -> 바닐라 민트*/
    this->btns.append(new MenuBtn(this, "아몬드 봉봉",":/image/icecream/armond_bonbon"));
    this->btns.append(new MenuBtn(this, "슈팅스타",":/image/icecream/shootingstar"));
    this->btns.append(new MenuBtn(this, "애플 민트",":/image/icecream/apple_mint"));
    this->btns.append(new MenuBtn(this, "바닐라",":/image/icecream/vanilla"));

    this->btns.append(new MenuBtn(this, "오레오 쿠앤크",":/image/icecream/oreo_cookie_and_cream"));
    this->btns.append(new MenuBtn(this, "허니 크런치",":/image/icecream/honey_crunch"));

    for (int row = 0; row < (int)(this->btns.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (c >= this->btns.size()) break;
            ui->gridLayout_mint->addWidget(this->btns[c], row, col);
            c++;
        }
    }

    //빈 버튼 추가
    for (int row = 1; row <3; row++){
        for (int col =2; col <4; col++){
            this->btns.append(new MenuBtn(this, "",""));
            ui->gridLayout_mint->addWidget(this->btns[c++], row, col);
        }
    }

    /*  flavor 선택 -> 곡물 견과류*/
    this->btns.append(new MenuBtn(this, "아몬드 봉봉",":/image/icecream/armond_bonbon"));
    this->btns.append(new MenuBtn(this, "피스타치오 아몬드",":/image/icecream/pistachio_almond"));
    this->btns.append(new MenuBtn(this, "자모카 아몬드 훠지",":/image/icecream/jamoca_almond_fudge"));
    this->btns.append(new MenuBtn(this, "허니 크런치",":/image/icecream/honey_crunch"));

    for (int row = 0; row < (int)(this->btns.size()+3) / 4; row++) {
        for (int col = 0; col < 4; col++ ) {
            if (c >= this->btns.size()) break;
            ui->gridLayout_nuts->addWidget(this->btns[c], row, col);
            c++;
        }
    }

    //빈 버튼 추가
    for (int row=1; row< 3; row++){
        for (int col=0; col<4; col++){
            this->btns.append(new MenuBtn(this, "",""));
            ui->gridLayout_nuts->addWidget(this->btns[c++], row, col);
        }
    }
}

void menu::connectsetting()
{
    connect(ui->btn_go_home, &QPushButton::clicked, this, &menu::gohome_signalf);
}

void menu::concup_plus_minus()
{
    //컵추가
    connect(ui->btn_cup_plus, &QPushButton::clicked, this, [this](){
        this->cup_count++;
        ui->lineEdit_cup_quantity->setText(QString::number(this->cup_count));
        ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnon_btn);
        toggle_select_complete();
    });
    //컵빼기
    connect(ui->btn_cup_minus, &QPushButton::clicked, this, [this](){
        if(cup_count>0)
        {
            this->cup_count--;
            ui->lineEdit_cup_quantity->setText(QString::number(this->cup_count));
            ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnon_btn);
        }
        if(cup_count ==0){
            ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnoff_btn);
        }
        toggle_select_complete();
    });
    //콘추가
    connect(ui->btn_con_plus, &QPushButton::clicked, this, [this](){
        this->con_count++;
        ui->lineEdit_con_quantity->setText(QString::number(this->con_count));
        ui->stackedWidget_con_btn->setCurrentWidget(ui->page_conquantity_turnon_btn);
        toggle_select_complete();
    });
    //콘빼기
    connect(ui->btn_con_minus, &QPushButton::clicked, this, [this](){
        if(con_count>0)
        {
            this->con_count--;
        }
        if(con_count ==0){
            ui->stackedWidget_con_btn->setCurrentWidget(ui->page_conquantity_turnoff_btn);
        }
        ui->lineEdit_con_quantity->setText(QString::number(this->con_count));
        toggle_select_complete();
    });


}

int menu::toggle_select_complete(){
    if(con_count || cup_count)
    {
        // 선택완료 불을 켜자
        ui->stackedWidget_select_optiontype_concup->setCurrentWidget(ui->page_select_turnon_optiontype_concup);
        return select_flag = 1;

    }else{
        //선택완료 버튼 불을끄자
        ui->stackedWidget_select_optiontype_concup->setCurrentWidget(ui->page_select_turnoff_optiontype_concup);
        return select_flag = 0;
    }
}

void menu::select_flavor_page(){
    if(select_flag == 1){
        ui->stackedWidget_main->setCurrentWidget(ui->page_main_flavor);
    }
}

void menu::gohome_signalf()
{
    emit gohome();
}

void menu::option_btn_control()
{
    //케이크 옵션
    //큰초 옵션
    connect(ui->btn_candle_plus_turnoff, &QPushButton::clicked, this, [this](){
        this->bigcandle_count++;
        (ui->stackedWidget_bigcandle->setCurrentWidget(ui->page_bigcandle_turnon));
        (ui->lineEdit_candle_quantity->setText(QString::number(bigcandle_count)));
    });
    connect(ui->btn_candle_plus, &QPushButton::clicked, this, [this](){
        this->bigcandle_count++;
        (ui->lineEdit_candle_quantity->setText(QString::number(bigcandle_count)));
    });
    connect(ui->btn_candle_minus, &QPushButton::clicked, this, [this](){
        this->bigcandle_count--;
        (ui->lineEdit_candle_quantity->setText(QString::number(bigcandle_count)));
        if(bigcandle_count==0)
        {
            (ui->stackedWidget_bigcandle->setCurrentWidget(ui->page_bigcandle_turnoff));
        }
    });
    //작은초 옵션
    connect(ui->btn_smallcandle_plus_turnoff, &QPushButton::clicked, this, [this](){
        this->smallcandle_count++;
        (ui->stackedWidget_smallcandle->setCurrentWidget(ui->page_smallcandle_turnon));
        (ui->lineEdit_smallcandle_quantity->setText(QString::number(smallcandle_count)));
    });
    connect(ui->btn_smallcandle_plus, &QPushButton::clicked, this, [this](){
        this->smallcandle_count++;
        (ui->lineEdit_smallcandle_quantity->setText(QString::number(smallcandle_count)));
    });
    connect(ui->btn_smallcandle_minus, &QPushButton::clicked, this, [this](){
        this->smallcandle_count--;
        (ui->lineEdit_smallcandle_quantity->setText(QString::number(smallcandle_count)));
        if(smallcandle_count==0)
        {
            (ui->stackedWidget_smallcandle->setCurrentWidget(ui->page_smallcandle_turnoff));
        }
    });
    //드라이아이스 옵션
    connect(ui->btn_dryice_plus_turnoff, &QPushButton::clicked, this, [this](){
        this->dryice_count +=10;
        (ui->stackedWidget_dryice->setCurrentWidget(ui->page_dryice_turnon));
        (ui->lineEdit_dryice_quantity->setText(QString::number(dryice_count)));
        (ui->stackedWidget_dryice_notneed->setCurrentWidget(ui->page_dryice_notneed_turnoff));
    });
    connect(ui->btn_dryice_plus, &QPushButton::clicked, this, [this](){
        if(dryice_count<30)
        {
            this->dryice_count += 10;
            (ui->lineEdit_dryice_quantity->setText(QString::number(dryice_count)));
        }
    });
    connect(ui->btn_dryice_minus, &QPushButton::clicked, this, [this](){
        this->dryice_count -= 10;
        (ui->lineEdit_dryice_quantity->setText(QString::number(dryice_count)));
        if(dryice_count==0)
        {
            (ui->stackedWidget_dryice->setCurrentWidget(ui->page_dryice_turnoff));
            (ui->stackedWidget_dryice_notneed->setCurrentWidget(ui->page_dryice_notneed_turnon));
        }
    });
    //드라이 필요없음 옵션
    connect(ui->btn_dryice_notneed_turnoff, &QPushButton::clicked, this, [this](){
        this->dryice_count=0;
        (ui->stackedWidget_dryice_notneed->setCurrentWidget(ui->page_dryice_notneed_turnon));
        (ui->stackedWidget_dryice->setCurrentWidget(ui->page_dryice_turnoff));
    });
    //포장 옵션
    connect(ui->btn_normalpojang_turnoff, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_normalpojang->setCurrentWidget(ui->page_normalpojang_turnon));
        (ui->stackedWidget_cakebag->setCurrentWidget(ui->page_cakebag_turnoff));
        (ui->stackedWidget_pojang_notneed->setCurrentWidget(ui->page_pojang_notneed_turnoff));
    });
    connect(ui->btn_cakebag_turnoff, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_cakebag->setCurrentWidget(ui->page_cakebag_turnon));
        (ui->stackedWidget_normalpojang->setCurrentWidget(ui->page_normalpojang_turnoff));
        (ui->stackedWidget_pojang_notneed->setCurrentWidget(ui->page_pojang_notneed_turnoff));
    });
    connect(ui->btn_pojang_notneed_turnoff, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_pojang_notneed->setCurrentWidget(ui->page_pojang_notneed_turnon));
        (ui->stackedWidget_normalpojang->setCurrentWidget(ui->page_normalpojang_turnoff));
        (ui->stackedWidget_cakebag->setCurrentWidget(ui->page_cakebag_turnoff));
    });
    //스푼 옵션
    connect(ui->btn_spoon_plus_turnoff, &QPushButton::clicked, this, [this](){
        this->spoon_count_cake++;
        (ui->stackedWidget_spoon->setCurrentWidget(ui->page_spoon_turnon));
        (ui->stackedWidget_spoon_notneed->setCurrentWidget(ui->page_spoon_notneed_turnoff));
        (ui->lineEdit_spoon_quantity->setText(QString::number(spoon_count_cake)));
    });
    connect(ui->btn_spoon_plus, &QPushButton::clicked, this, [this](){
        this->spoon_count_cake++;
        (ui->lineEdit_spoon_quantity->setText(QString::number(spoon_count_cake)));
    });
    connect(ui->btn_spoon_minus, &QPushButton::clicked, this, [this](){
        this->spoon_count_cake--;
        (ui->lineEdit_spoon_quantity->setText(QString::number(spoon_count_cake)));
        if(spoon_count_cake==0)
        {
            (ui->stackedWidget_spoon->setCurrentWidget(ui->page_spoon_turnoff));
            (ui->stackedWidget_spoon_notneed->setCurrentWidget(ui->page_spoon_notneed_turnon));
        }
    });
    //스푼 필요없음 옵션
    connect(ui->btn_spoon_notneed_turnoff, &QPushButton::clicked, this, [this](){
        this->spoon_count_cake=0;
        (ui->stackedWidget_spoon_notneed->setCurrentWidget(ui->page_spoon_notneed_turnon));
        (ui->stackedWidget_spoon->setCurrentWidget(ui->page_spoon_turnoff));
    });
    //음료 옵션
    //일반컵 옵션
    connect(ui->btn_normalcup_turnoff_beverage, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_normalcup_beverage->setCurrentWidget(ui->page_normalcup_turnon_beverage));
        (ui->stackedWidget_privatecup_beverage->setCurrentWidget(ui->page_privatecup_turnoff_beverage));
    });
    connect(ui->btn_privatecup_turnoff_beverage, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_privatecup_beverage->setCurrentWidget(ui->page_privatecup_turnon_beverage));
        (ui->stackedWidget_normalcup_beverage->setCurrentWidget(ui->page_normalcup_turnoff_beverage));
    });
    //커피 옵션
    //샷 옵션
    connect(ui->btn_extrashot_notneed_turnoff, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_extrashot_notneed->setCurrentWidget(ui->page_extrashot_notneed_turnon));
        (ui->stackedWidget_extrashot->setCurrentWidget(ui->page_extrashot_turnoff));
    });
    connect(ui->btn_extrashot_turnoff, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_extrashot_notneed->setCurrentWidget(ui->page_extrashot_notneed_turnoff));
        (ui->stackedWidget_extrashot->setCurrentWidget(ui->page_extrashot_turnon));
    });
    connect(ui->btn_normalcup_turnoff, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_normalcup->setCurrentWidget(ui->page_normalcup_turnon));
        (ui->stackedWidget_privatecup->setCurrentWidget(ui->page_privatecup_turnoff));
    });
    connect(ui->btn_privatecup_turnoff, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_privatecup->setCurrentWidget(ui->page_privatecup_turnon));
        (ui->stackedWidget_normalcup->setCurrentWidget(ui->page_normalcup_turnoff));
    });
    //단품 스푼 옵션
    connect(ui->btn_spoon_plus_turnoff_singleitem, &QPushButton::clicked, this, [this](){
        this->spoon_count_singleitem++;
        (ui->stackedWidget_spoon_singleitem->setCurrentWidget(ui->page_spoon_turnon_singleitem));
        (ui->stackedWidget_spoon_notneed_singleitem->setCurrentWidget(ui->page_spoon_notneed_turnoff_singleitem));
        (ui->lineEdit_spoon_quantity_singleitem->setText(QString::number(spoon_count_singleitem)));
    });
    connect(ui->btn_spoon_plus_singleitem, &QPushButton::clicked, this, [this](){
        this->spoon_count_singleitem++;
        (ui->lineEdit_spoon_quantity_singleitem->setText(QString::number(spoon_count_singleitem)));
    });
    connect(ui->btn_spoon_minus_singleitem, &QPushButton::clicked, this, [this](){
        this->spoon_count_singleitem--;
        (ui->lineEdit_spoon_quantity_singleitem->setText(QString::number(spoon_count_singleitem)));
        if(spoon_count_singleitem==0)
        {
            (ui->stackedWidget_spoon_singleitem->setCurrentWidget(ui->page_spoon_turnoff_singleitem));
            (ui->stackedWidget_spoon_notneed_singleitem->setCurrentWidget(ui->page_spoon_notneed_turnon_singleitem));
        }
    });
    //스푼 필요없음 옵션
    connect(ui->btn_spoon_notneed_turnoff_singleitem, &QPushButton::clicked, this, [this](){
        this->spoon_count_singleitem=0;
        (ui->stackedWidget_spoon_notneed_singleitem->setCurrentWidget(ui->page_spoon_notneed_turnon_singleitem));
        (ui->stackedWidget_spoon_singleitem->setCurrentWidget(ui->page_spoon_turnoff_singleitem));
    });



    //케이크 옵션에서 이전화면과 선택완료
    connect(ui->btn_goback_optiontype_cake, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu));
        option_startsetting();
        //이전에 선택했던 메뉴 사라지게 해야함.
    });
    connect(ui->btn_select_turnon_optiontype_cake, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu));
        //세팅한 옵션 저장되어야함.
        // opt0.setName("큰초");
        // opt0.setQuantity(bigcandle_count); //ui->lineEdit_candle_quantity->text()
        // opt0.setPrice(0);
        // options.append(opt0);
        // opt1.setName("작은초");
        // opt1.setQuantity(smallcandle_count);
        // opt1.setPrice(0);
        // opt2.setName("드라이아이스");
        // opt2.setQuantity(dryice_count);
        // opt2.setPrice(0);
        // option_startsetting();
    });
    //음료 옵션에서 이전화면과 선택 완료
    connect(ui->btn_goback_optiontype_beverage, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu));
        option_startsetting();
        //이전에 선택했던 메뉴 사라지게 해야함.
    });
    connect(ui->btn_select_turnon_optiontype_beverage, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu));
        option_startsetting();
        //세팅한 옵션 저장되어야함.
    });
    //커피 옵션에서 이전화면과 선택 완료
    connect(ui->btn_goback_optiontype_coffee, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu));
        option_startsetting();
        //이전에 선택했던 메뉴 사라지게 해야함.
    });
    connect(ui->btn_select_turnon_optiontype_coffee, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu));
        option_startsetting();
        //세팅한 옵션 저장되어야함.
    });
    //단품 옵션에서 이전화면과 선택 완료
    connect(ui->btn_goback_optiontype_singleitem, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu));
        option_startsetting();
        //이전에 선택했던 메뉴 사라지게 해야함.
    });
    connect(ui->btn_select_turnon_optiontype_singleitem, &QPushButton::clicked, this, [this](){
        (ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu));
        option_startsetting();
        //세팅한 옵션 저장되어야함.
    });
}

void menu::bottom_btn_control()
{
    connect(ui->btn_goback_optiontype_concup, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu);
    });
    if(con_count>0||cup_count>0)
        ui->stackedWidget_select_optiontype_concup->setCurrentWidget(ui->page_select_turnon_optiontype_concup);
    else if(con_count==0&&cup_count==0)
        ui->stackedWidget_select_optiontype_concup->setCurrentWidget(ui->page_select_turnoff_optiontype_concup);
    connect(ui->btn_select_turnon_optiontype_coffee, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_main->setCurrentWidget(ui->page_main_flavor);
    });
}

void menu::type_menu_btn_control()
{
    //아이스크림 케이크 버튼
    connect(ui->btn_icecreamcake_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_icecreamcake_btn->setCurrentWidget(ui->page_icecreamcake_turnon);
        ui->stackedWidget_icecream_btn->setCurrentWidget(ui->page_icecream_turnoff);
        ui->stackedWidget_readypack_btn->setCurrentWidget(ui->page_readypack_turnoff);
        ui->stackedWidget_coffee_btn->setCurrentWidget(ui->page_coffee_turnoff);
        ui->stackedWidget_beverage_btn->setCurrentWidget(ui->page_beverage_turnoff);
        ui->stackedWidget_dessert_btn->setCurrentWidget(ui->page_dessert_turnoff);
        ui->stackedWidget_arraytype->setCurrentWidget(ui->page_array_icecreamcake);
    });
    //아이스크림 버튼
    connect(ui->btn_icecream_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_icecreamcake_btn->setCurrentWidget(ui->page_icecreamcake_turnoff);
        ui->stackedWidget_icecream_btn->setCurrentWidget(ui->page_icecream_turnon);
        ui->stackedWidget_readypack_btn->setCurrentWidget(ui->page_readypack_turnoff);
        ui->stackedWidget_coffee_btn->setCurrentWidget(ui->page_coffee_turnoff);
        ui->stackedWidget_beverage_btn->setCurrentWidget(ui->page_beverage_turnoff);
        ui->stackedWidget_dessert_btn->setCurrentWidget(ui->page_dessert_turnoff);
        ui->stackedWidget_arraytype->setCurrentWidget(ui->page_array_icecream);
    });
    //레디팩 버튼
    connect(ui->btn_readypack_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_icecreamcake_btn->setCurrentWidget(ui->page_icecreamcake_turnoff);
        ui->stackedWidget_icecream_btn->setCurrentWidget(ui->page_icecream_turnoff);
        ui->stackedWidget_readypack_btn->setCurrentWidget(ui->page_readypack_turnon);
        ui->stackedWidget_coffee_btn->setCurrentWidget(ui->page_coffee_turnoff);
        ui->stackedWidget_beverage_btn->setCurrentWidget(ui->page_beverage_turnoff);
        ui->stackedWidget_dessert_btn->setCurrentWidget(ui->page_dessert_turnoff);
        ui->stackedWidget_arraytype->setCurrentWidget(ui->page_array_readypack);
    });
    //커피 버튼
    connect(ui->btn_coffee_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_icecreamcake_btn->setCurrentWidget(ui->page_icecreamcake_turnoff);
        ui->stackedWidget_icecream_btn->setCurrentWidget(ui->page_icecream_turnoff);
        ui->stackedWidget_readypack_btn->setCurrentWidget(ui->page_readypack_turnoff);
        ui->stackedWidget_coffee_btn->setCurrentWidget(ui->page_coffee_turnon);
        ui->stackedWidget_beverage_btn->setCurrentWidget(ui->page_beverage_turnoff);
        ui->stackedWidget_dessert_btn->setCurrentWidget(ui->page_dessert_turnoff);
        ui->stackedWidget_arraytype->setCurrentWidget(ui->page_array_coffee);
    });
    //음료 버튼
    connect(ui->btn_beverage_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_icecreamcake_btn->setCurrentWidget(ui->page_icecreamcake_turnoff);
        ui->stackedWidget_icecream_btn->setCurrentWidget(ui->page_icecream_turnoff);
        ui->stackedWidget_readypack_btn->setCurrentWidget(ui->page_readypack_turnoff);
        ui->stackedWidget_coffee_btn->setCurrentWidget(ui->page_coffee_turnoff);
        ui->stackedWidget_beverage_btn->setCurrentWidget(ui->page_beverage_turnon);
        ui->stackedWidget_dessert_btn->setCurrentWidget(ui->page_dessert_turnoff);
        ui->stackedWidget_arraytype->setCurrentWidget(ui->page_array_beverage);
    });
    //디저트 버튼
    connect(ui->btn_dessert_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_icecreamcake_btn->setCurrentWidget(ui->page_icecreamcake_turnoff);
        ui->stackedWidget_icecream_btn->setCurrentWidget(ui->page_icecream_turnoff);
        ui->stackedWidget_readypack_btn->setCurrentWidget(ui->page_readypack_turnoff);
        ui->stackedWidget_coffee_btn->setCurrentWidget(ui->page_coffee_turnoff);
        ui->stackedWidget_beverage_btn->setCurrentWidget(ui->page_beverage_turnoff);
        ui->stackedWidget_dessert_btn->setCurrentWidget(ui->page_dessert_turnon);
        ui->stackedWidget_arraytype->setCurrentWidget(ui->page_array_dessert);
    });
}

void menu::flavor_menu_btn_control()
{
    // 추천 맛 버튼
    connect(ui->btn_recommand_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_recommand_btn->setCurrentWidget(ui->page_recommand_turnon);
        ui->stackedWidget_all_btn->setCurrentWidget(ui->page_all_turnoff);
        ui->stackedWidget_fruit_btn->setCurrentWidget(ui->page_fruit_turnoff);
        ui->stackedWidget_choco_btn->setCurrentWidget(ui->page_choco_turnoff);
        ui->stackedWidget_milk_btn->setCurrentWidget(ui->page_milk_turnoff);
        ui->stackedWidget_caramel_btn->setCurrentWidget(ui->page_caramel_turnoff);
        ui->stackedWidget_mint_btn->setCurrentWidget(ui->page_mint_turnoff);
        ui->stackedWidget_nuts_btn->setCurrentWidget(ui->page_nuts_turnoff);
        ui->stackedWidget_arrayflavor->setCurrentWidget(ui->page_array_recommand);
    });
    // 모든 맛 버튼
    connect(ui->btn_all_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_recommand_btn->setCurrentWidget(ui->page_recommand_turnoff);
        ui->stackedWidget_all_btn->setCurrentWidget(ui->page_all_turnon);
        ui->stackedWidget_fruit_btn->setCurrentWidget(ui->page_fruit_turnoff);
        ui->stackedWidget_choco_btn->setCurrentWidget(ui->page_choco_turnoff);
        ui->stackedWidget_milk_btn->setCurrentWidget(ui->page_milk_turnoff);
        ui->stackedWidget_caramel_btn->setCurrentWidget(ui->page_caramel_turnoff);
        ui->stackedWidget_mint_btn->setCurrentWidget(ui->page_mint_turnoff);
        ui->stackedWidget_nuts_btn->setCurrentWidget(ui->page_nuts_turnoff);
        ui->stackedWidget_arrayflavor->setCurrentWidget(ui->page_array_all);
    });
    // 과일 맛 버튼
    connect(ui->btn_fruit_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_recommand_btn->setCurrentWidget(ui->page_recommand_turnoff);
        ui->stackedWidget_all_btn->setCurrentWidget(ui->page_all_turnoff);
        ui->stackedWidget_fruit_btn->setCurrentWidget(ui->page_fruit_turnon);
        ui->stackedWidget_choco_btn->setCurrentWidget(ui->page_choco_turnoff);
        ui->stackedWidget_milk_btn->setCurrentWidget(ui->page_milk_turnoff);
        ui->stackedWidget_caramel_btn->setCurrentWidget(ui->page_caramel_turnoff);
        ui->stackedWidget_mint_btn->setCurrentWidget(ui->page_mint_turnoff);
        ui->stackedWidget_nuts_btn->setCurrentWidget(ui->page_nuts_turnoff);
        ui->stackedWidget_arrayflavor->setCurrentWidget(ui->page_array_fruit);
    });
    // 초코 맛 버튼
    connect(ui->btn_choco_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_recommand_btn->setCurrentWidget(ui->page_recommand_turnoff);
        ui->stackedWidget_all_btn->setCurrentWidget(ui->page_all_turnoff);
        ui->stackedWidget_fruit_btn->setCurrentWidget(ui->page_fruit_turnoff);
        ui->stackedWidget_choco_btn->setCurrentWidget(ui->page_choco_turnon);
        ui->stackedWidget_milk_btn->setCurrentWidget(ui->page_milk_turnoff);
        ui->stackedWidget_caramel_btn->setCurrentWidget(ui->page_caramel_turnoff);
        ui->stackedWidget_mint_btn->setCurrentWidget(ui->page_mint_turnoff);
        ui->stackedWidget_nuts_btn->setCurrentWidget(ui->page_nuts_turnoff);
        ui->stackedWidget_arrayflavor->setCurrentWidget(ui->page_array_choco);
    });
    // 우유 맛 버튼
    connect(ui->btn_milk_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_recommand_btn->setCurrentWidget(ui->page_recommand_turnoff);
        ui->stackedWidget_all_btn->setCurrentWidget(ui->page_all_turnoff);
        ui->stackedWidget_fruit_btn->setCurrentWidget(ui->page_fruit_turnoff);
        ui->stackedWidget_choco_btn->setCurrentWidget(ui->page_choco_turnoff);
        ui->stackedWidget_milk_btn->setCurrentWidget(ui->page_milk_turnon);
        ui->stackedWidget_caramel_btn->setCurrentWidget(ui->page_caramel_turnoff);
        ui->stackedWidget_mint_btn->setCurrentWidget(ui->page_mint_turnoff);
        ui->stackedWidget_nuts_btn->setCurrentWidget(ui->page_nuts_turnoff);
        ui->stackedWidget_arrayflavor->setCurrentWidget(ui->page_array_milk);
    });
    // 카라멜 맛 버튼
    connect(ui->btn_caramel_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_recommand_btn->setCurrentWidget(ui->page_recommand_turnoff);
        ui->stackedWidget_all_btn->setCurrentWidget(ui->page_all_turnoff);
        ui->stackedWidget_fruit_btn->setCurrentWidget(ui->page_fruit_turnoff);
        ui->stackedWidget_choco_btn->setCurrentWidget(ui->page_choco_turnoff);
        ui->stackedWidget_milk_btn->setCurrentWidget(ui->page_milk_turnoff);
        ui->stackedWidget_caramel_btn->setCurrentWidget(ui->page_caramel_turnon);
        ui->stackedWidget_mint_btn->setCurrentWidget(ui->page_mint_turnoff);
        ui->stackedWidget_nuts_btn->setCurrentWidget(ui->page_nuts_turnoff);
        ui->stackedWidget_arrayflavor->setCurrentWidget(ui->page_array_caramel);
    });
    // 민트 맛 버튼
    connect(ui->btn_mint_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_recommand_btn->setCurrentWidget(ui->page_recommand_turnoff);
        ui->stackedWidget_all_btn->setCurrentWidget(ui->page_all_turnoff);
        ui->stackedWidget_fruit_btn->setCurrentWidget(ui->page_fruit_turnoff);
        ui->stackedWidget_choco_btn->setCurrentWidget(ui->page_choco_turnoff);
        ui->stackedWidget_milk_btn->setCurrentWidget(ui->page_milk_turnoff);
        ui->stackedWidget_caramel_btn->setCurrentWidget(ui->page_caramel_turnoff);
        ui->stackedWidget_mint_btn->setCurrentWidget(ui->page_mint_turnon);
        ui->stackedWidget_nuts_btn->setCurrentWidget(ui->page_nuts_turnoff);
        ui->stackedWidget_arrayflavor->setCurrentWidget(ui->page_array_mint);
    });
    // 곡물 맛 버튼
    connect(ui->btn_nuts_turnoff, &QPushButton::clicked, this, [this](){
        ui->stackedWidget_recommand_btn->setCurrentWidget(ui->page_recommand_turnoff);
        ui->stackedWidget_all_btn->setCurrentWidget(ui->page_all_turnoff);
        ui->stackedWidget_fruit_btn->setCurrentWidget(ui->page_fruit_turnoff);
        ui->stackedWidget_choco_btn->setCurrentWidget(ui->page_choco_turnoff);
        ui->stackedWidget_milk_btn->setCurrentWidget(ui->page_milk_turnoff);
        ui->stackedWidget_caramel_btn->setCurrentWidget(ui->page_caramel_turnoff);
        ui->stackedWidget_mint_btn->setCurrentWidget(ui->page_mint_turnoff);
        ui->stackedWidget_nuts_btn->setCurrentWidget(ui->page_nuts_turnon);
        ui->stackedWidget_arrayflavor->setCurrentWidget(ui->page_array_nuts);
    });
}


//0519 추가

//모든 버튼들에게 클릭이벤트를 준다.(menu 선택 버튼1) -> 커넥트 하면서 즉시 경로 받아오기, 버튼 추가
void menu::clicked_setting(){ //메뉴 선택 버튼 커넥트
    for (int i = 0; i < btns2.size(); i++) {
        connect(btns2[i], &menubtn2::clicked, this, [this, i]() {
            handle_clicked(i);
        });
    }

    for(int i=0; i<btns.size(); i++){ //맛 선택 버튼 커넥트
        connect(this->btns[i], &MenuBtn::clicked, this, [this, i](){
            flavor_name = this->btns[i]->get_flavor_name();
            handle_clicked_flavor(i);
        });
    }
}

//클릭 핸들링
void menu::handle_clicked(int index) {
    QString menuName = btns2[index]->get_menu_name(); //메뉴명 가져오기
    if (is_menu_added(menuName)) { //메뉴명을 사용해서 중복 체크 (중복 시 카트에 담기지 않도록)
        qDebug() << "중복 메뉴:" << menuName;
        return;
    }
    //중복이 아니면
    load_image(menuName); //이미지 로드
    check_icecream(menuName); //아이스크림 여부 , 아이스크림 사이즈 체크 0520
    on_btn_select_turnoff_clicked(); //메뉴 1개이상 선택시 선택완료 체크 가능

    if(this->icecream_flag==1){ //클릭한 객체가 아이스크림이면
        ui->stackedWidget_main->setCurrentWidget(ui->page_option); //맛 선택하는 위젯으로 넘겨라
        ui->stackedWidget_optiontype->setCurrentWidget(ui->page_optiontype_concup);
        size_of_flavor(); //아이스크림 사이즈 구해라
    }
}

void menu::handle_clicked_flavor(int index) {
    flavor_name = btns[index]->get_flavor_name(); //메뉴명 가져오기
    load_image_flavor(flavor_name); //이미지 로드하기
    // flavor_get_object_name(); //번호 부여
    qDebug() << "맛 이름~" << flavor_name;
}


//메뉴 중복검사
bool menu::is_menu_added(const QString &menuName) {
    return add_menu_name.contains(menuName); //리스트에 해당 메뉴가 있는지 없는지
}

//이름 가져와서 이미지 로드하기!!
void menu::load_image(const QString &menuName) {
    QSqlQuery query(db);
    QString sql = QString("select menu_file_path from menus where menu_name = \"%1\"").arg(menuName); //메뉴명을 기준으로 사진 경로 받아오기
    if (query.exec(sql) && query.next()) {
        imgPath = query.value(0).toString(); //경로 파싱
    }
    select_menu *cart = new select_menu(this, imgPath, menu_cnt); //cart라는 이름의 select_menu위젯 객체 생성합니당
    cart->setObjectName(QString::number(btn_cart.size())); //인덱스 기준으로 객체 이름 부여함, 삭제하기 위해서예용~

    add_menu_name.append(menuName); //새로 추가한 이름 리스트에 추가 (중복검사용)
    connect(cart, &select_menu::send_data, this, &menu::recv_data); //삭제 시그널 커넥트
    this->btn_cart.append(cart); //버튼 객체를 리스트에 담음

    //리스트에서 끄내서 화면에 출력
    ui->gridLayout_menu_cart->addWidget(this->btn_cart[e], 0, col_);
    e++; col_++;
    ui->gridLayout_menu_cart->setAlignment(Qt::AlignLeft);
    //라벨 출력
    ui->text_menu_cnt->setText(QString("총 %1개").arg(btn_cart.size()));
}

//0521생성함수
void menu::load_image_flavor(const QString &flavor_name) {
    QSqlQuery query(db);
    QString sql_ = QString("select menu_file_path, menu_id from menus where menu_name = \"%1\"").arg(flavor_name); //메뉴명을 기준으로 사진 경로 받아오기
    if (query.exec(sql_) && query.next()) {
        imgPath = query.value(0).toString(); //경로 파싱
        flavorId = query.value(1).toInt();
    }
    this->btn_flavor_cart[this->flavor_select_num ++]->change_path(imgPath);
}

// void menu::flavor_get_object_name(){
//     for (int i = 0; i < btn_flavor_cart.size(); i++){
//         btn_flavor_cart[i]->setObjectName(QString::number(btn_flavor_cart.size())); //인덱스 기준으로 객체 이름 부여함, 삭제하기 위해서예용~
//     }
// }
//아이스크림 여부 체크하고, 아이스크림 사이즈 확인하기
int menu::check_icecream(const QString &menuName){ //0520
    if (menuName.contains("싱글")){
        menusize = single_; icecream_flag = 1;
    }
    else if (menuName.contains("더블")){
        menusize = double_; icecream_flag = 1;
    }
    else if (menuName == "파인트"){
        menusize = pint; icecream_flag = 2;
    }
    else if (menuName == "쿼터"){
        menusize = quater; icecream_flag = 2;
    }
    else if (menuName == "패밀리"){
        menusize = family; icecream_flag = 2;
    }
    else if (menuName == "하프갤론"){
        menusize = halfgallon; icecream_flag = 2;
    }
    else{
        menusize = 0;
        icecream_flag = 0;
    }

    qDebug() << "menu_size: " << menusize << "아이스크림 플래그" << icecream_flag;
    return menusize;
}

//0521수정
void menu::size_of_flavor(){ //창 넘어가는 즉시 사이즈 만큼 위젯 추가하기 이제 잘 됨
    btn_flavor_cart.clear(); //기존 리스트를 비워줌
    for(int i=0; i <menusize; i++){ // 변수명 소문자로 변경! 대문자는 상수에만 쓰자
        select_flavor *flavor_cart = new select_flavor(this,":/image/etc/cloud.png"); // <-이녀석이 반복문 밖에 있어서 계속 덮어쓰고 있었음. 각각의 객체로 생성하려면 반복문 안에 넣었어야함
        this->btn_flavor_cart.append(flavor_cart); //리스트에 추가
        ui->gridLayout_flavor->addWidget(flavor_cart,0,i);
        ui->gridLayout_flavor->setAlignment(Qt::AlignLeft);
        qDebug() << "야옹";
    }
}

void menu::reorder_objectname() { //인덱스 기준으로 객체 이름 가져오므로 삭제 후 다시 이름 부여해줌
    for (int i = 0; i < btn_cart.size(); i++) {
        btn_cart[i]->setObjectName(QString::number(i));
    }
}

void menu::reorder_flavor_objectname() {
    for (int i = 0; i < btn_flavor_cart.size(); i++) {
        btn_cart[i]->setObjectName(QString::number(i));
    }
}

void menu::recv_data_flavor(QString data){ //맛 삭제 시그널 오면 둥실이를 띄우자
    qDebug() << "flavor Btn: " << data;

    for (int i = 0; i < btn_flavor_cart.size(); i ++){
        if(btn_flavor_cart[i]->objectName()==data){
            ui->gridLayout_flavor->removeWidget(btn_flavor_cart[i]); //그리드에서 위젯 삭제
            select_flavor *flavor_cart = new select_flavor(this,":/image/etc/cloud.png"); //둥실이 객체 새로 만들기 생성
            ui->gridLayout_flavor->addWidget(flavor_cart,0,i); //해당하는 자리에 그대로 위젯 추가하기
            reorder_flavor_objectname(); //혹시 몰라서 재정렬 해볼게요
            break;
        }
    }
}

//ver.02 삭제 시그널이 왔어요!
void menu::recv_data(QString data) {
    qDebug() << "button : " << data;

    for (int i = 0; i < btn_cart.size(); i++) { //리스트의 사이즈만큼 반복하면서
        if (btn_cart[i]->objectName() == data) { //위젯 리스트 objectName 가져옴
            ui->gridLayout_menu_cart->removeWidget(btn_cart[i]); //그리드에서 위젯 삭제
            delete btn_cart[i]; //위젯 리스트에서 삭제함
            btn_cart.removeAt(i); //객체 삭제, 배열은 알아서 당겨집니다.히히
            add_menu_name.removeAt(i); // 중복검사 메뉴 이름도 빼줍니당
            e--;  // 버튼 수 감소
            on_btn_select_turnoff_clicked(); //메뉴 삭제시 선택된 메뉴가 0개 되면 선택완료 버튼 꺼요 0520
            ui->text_menu_cnt->setText(QString("총 %1개").arg(btn_cart.size()));
            reorder_objectname();  // << 여기서 objectName 재정렬함!!
            break;
        }
    }
}

void menu::on_btn_select_turnoff_clicked() //메뉴 선택 시 선택완료 버튼 활성화
{
    ui->btn_select_turnoff->setEnabled(false);

    if (e == 0) //btn_cart.size()
    {
        ui->btn_select_turnoff->setEnabled(false);
        ui->stackedWidget_select_btn->setCurrentWidget(ui->page_select_turnoff) ;
    }

    else if(e >=1)
    {
        ui->btn_select_turnoff->setEnabled(true);
        ui->stackedWidget_select_btn->setCurrentWidget(ui->page_select_turnon) ;

    }
}

void menu::on_btn_gofirst_clicked() //처음으로 버튼 누르면 첫 화면으로 이동
{
    // first *firstWindow = new first(this);  // 부모를 안 주면 독립적으로 뜸
    // firstWindow->show();

    // this->close(); // 현재 menu 창 닫기
    // 방법 1. 앱 완전 재시작
    emit gohome();
}

void menu::changewindow_take()
{
    ui->stackedWidget_take->setCurrentWidget(ui->page_take);
}
void menu::changewindow_takeout()
{
    ui->stackedWidget_take->setCurrentWidget(ui->page_takeout);
}

//컵콘 옵션에서의 이전화면 버튼
void menu::on_btn_goback_optiontype_concup_clicked()
{
    //아이스크림 선택된거 지워야함.
    // 1. 아이스크림 메뉴 정보 초기화
    this->icecream_flag = 0;
    this->menusize = 0;

    // 2. 콘/컵 수량 초기화  되어있으면 삭제.
    this->cup_count = 0;
    this->con_count = 0;
    ui->lineEdit_cup_quantity->setText("0");
    ui->lineEdit_con_quantity->setText("0");

    // 3. 컵/콘 관련 UI 초기화 필요없으면 삭제.
    ui->stackedWidget_cup_btn->setCurrentWidget(ui->page_cupquantity_turnoff_btn);
    ui->stackedWidget_con_btn->setCurrentWidget(ui->page_conquantity_turnoff_btn);
    ui->stackedWidget_select_optiontype_concup->setCurrentWidget(ui->page_select_turnoff_optiontype_concup);

    // 4. 메인 화면으로 복귀
    ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu);
}


//경태님 함수
void menu::go_to_select_flavor(){
    if(select_flag == 1){
        ui->stackedWidget_main->setCurrentWidget(ui->page_main_flavor);
    }

    //컵콘 개수확인 여기서 ..
    qDebug() << "컵 카운트"<< cup_count<<"\n";
    qDebug() << "콘 카운트"<< con_count<<"\n";;

    // int con_cnt =3;
    // int cup_cnt =2;

    QString con_image = ":/image/etc/double_junior.png";
    QString cup_image = ":/image/etc/quarter.png";

    int column_concup =0 ;

    for (int i=0; i<con_count; i++){
        cart_concup * concup = new cart_concup(this,con_image );
        // concup->imagePath = con_image;
        ui->gridLayout_cupcon->addWidget(concup, 0, column_concup);
        ui->gridLayout_cupcon->setAlignment(Qt::AlignLeft);
        column_concup++;

    }

    for (int j=0; j<cup_count; j++){
        cart_concup * concup1 = new cart_concup(this, cup_image);
        // concup1->imagePath = cup_image;
        ui->gridLayout_cupcon->addWidget(concup1, 0, column_concup);
        ui->gridLayout_cupcon->setAlignment(Qt::AlignLeft);
        column_concup++;
    }
}

void menu::go_to_select_menu(){


    int last_index_of_cart = btn_cart.size()-1;
    //위젯에서 삭제
    ui->gridLayout_menu_cart->removeWidget(btn_cart[last_index_of_cart]);
    //위젯 리스트에서 삭제
    delete btn_cart[last_index_of_cart];
    //배열에서 삭제
    btn_cart.removeLast();
    // qDebug()<<"60line"<< last_index_of_cart ;
    add_menu_name.removeAt(last_index_of_cart); // 중복검사 메뉴 이름도 빼줍니당
    e--;  // 버튼 수 감소 e.0
    ui->stackedWidget_main->setCurrentWidget(ui->page_main_menu);
}


menu::~menu()
{
    delete ui;
}
