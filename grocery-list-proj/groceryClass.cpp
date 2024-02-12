#include "grocery.h"
#include <iostream>
using namespace std;

GroceryItem::GroceryItem() : name(""), price(0.0) {}

GroceryItem::GroceryItem(const string &name, double price) : name(name), price(price) {}

string GroceryItem::getName() const
{
    return name;
}

double GroceryItem::getPrice() const
{
    return price;
}

void GroceryItem::setName(const string &name)
{
    this->name = name;
}

void GroceryItem::setPrice(double price)
{
    this->price = price;
}

ostream &operator<<(ostream &os, const GroceryItem &item)
{
    os << "Name: " << item.name << ", Price: $" << item.price;
    return os;
}
