#ifndef PERIMETER_H
#define PERIMETER_H

#include <string>
#include <iostream>
using namespace std;

class Shape
{
private:
public:
    virtual double GetPerimeter() const = 0;
    virtual double GetArea() const = 0;
    virtual ~Shape();
};
class Square : public Shape
{
private:
    double sideSize;

public:
    Square();
    Square(double sideSize);
    double GetPerimeter() const override;

    double GetArea() const override;
};

class Triangle : public Shape
{
private:
    double baseSize;
    double rightSize;
    double leftSize;

public:
    Triangle();
    Triangle(double baseSize, double rightSize, double leftSize);
    double GetPerimeter() const override;

    double GetArea() const override;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle();
    Circle(double radius);
    double GetPerimeter() const;
    double GetArea() const;
};

#endif