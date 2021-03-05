#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class Vector
{
public:
    typedef T * iterator;
    typedef T value_type;

    Vector()
    : _start(nullptr)
    , _finish(nullptr)
    , _end_of_storage(nullptr)
    {

    }

    ~Vector();

    void push_back(const T &value);
    void pop_back();

    iterator begin()
    {
        return _start;
    }

    iterator end()
    {
        return _finish;
    }

    int size()
    {
        return _finish - _start;
    }

    int capacity()
    {
        return _end_of_storage - _start;
    }

private:
    void reallocate();
private:
    static std::allocator<T> _alloc;

    T *_start;
    T *_finish;
    T *_end_of_storage;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::~Vector()
{
    if (_start)
    {
        while (_finish != _start)
        {
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start, capacity());
    }
}

template <typename T>
void Vector<T>::push_back(const T &value)
{
    if (size() == capacity())
    {
        reallocate();
    }
    if (size() < capacity())
    {
        _alloc.construct(_finish++, value);
    }
}

template <typename T>
void Vector<T>::pop_back()
{
    if (size() > 0)
    {
        _alloc.destroy(--_finish);
    }
}

template <typename T>
void Vector<T>::reallocate()
{
    int old_capacity = capacity();
    int new_capacity = old_capacity > 0 ? 2 * old_capacity : 1;

    T *ptmp = _alloc.allocate(new_capacity);
    if (_start)
    {
        /* std::copy(_start, _finish, ptmp); */
        std::uninitialized_copy(_start, _finish, ptmp);
        while (_finish != _start)
        {
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start, old_capacity);
    }

    _start = ptmp;
    _finish = _start + old_capacity;
    _end_of_storage = _start + new_capacity;
}

template <typename Container>
void printVectorSize(Container &vec)
{
    cout << "vec.size() = " << vec.size() << endl;
    cout << "vec.capacity() = " << vec.capacity() << endl;
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
    
    ~Point()
    {
        cout << "~Point()" << endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);

private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix << ", " << rhs._iy << ")";
    return os;
}

void test()
{
    Vector<int> numbers;
    printVectorSize(numbers);

    cout << endl;
    numbers.push_back(1);
    printVectorSize(numbers);

    cout << endl;
    numbers.push_back(7);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(5);
    numbers.push_back(1);
    printVectorSize(numbers);

    cout << endl;
    for (auto &elem : numbers)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test2()
{
    Vector<Point> numbers;
    printVectorSize(numbers);

    cout << endl;
    numbers.push_back(Point(1, 2));
    printVectorSize(numbers);

    cout << endl;
    numbers.push_back(Point(1, -2));
    numbers.push_back(Point(3, 0));
    numbers.push_back(Point(3, 4));
    numbers.push_back(Point(8, 2));
    numbers.push_back(Point(11, 22));
    printVectorSize(numbers);

    cout << endl;
    for (auto &elem : numbers)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    test2();

    return 0;
}

