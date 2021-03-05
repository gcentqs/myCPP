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

void test()
{
    Complex com1(1, 2);
    cout << "com1 = ";
    com1.print();

    cout << endl;
    Complex com2(3, 4);
    cout << "com2 = ";
    com2.print();

    Complex com3 = com1 + com2;
    com3.print();

    Complex com4 = {10, 20};
    com4.print();
}

int main()
{
    test();

    return 0;
}

