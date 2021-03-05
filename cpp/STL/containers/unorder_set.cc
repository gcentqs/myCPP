#include <math.h>
#include <iostream>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_set;

template <typename Container>
void display(const Container &con)
{
    for (auto &elem : con)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test()
{
    unordered_set<int> numbers{3, 1, 2, 7, 5, 4, 2, 1, 8};
    display(numbers);
}

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    double distance() const
    {
        return hypot(_ix, _iy);
    }

    int getIx() const 
    {
        return _ix;
    }

    int getIy() const 
    {
        return _iy;
    }

    ~Point()
    {
        /* cout << "~Point()" << endl; */
    }
    
    /* friend bool operator<(const Point &lhs, const Point &rhs); */
    /* friend bool operator>(const Point &lhs, const Point &rhs); */
    /* friend struct PointCompare; */
    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);

private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    cout << "(" << rhs._ix << ", " << rhs._iy << ")";
    return os;
}

namespace std
{
template <>
struct hash<Point>
{
    size_t operator()(const Point &rhs) const
    {
        cout << "struct hash::operator()(const Point &) const" << endl;
        return (rhs.getIx() << 1) ^ (rhs.getIy() << 1);
    }
};
}

bool operator==(const Point &lhs, const Point &rhs)
{
    cout << "bool operator==(const Point &, const Point &)" << endl;
    return (lhs.getIx() == rhs.getIx() && lhs.getIy() == rhs.getIy());
}

void test2()
{
    /* unordered_set<Point> numbers */
    unordered_set<Point, std::hash<Point>, std::equal_to<Point>> numbers
    {
        Point(1, 2),
        Point(1, -2),
        Point(3, 0),
        Point(3, 4),
        Point(7, 2),
        Point(8, 0),
        Point(1, 2),
    };

    display(numbers);
}

int main()
{
    test2();

    return 0;
}

