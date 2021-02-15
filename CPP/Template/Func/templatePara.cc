#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//模板的参数类型：类型参数  非类型参数(常量表达式/整型)
template <class T, short kMin = 10>
T multiply(T x, T y)
{
    return x * y * kMin;
}

int main()
{
    int ia = 3, ib = 4;
    double da = 3.3, db = 4.4;

    cout << "multiply(ia, ib) = " << multiply<int>(ia, ib) << endl;
    cout << "multiply(da, db) = " << multiply<double, 5>(da, db) << endl;

    return 0;
}

