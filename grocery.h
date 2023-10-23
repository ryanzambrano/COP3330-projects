#include <iostream>
using namespace std;

class groceryItem
{
private:
    string name;
    int price;

public:
    string getName();
    string setName();
    int getPrice();
    int setPrice();
};