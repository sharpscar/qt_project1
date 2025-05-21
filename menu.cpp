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
    this->type_menu_btn_control();
    this->flavor_menu_btn_control();
    // Option *opt = new Option();
}

void menu::startsetting()
{

    // opt1.setCategory("");
    // opt1.setName("해피씰");
    // opt1.setPrice(500);
    // opt1.setQuentity(1);
    option_startsetting();
    option_btn_control();
    ui->stackedWidget_main->setCurrentWidget(ui->page_option);
    ui->stackedWidget_leftmenu->setCurrentWidget(ui->page_typemenu);
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
        qDebug() << "menu_name:" << menuName << ", menu_file_path:" << menuFilePath;
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
        qDebug() << "menu_name:" << menuName << ", menu_file_path:" << menuFilePath;
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
        qDebug() << "menu_name:" << menuName << ", menu_file_path:" << menuFilePath;
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
        qDebug() << "menu_name:" << menuName << ", menu_file_path:" << menuFilePath;
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
        qDebug() << "menu_name:" << menuName << ", menu_file_path:" << menuFilePath;
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
        qDebug() << "menu_name:" << menuName << ", menu_file_path:" << menuFilePath;
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


    //모든 버튼들에게 클릭이벤트를 준다.(flavor선택 버튼1)
    for(int i=0; i<btns.size(); i++){
        connect(this->btns[i], &MenuBtn::clicked, this, [this, i](){
            flavorName = this->btns2[i]->getName();
            qDebug() << this->btns[i]->getName(); //이름이 잘 들어갔나요?
        });
    }

    //모든 버튼들에게 클릭이벤트를 준다.(menu 선택 버튼1)
    for(int i=0; i<btns2.size(); i++){
        connect(this->btns2[i], &menubtn2::clicked, this, [this, i](){
            QString menuName = this->btns2[i]->getName();
            QSqlQuery query2(this->db);

            QString sql_imgpath = "select menu_file_path from menus where menu_name = "  + menuName + "\"";
            qDebug() << sql_imgpath;

            QString img_path = query2.value(0).toString();
            qDebug() << img_path;

        });
    }
}

void menu::connectsetting()
{
    connect(ui->btn_go_home, &QPushButton::clicked, this, &menu::gohome_signalf);
}

void menu::concup_plus_minus()
{
    connect(ui->btn_cup_plus, &QPushButton::clicked, this, [this](){
        this->cup_count++;
        ui->lineEdit_cup_quantity->setText(QString::number(this->cup_count));
    });
    connect(ui->btn_cup_minus, &QPushButton::clicked, this, [this](){
        if(cup_count>0)
        {
            this->cup_count--;
        }
        ui->lineEdit_cup_quantity->setText(QString::number(this->cup_count));
    });
    connect(ui->btn_con_plus, &QPushButton::clicked, this, [this](){
        this->con_count++;
        ui->lineEdit_con_quantity->setText(QString::number(this->con_count));
    });
    connect(ui->btn_con_minus, &QPushButton::clicked, this, [this](){
        if(con_count>0)
        {
            this->con_count--;
        }
        ui->lineEdit_con_quantity->setText(QString::number(this->con_count));
    });
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
        opt1.setName("큰초");
        opt1.setQuantity(bigcandle_count); //ui->lineEdit_candle_quantity->text()
        opt1.setPrice(0);
        options.append(opt1);
        opt2.setName("작은초");
        opt2.setQuantity(smallcandle_count);
        opt2.setPrice(0);
        opt3.setName("드라이아이스");
        opt3.setQuantity(dryice_count);
        opt3.setPrice(0);
        option_startsetting();
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

void menu::changewindow_take()
{
    ui->stackedWidget_take->setCurrentWidget(ui->page_take);
}
void menu::changewindow_takeout()
{
    ui->stackedWidget_take->setCurrentWidget(ui->page_takeout);
}

menu::~menu()
{
    delete ui;
}
