#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Complex
{
public:
    Complex(double dreal = 0, double dimage = 0)
    : _dreal(dreal)
    , _dimage(dimage)
    {
        cout << "Complex(double = 0, double = 0)" << endl;
    }
    
    Complex(const Complex &rhs)
    : _dreal(rhs._dreal)
    , _dimage(rhs._dimage)
    {
        cout << "Complex(const Complex &)" << endl;
    }

    Complex operator++(int)
    {
        cout << "Complex operator++(int)" << endl;
        Complex tmp(*this);
        ++_dreal;
        ++_dimage;
        return tmp;
    }

    void print() const
    {
        /* cout << _dreal << "+" << _dimage << "i" << endl; */
        if (0 == _dreal && 0 == _dimage)
        {
            cout << 0 << endl;
        }
        else if (0 == _dreal)
        {
            cout << _dimage << "i" << endl;
        }
        else
        {
            cout << _dreal;
            if (_dimage > 0)
            {
                cout << "+" << _dimage << "i" << endl;
            }
            else if (_dimage < 0)
            {
                cout << "-" << -_dimage << "i" << endl;
            }
            else
            {
                cout << endl;
            }
        }
    }

    double getDreal() const
    {
        return _dreal;
    }

    double getDimage() const
    {
        return _dimage;
    }

    Complex operator+=(const Complex &rhs)
    {
        cout << "Complex operator+=(const Complex &)" << endl;
        _dreal += rhs._dreal;
        _dimage += rhs._dimage;
        return *this;
    }

    Complex &operator=(const Complex &rhs)
    {
        cout << "Complex operator=(const Complex &)" << endl;
        return *this;
    }

    Complex &operator++()
    {
        cout << "Complex &operator++" << endl;
        ++_dreal;
        ++_dimage;
        return *this;
    }

    friend Complex operator+(const Complex &lhs, const Complex &rhs);

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
    return Complex(lhs._dreal + rhs._dreal,
                   lhs._dimage + rhs._dimage);
}

void test()
{
    Complex com1(1, 2);
    cout << "com1 = ";
    com1.print();

    cout << endl;
    Complex com2(3, 4);
    cout << "com2 = ";
    com2.print();

    /* Complex com3 = com1 + com2; */
    /* com3.print(); */
    /* com1 += com2; */
    /* cout << "com1 = "; */
    /* com1.print(); */

    cout << "++com1 = ";
    (++com1).print();
    cout << "com1 = ";
    com1.print();

    cout << "com1++ = ";
    (com1++).print();
    cout << "com1 = ";
    com1.print();
}

int main()
{
    test();

    return 0;
}

