#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;

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

void test()
{
    weak_ptr<Point> wp;

    {
        shared_ptr<Point> sp(new Point(1, 2));

        wp = sp;
        cout << "wp.expired() = " << wp.expired() << endl;
        shared_ptr<Point> sp2 = wp.lock();
        if (sp2)
        {
            cout << "提升成功，该对象还存在" << endl
                << "*sp2 = ";
            sp2->print();
        }
        else
        {
            cout << "提升失败，该对象已经销毁" << endl;
        }
    }
    cout << "wp.expired() = " << wp.expired() << endl;
    shared_ptr<Point> sp2 = wp.lock();
    if (sp2)
    {
        cout << "提升成功，该对象还存在" << endl
            << "*sp2 = ";
        sp2->print();
    }
    else
    {
        cout << "提升失败，该对象已经销毁" << endl;
    }
}

int main()
{
    test();

    return 0;
}

