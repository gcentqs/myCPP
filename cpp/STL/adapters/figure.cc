#include <math.h>
#include <iostream>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::bind;

class Figure
{
public:
    using DisplayCallback = function<void()>;
    using AreaCallback = function<double()>;

    DisplayCallback _displayCallback;
    AreaCallback _areaCallback;

    //注册回调函数
    void setDisplayCallback(function<void()> &&cb)
    {
        _displayCallback = cb;
    }

    void setAreaCallback(function<double()> &&cb)
    {
        _areaCallback = cb;
    }

    void handleDisplayCallback() const
    {
        if (_displayCallback)
        {
            _displayCallback();
        }
    }

    double handleAreaCallback() const
    {
        if (_areaCallback)
        {
            return _areaCallback();
        }
        else
        {
            return 0;
        }
    }
};

class Rectangle
{
public:
    Rectangle(double length = 0, double width = 0)
    : _length(length)
    , _width(width)
    {
        
    }

    void display() const 
    {
        cout << "Rectangle"; 
    }

    double area() const 
    {
        return _length * _width;
    }

private:
    double _length;
    double _width;
};


class Circle
{
public:
    Circle(double radius = 0)
    : _radius(radius)
    {

    }

public:
    void display() const 
    {
        cout << "Circle";
    }

    double area() const 
    {
        return _radius * _radius * 3.1415;
    }

private:
    double _radius;
};

class Triangle
{
public:
    Triangle(double a = 0, double b = 0, double c = 0)
    : _a(a)
    , _b(b)
    , _c(c)
    {

    }

public:
    void display() const 
    {
        cout << "Triangle";
    }

    double area() const 
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
    fig.handleDisplayCallback();
    cout << "'s area = " << fig.handleAreaCallback() << endl;
}

int main()
{
    Rectangle rectangle(10, 12);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

    Figure figure;
    figure.setDisplayCallback(bind(&Rectangle::display, &rectangle));
    figure.setAreaCallback(bind(&Rectangle::area, &rectangle));
    func(figure);
    /* func(rectangle); */
    /* func(circle); */
    /* func(triangle); */

    return 0;
}

