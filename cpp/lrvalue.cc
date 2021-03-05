#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void test()
{
    int a = 3;
    int b = 4;

    int &&rref = 10; 
}

void test2()
{
    int number1 = 10;
    int number2 = 20;
    std::move(number1);
    cout << "number1 = " << number1 << endl
        << "number2 = " << number2 << endl;
}

int main()
{
    test2();

    return 0;
}

