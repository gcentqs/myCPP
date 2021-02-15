#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

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
    int *pt = new int(10);
    unique_ptr<int> up(pt);
    cout << "*up = " << *up << endl
        << "pt = " << pt << endl
        << "up.get() = " << up.get() << endl;

    /* unique_ptr<int> up2(up); */  //error，禁止拷贝或赋值

    //具有移动语义
    unique_ptr<int> up3(std::move(up));

    cout << endl;
    unique_ptr<Point> up4(new Point(1, 2));
    vector<unique_ptr<Point>> numbers;
    numbers.push_back(unique_ptr<Point>(new Point(10, 20)));
    numbers.push_back(std::move(up4));
}

int main()
{
    test();

    return 0;
}

