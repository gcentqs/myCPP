#include <string.h>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

            //通过类型推导(在实参传递的时候)
//函数模板 <================================> 模板函数
            //实例化
/* template <typename T> */
template <class T>
T add(T x, T y)
{
    return x + y;
}

//函数模板可以和函数模板进行重载
template <class T>
T add(T x, T y, T z)
{
    return x + y + z;
}

#if 0
//普通函数优先于函数模板执行
//普通函数可以和函数模板进行重载
int add(int x, int y)
{
    return x + y;
}
#endif

#if 1
//模板的特殊化：全特化、偏特化
template <>
const char *add(const char * pstr1, const char * pstr2)
{
    size_t len = strlen(pstr1) + strlen(pstr2);
    char *tmp = new char[len]();

    strcpy(tmp, pstr1);
    strcat(tmp, pstr2);
    return tmp;
}
#endif

void test()
{
    int ia = 3;
    int ib = 4;
    double da = 3.3;
    double db = 4.4;
    char ca = 'a';
    char cb = 2;
    string s1 = "hello";
    string s2 = "world";

    cout << "add(ia, ib) = " << add(ia, ib) << endl;//隐式实例化
    /* cout << "add(da, db) = " << add(da, db) << endl; */
    cout << "add(da, db) = " << add<double>(da, db) << endl;//显式实例化
    cout << "add(ca, cb) = " << add(ca, cb) << endl;
    cout << "add(s1, s2) = " << add(s1, s2) << endl;

    const char *pstr1 = "hefei";
    const char *pstr2 = "anhui";

    cout << "add(pstr1, pstr2) = " << add(pstr1, pstr2) << endl;
}

int main()
{
    test();

    return 0;
}

