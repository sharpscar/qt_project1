#ifndef OPTION_H
#define OPTION_H
#include <QString>


class Option
{
public:
    Option();


    QString name;
    QString category;
    int price;
    int order_detail_id;       //주문 상세 아이디는 sql로 마지막 order_detail_id를 가져올수 있다.
    int quentity;

    // setter 함수들
    void setName(QString name_);
    void setCategory(QString category_);
    void setPrice(int price_);
    void setOrder_detail_id(int order_detail_id_);
    void setQuentity(int quentity_);

    QString getName();
    QString getCategory();
    int getPrice();
    int getOrder_detail_id();
    int getQuentity();
};

#endif // OPTION_H



