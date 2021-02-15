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

    void print()
    {
        cout << "(" << _ix << ", " << _iy << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }

private:
    int _ix;
    int _iy;
};


template <class T>
class RAII
{
public:
    //在构造函数中托管资源
    RAII(T *data)
    : _data(data)
    {
        cout << "RAII(T *)" << endl;
    }

    //提供若干访问资源的方法
    T *operator->()
    {
        return _data;
    }

    T &operator*()
    {
        return *_data;
    }

    T *get()
    {
        return _data;
    }

    void reset(T *data = nullptr)
    {
        if (_data)
        {
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }

    //不允许复制或赋值
    RAII(const RAII &rhs) = delete;
    RAII &operator=(const RAII &rhs) = delete;

    //在析构函数中释放资源
    ~RAII()
    {
        cout << "~RAII()" << endl;
        if (_data)
        {
            delete _data;
            _data = nullptr;
        }
    }
    
private:
    T *_data;
};

void test()
{
    RAII<Point> ppt(new Point(1, 2));
    ppt->print();
    /* ppt.operator->()->print(); */

    /* RAII<Point> ppt2(ppt); */
    RAII<Point> ppt3(new Point(3, 4));
    /* ppt3 = ppt; */
}

int main()
{
    test();

    return 0;
}

