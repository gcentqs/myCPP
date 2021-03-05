#include <limits>
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

    friend Complex operator+(const Complex &lhs, const Complex &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);
    friend std::istream &operator>>(std::istream &is, Complex &rhs);

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

std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
    if (0 == rhs._dreal && 0 == rhs._dimage)
    {
        os << 0 << endl;
    }
    else if (0 == rhs._dreal)
    {
        os << rhs._dimage << "i" << endl;
    }
    else
    {
        os << rhs._dreal;
        if (rhs._dimage > 0)
        {
            os << "+" << rhs._dimage << "i" << endl;
        }
        else if (rhs._dimage < 0)
        {
            os << "-" << -rhs._dimage << "i" << endl;
        }
        else
        {
            os << endl;
        }
    }
    return os;

}

void read(std::istream &is, double &rhs)
{
    while (is >> rhs, !is.eof())
    {
        if (is.bad())
        {
            std::cerr << "istream is bad" << endl;
        }
        else if (is.fail())
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "please enter a double data" << endl;
        }
        else
        {
            cout << "rhs = " << rhs << endl;
            break;
        }
    }
}

std::istream &operator>>(std::istream &is, Complex &rhs)
{
    read(is, rhs._dreal);
    read(is, rhs._dimage);
    return is;
}

void test()
{
    Complex com1(1, 2);
    cout << "com1 = " << com1;

    cout << endl;
    Complex com2(3, 4);
    cout << "com2 = " << com2;

    /* Complex com3 = com1 + com2; */
    /* com3.print(); */
    com1 += com2;
    cout << "com1 = " << com1;

    cin >> com2; 
    cout << "com2 = " << com2;
}

int main()
{
    test();

    return 0;
}

