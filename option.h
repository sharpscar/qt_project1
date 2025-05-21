#ifndef OPTION_H
#define OPTION_H
#include <QString>
#include <QWidget>


class Option
{
public:
    Option();


    QString name;
    QString category;
    int price;
    int order_detail_id;       //주문 상세 아이디는 sql로 마지막 order_detail_id를 가져올수 있다.
    int quantity;
    QVector<int> flav_data;
    // setter 함수들
    void setName(QString name_);
    void setCategory(QString category_);
    void setPrice(int price_);
    void setOrder_detail_id(int order_detail_id_);
    void setQuantity(int quantity_);
    void add_flavor(int);

    QString getName();
    QVector<int> get_flav_data();
    QString getCategory();
    int getPrice();
    int getOrder_detail_id();
    int getQuantity();
};

#endif // OPTION_H



