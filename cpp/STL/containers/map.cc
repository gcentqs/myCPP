#include <math.h>
#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

template <typename Container>
void display(Container &con)
{
    for (auto &elem : con)
    {
        cout << elem.first << ":" << elem.second << endl;
    }
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

    ~Point()
    {
        /* cout << "~Point()" << endl; */
    }
    
    friend bool operator<(const Point &lhs, const Point &rhs);
    friend bool operator>(const Point &lhs, const Point &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
    friend struct PointCompare;

private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    cout << "(" << rhs._ix << ", " << rhs._iy << ")";
    return os;
}

bool operator<(const Point &lhs, const Point &rhs)
{
    cout << "bool operator<(const Point &, const Point &)" << endl;
    if (lhs.distance() < rhs.distance())
    {
        return true;
    }
    else if (lhs.distance() == rhs.distance())
    {
        return (lhs._ix < rhs._ix) || (lhs._iy < rhs._iy);
    }
    else
    {
        return false;
    }
}

bool operator>(const Point &lhs, const Point &rhs)
{
    cout << "bool operator>(const Point &, const Point &)" << endl;
    if (lhs.distance() > rhs.distance())
    {
        return true;
    }
    else if (lhs.distance() == rhs.distance())
    {
        return (lhs._ix > rhs._ix) || (lhs._iy > rhs._iy);
    }
    else
    {
        return false;
    }
    
}


struct PointCompare
{
    bool operator()(const Point &lhs, const Point &rhs)
    {
        cout << "bool PointCompare::operator()(const Point &, const Point &)" << endl;
        if (lhs.distance() < rhs.distance())
        {
            return true;
        }
        else if (lhs.distance() == rhs.distance())
        {
            return (lhs._ix < rhs._ix) || (lhs._iy < rhs._iy);
        }
        else
        {
            return false;
        }
    }
};

void test()
{
    /* map<int, string, std::less<int>> numbers */
    map<int, string, std::greater<int>> numbers
    {
        {2, "shanghai"},
        std::pair<int, string>(4, "shenzhen"),
        std::make_pair(6, "hefei"),
        std::make_pair(5, "nanjing"),
        {1, "beijing"},
        std::pair<int, string>(3, "guangzhou"),
        std::make_pair(3, "xinjiang"),
    };

    display(numbers);

    cout << numbers[1] << endl;
    cout << numbers[10] << endl;
    display(numbers);
    cout << endl;
    numbers[10] = "wuhan";
    display(numbers);
}

void test2()
{
    map<string, Point> numbers
    {
        {"1", Point(1, 2)},
        std::make_pair("4444", Point(3, 4)),
        {"22", Point(1, -2)},
        std::make_pair("55555", Point(8, 2)),
        std::pair<string, Point>("333", Point(3, 0)),
    };

    display(numbers);

    cout << endl << "map查找" << endl;
    size_t cnt1 = numbers.count("1");
    size_t cnt2 = numbers.count("2");
    cout << "cnt1 = " << cnt1 << endl;
    cout << "cnt2 = " << cnt2 << endl;

    cout << "numbers[\"1\"] = " << numbers["1"] << endl;
}

int main()
{
    test2();

    return 0;
}

