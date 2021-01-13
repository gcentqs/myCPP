#include <math.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Figure
{
public:
    virtual
    void display() const = 0;

    virtual
    double area() const = 0;
};


class Rectangle
:public Figure
{
public:
    Rectangle(double length = 0, double width = 0)
    : _length(length)
    , _width(width)
    {
        
    }

    void display() const override
    {
        cout << "Rectangle"; 
    }

    double area() const override
    {
        return _length * _width;
    }

private:
    double _length;
    double _width;
};


class Circle
:public Figure
{
public:
    Circle(double radius = 0)
    : _radius(radius)
    {

    }

public:
    void display() const override
    {
        cout << "Circle";
    }

    double area() const override
    {
        return _radius * _radius * 3.1415;
    }

private:
    double _radius;
};

class Triangle
:public Figure
{
public:
    Triangle(double a = 0, double b = 0, double c = 0)
    : _a(a)
    , _b(b)
    , _c(c)
    {

    }

public:
    void display() const override
    {
        cout << "Triangle";
    }

    double area() const override
    {
        double tmp = (_a + _b + _c) / 2;
        return sqrt(tmp * (tmp - _a) * (tmp - _b) * (tmp - _c));
    }

private:
    double _a;
    double _b;
    double _c;
};

void func(const Figure &fig)
{
    fig.display();
    cout << "'s area = " << fig.area() << endl;
}

int main()
{
    Rectangle rectangle(10, 12);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

    func(rectangle);
    func(circle);
    func(triangle);

    return 0;
}

