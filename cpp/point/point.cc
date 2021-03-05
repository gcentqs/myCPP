#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Point;

class Complex
{
    friend class Point;
    
public:
    Complex(double dreal = 0, double dimage = 0)
    : _dreal(dreal)
    , _dimage(dimage)
    {
        cout << "Complex(double = 0, double = 0)" << endl;
    }

    void print() const
    {
        cout << _dreal << "+" << _dimage << "i" << endl;
    }

    double getDreal() const
    {
        return _dreal;
    }

    double getDimage() const
    {
        return _dimage;
    }

    ~Complex()
    {
        cout << "~Complex()" << endl;
    }

private:
    double _dreal;
    double _dimage;
};

Complex operator+(const Complex &lhs, const Complex &rhs)
{
    return Complex(lhs.getDreal() + rhs.getDreal(),
                   lhs.getDimage() + rhs.getDimage());
}

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    Point(const Complex &rhs)
    : _ix(rhs._dreal)
    , _iy(rhs._dimage)
    {
        cout << "Point(const Complex &)" << endl;
    }


    Point(const Point &rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
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

    operator double()
    {
        if (0 == _iy)
        {
            return 0;
        }
        else
        {
            return static_cast<double>(_ix) / _iy;
        }
    }

    operator Complex()
    {
        return Complex(_ix, _iy);
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);

private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix << ", " << rhs._iy << ")";

    return os;
}

void test()
{
    Point pt1(1, 2);
    cout << "pt1 = " << pt1 << endl;
    Point pt2{2, 3};

    Complex com1(10, 20);
    Point pt2 = com1;
    /* Point pt2(com1); */
    /* pt2 = pt1; */
    /* pt2 = com1; */
    cout << "pt2 = " << pt2 << endl;

    /* cout << endl; */
    /* int ix = pt1; */
    /* cout << "ix = " << ix << endl; */

    /* cout << endl; */
    /* double dx = pt1; */
    /* cout << "dx = " << dx << endl; */

    /* cout << endl; */
    /* Complex com2 = pt1; */
    /* cout << "com2 = "; */
    /* com2.print(); */
}

int main()
{
    test();

    return 0;
}

