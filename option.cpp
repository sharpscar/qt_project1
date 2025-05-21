#include "option.h"

Option::Option() {


}




void Option::setName(QString name_){
    name = name_;
}

void Option::setCategory(QString category_){
    category= category_;
}


void Option::setPrice(int price_){
    price = price_;
}


void Option::setOrder_detail_id(int order_detail_id_){
    order_detail_id = order_detail_id_;
}


void Option::setQuantity(int quantity_){
    quantity = quantity_;
}

void Option::add_flavor(int menu_id)
{
    flav_data.append(menu_id);
}

QVector<int> Option::get_flav_data()
{
    return flav_data;
}

QString Option::getName(){
    return name;
}

QString Option::getCategory(){
    return category;
}

int Option::getPrice(){
    return price;
}

int Option::getOrder_detail_id(){
    return order_detail_id;
}

int Option::getQuantity(){
    return quantity;
}
\



