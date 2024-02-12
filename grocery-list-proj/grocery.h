#include <iostream>
using namespace std;

class GroceryItem
{
private:
    string name;
    double price;

public:
    GroceryItem();
    GroceryItem(const string &name, double price);

    string getName() const;
    double getPrice() const;

    void setName(const string &name);
    void setPrice(double price);

    friend ostream &operator<<(ostream &os, const GroceryItem &item);
};
