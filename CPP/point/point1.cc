#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    Point &operator=(const Point &rhs)
    {
        _ix = rhs._ix;
        _iy = rhs._iy;
        cout << "Point &operator=(const Point &)" << endl;
    }

    operator int()
    {
        return _ix + _iy;
    }

    /* operator double() */
    /* { */
    /*     if (0 == _iy) */
    /*     { */
    /*         return 0; */
    /*     } */
    /*     else */
    /*     { */
    /*         return static_cast<double>(_ix) / _iy; */
    /*     } */
    /* } */

    ~Point()
    {
        cout << "~Point()" << endl;
    }

private:
    int _ix;
    int _iy;
};

void test()
{
    Point pt1(1, 2);
    cout << "pt1 = " << pt1 << endl;

    /* pt2 = pt1; */
    /* pt2 = com1; */

    /* cout << endl; */
    /* int ix = pt1; */
    /* cout << "ix = " << ix << endl; */

    /* cout << endl; */
    /* double dx = pt1; */
    /* cout << "dx = " << dx << endl; */

}

int main()
{
    test();

    return 0;
}

