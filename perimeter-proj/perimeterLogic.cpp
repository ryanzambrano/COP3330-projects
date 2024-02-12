#include "perimeter.h"
#include <iostream>
#include <cmath>
using namespace std;

Square::Square()
{
    sideSize = 5;
};
Square::Square(double size)
{
    sideSize = size;
};

Circle::Circle()
{
    radius = 5;
};

Circle::Circle(double size)
{
    radius = size;
};

Triangle::Triangle()
{
    baseSize = 5;
    rightSize = 10;
    leftSize = 10;
};

Triangle::Triangle(double base, double right, double left)
{
    baseSize = base;
    rightSize = right;
    leftSize = left;
};

double Square::GetPerimeter() const
{
    return 4 * sideSize;
}

double Square::GetArea() const
{
    return sideSize * sideSize;
}

double Triangle::GetPerimeter() const
{
    return baseSize + rightSize + leftSize;
}

double Triangle::GetArea() const
{
    double s = (baseSize + rightSize + leftSize) / 2;
    return sqrt(s * (s - baseSize) * (s - rightSize) * (s - leftSize));
}

double Circle::GetPerimeter() const
{
    return 2 * M_PI * radius;
}

double Circle::GetArea() const
{
    return M_PI * radius * radius;
}

Shape::~Shape() {}