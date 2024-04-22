#include <iostream>
#include "grocery.h"
using namespace std;

int main()
{
    int size = 3;
    int count = 0;
    GroceryItem *groceryList = new GroceryItem[size];

    int choice;
    double total = 0.0;

    while (true)
    {
        cout << "\n\n==== Welcome to the SUPER FUN Grocery Store! ====" << endl;
        cout << "===================================================" << endl;
        cout << "=== 1. Add a YUMMY Item to Your Cart! ===" << endl;
        cout << "=== 2. Oops! Remove an Item! No worries! =" << endl;
        cout << "=== 3. Sneak a Peek into Your Cart! What's in there? ==" << endl;
        cout << "=== 4. Check Out! Show me the MONEY!" << endl;
        cout << "===================================================" << endl;
        cout << "Type the number of your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            double price;
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter item price: ";
            cin >> price;

            if (count == size)
            {
                size += 3;
                GroceryItem *temp = new GroceryItem[size];
                for (int i = 0; i < count; ++i)
                {
                    temp[i] = groceryList[i];
                }
                delete[] groceryList;
                groceryList = temp;
            }

            groceryList[count++] = GroceryItem(name, price);
        }
        else if (choice == 2)
        {
            string nameToRemove;
            cout << "Enter the name of the item to remove: ";
            cin >> nameToRemove;

            bool found = false;
            for (int i = 0; i < count; ++i)
            {
                if (groceryList[i].getName() == nameToRemove)
                {
                    found = true;
                    for (int j = i; j < count - 1; ++j)
                    {
                        groceryList[j] = groceryList[j + 1];
                    }
                    --count;
                    cout << "Item removed successfully!" << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "Item not found in the list." << endl;
            }
        }

        else if (choice == 3)
        {
            for (int i = 0; i < count; ++i)
            {
                cout << groceryList[i] << endl;
            }
        }
        else if (choice == 4)
        {
            for (int i = 0; i < count; ++i)
            {
                total += groceryList[i].getPrice();
            }
            cout << "Subtotal: $" << total << endl;
            cout << "Total with 7% tax: $" << total * 1.07 << endl;
            break;
        }
    }

    delete[] groceryList;
    return 0;
}
