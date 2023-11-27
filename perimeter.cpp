#include <iostream>
#include <memory>
#include "perimeter.h"
using namespace std;

int main()
{
    Shape **shapes = nullptr;
    int shapeCount = 0;
    int capacity = 0;
    char choice;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Add a Square\n";
        cout << "2. Add a Circle\n";
        cout << "3. Add a Triangle\n";
        cout << "4. Calculate total perimeter and area of all shapes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (as a number): ";
        cin >> choice;

        if (choice == '5')
        {
            break;
        }

        if (shapeCount >= capacity)
        {
            capacity = capacity == 0 ? 1 : capacity * 2;
            Shape **newArray = new Shape *[capacity];

            for (int i = 0; i < shapeCount; ++i)
            {
                newArray[i] = shapes[i];
            }

            delete[] shapes;
            shapes = newArray;
        }

        switch (choice)
        {
        case '1':
        {
            double side;
            cout << "Enter side length of the square: ";
            cin >> side;
            shapes[shapeCount++] = new Square(side);
            break;
        }
        case '2':
        {
            double radius;
            cout << "Enter radius of the circle: ";
            cin >> radius;
            shapes[shapeCount++] = new Circle(radius);
            break;
        }
        case '3':
        {
            double base, right, left;
            cout << "Enter base, right side, and left side of the triangle\n";
            cout << "base: ";
            cin >> base;
            cout << "right: ";
            cin >> right;
            cout << "left: ";
            cin >> left;

            shapes[shapeCount++] = new Triangle(base, right, left);
            break;
        }
        case '4':
        {
            double totalPerimeter = 0, totalArea = 0;
            for (int i = 0; i < shapeCount; ++i)
            {
                totalPerimeter += shapes[i]->GetPerimeter();
                totalArea += shapes[i]->GetArea();
            }
            cout << "Total Perimeter: " << totalPerimeter << "\n";
            cout << "Total Area: " << totalArea << "\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    for (int i = 0; i < shapeCount; ++i)
    {
        delete shapes[i];
    }
    delete[] shapes;

    return 0;
}
