#include <math.h>
#include <iostream>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::multiset;
using std::vector;

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
    /* int arr[10] = {1, 4, 8, 2, 3, 1, 9, 7, 6, 5}; */
    /* multiset<int> numbers(arr, arr+10); */
    
    multiset<int> numbers{1, 4, 8, 2, 3, 1, 9, 7, 6, 5};
    display(numbers);

    //multiset的查找
    size_t cnt1 = numbers.count(1);
    size_t cnt2 = numbers.count(10);
    cout << "cnt1 = " << cnt1 << endl;
    cout << "cnt2 = " << cnt2 << endl;

    /* multiset<int>::iterator iter = numbers.find(0); */
    /* if (iter == numbers.end()) */
    /* { */
    /*     cout << "该元素不存在" << endl; */
    /* } */
    /* else */
    /* { */
    /*     cout << "该元素存在 ：" << *iter << endl; */
    /* } */

    cout << endl << "insert" << endl;
    /* std::pair<multiset<int>::iterator, bool> ret = numbers.insert(1); */
    /* if (ret.second) */
    /* { */
    /*     cout << "insert success: " << *ret.first << endl; */
    /* } */
    /* else */
    /* { */
    /*     cout << "insert failed" << endl; */
    /* } */

    /* vector<int> vec{1, 2, 11, 15, 2, 4, 8, 9}; */
    /* numbers.insert(vec.begin(), vec.end()); */
    /* display(numbers); */

    cout << endl;
    numbers.insert(std::initializer_list<int>{11, 21, 41, 81});
    display(numbers);

    /* cout << endl << "erase" << endl; */
    /* auto iter = numbers.begin(); */
    /* ++iter; */
    /* ++iter; */
    /* cout << "*iter = " << *iter << endl; */
    /* numbers.erase(iter); */
    /* display(numbers); */

    /* *iter = 100; error, multiset元素不支持修改*/

    cout << endl;
    auto iter1 = numbers.lower_bound(3);
    auto iter2 = numbers.upper_bound(7);
    cout << "*iter1 = " << *iter1 << endl
        << "*iter2 = " << *iter2 << endl;
    while (iter1 != iter2)
    {
        cout << *iter1 << " ";
        ++iter1;
    }
    cout << endl;

    numbers.insert({3, 3});
    cout << "equal_range" << endl;
    std::pair<multiset<int>::iterator, multiset<int>::iterator> ret = numbers.equal_range(3);
    cout << "*ret.first = " << *ret.first << endl
        << "*ret.second = " << *ret.second << endl;
    while (ret.first != ret.second)
    {
        cout << *ret.first << " ";
        ++ret.first;
    }
    cout << endl;
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

void test2()
{
    /* multiset<Point, std::less<Point>> numbers */
    /* multiset<Point, std::greater<Point>> numbers */
    multiset<Point, PointCompare> numbers
    {
        Point(1, 2),
        Point(1, -2),
        Point(3, 4),
        Point(3, 0),
        Point(1, 2)
    };
    display(numbers);
}

int main()
{
    test();

    return 0;
}

