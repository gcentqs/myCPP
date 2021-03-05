#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
    Point(double dx = 0, double dy = 0)
    : _dx(dx)
    , _dy(dy)
    {
        cout << "Point(double = 0, double = 0)" << endl;
    }

    template <class T = int>
    T print()
    {
        return (T)_dx;
    }

private:
    double _dx;
    double _dy;
};

int main()
{
    Point pt(11.11, 22.22);
    cout << "pt.print() = " << pt.print<int>() << endl;
    cout << "pt.print() = " << pt.print<double>() << endl;

    return 0;
}

