#include <string.h>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class String
{
public:
    String()
    : _pstr(new char[1]())
    {
        cout << "String()" << endl;
    }

    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(const String &rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    //rvalue reference
    //String s3 = String("hello")
    //移动构造函数
    String(String &&rhs)
    : _pstr(rhs._pstr)
    {
        cout << "String(String &&)" << endl;
        rhs._pstr = nullptr;
    }

    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if (this != &rhs)
        {
             delete [] _pstr;
             _pstr = nullptr;

             _pstr = new char[strlen(rhs._pstr) + 1]();
             strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    //s3 = String("hefei");
    //移动赋值运算符函数
    String &operator=(String &&rhs)
    {
        cout << "String &operator=(String &&)" << endl;
        if (this != &rhs)
        {
            delete [] _pstr;
            _pstr = nullptr;

            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
            return *this;
        }
    }

    ~String()
    {
        cout << "~String()" << endl;
        if (_pstr)
        {
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
    char *_pstr;
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    os << rhs._pstr;
    return os;
}

void test()
{
    vector<String> vec;
    vec.push_back("hello");

    cout << "vec[0] = " << vec[0] << endl;

    cout << endl;
    String s3 = String("world");
    cout << "s3 = " << s3 << endl;

    cout << endl;
    s3 = String("hefei");
    cout << "s3 = " << s3 << endl;

    cout << endl;
    s3 = std::move(vec[0]);
    cout << "s3 = " << s3 << endl;

    cout << endl;
    String s1 = "HelloWorld";

    cout << endl;
    s1 = std::move(s1);
    /* s3 = std::move(s1); */
    /* std::move(s1); */
    cout << "s1 = " << s1 << endl;
}

int main()
{
    test();

    return 0;
}

