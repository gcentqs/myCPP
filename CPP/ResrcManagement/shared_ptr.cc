#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
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
    shared_ptr<int> sp(pt);
    cout << "*sp = " << *sp << endl
        << "pt = " << pt << endl
        << "sp.get() = " << sp.get() << endl
        << "sp.use_count() = " << sp.use_count() << endl;

    shared_ptr<int> sp2(sp); 
    cout << endl;
    cout << "*sp = " << *sp << endl
        << "sp.get() = " << sp.get() << endl
        << "sp.use_count() = " << sp.use_count() << endl;
    cout << endl;
    cout << "*sp2 = " << *sp2 << endl
        << "sp2.get() = " << sp2.get() << endl
        << "sp2.use_count() = " << sp2.use_count() << endl;

    cout << endl;
    shared_ptr<int> sp3(new int(100));
    cout << "*sp3 = " << *sp3 << endl
        << "sp3.get() = " << sp3.get() << endl
        << "sp3.use_count() = " << sp3.use_count() << endl;
    sp3 = sp;
    cout << endl << "*sp3 = " << *sp3 << endl
        << "sp3.get() = " << sp3.get() << endl
        << "sp3.use_count() = " << sp3.use_count() << endl;
    shared_ptr<int> sp4(std::move(sp));
    cout << endl << "*sp3 = " << *sp3 << endl
        << "sp3.get() = " << sp3.get() << endl
        << "sp3.use_count() = " << sp3.use_count() << endl;
    cout << endl << "*sp4 = " << *sp4 << endl
        << "sp4.get() = " << sp4.get() << endl
        << "sp4.use_count() = " << sp4.use_count() << endl;

    /* shared_ptr<Point> sp4(new Point(1, 2)); */
    /* vector<shared_ptr<Point>> numbers; */
    /* numbers.push_back(shared_ptr<Point>(new Point(10, 20))); */
    /* numbers.push_back(std::move(sp4)); */
}

int main()
{
    test();

    return 0;
}

