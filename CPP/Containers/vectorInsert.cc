#include <iostream>
#include <vector>
#include <deque>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

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
    /* vector<int> numbers(arr, arr+10); */
    vector<int> numbers{1, 4, 3, 2, 5, 8, 7, 9};

    display(numbers);
    cout << "numbers.size() = " << numbers.size() << endl
        << "numbers.capacity() = " << numbers.capacity() << endl;

    //push_back时，当size==capacity，可以进行两倍扩容，而insert每次插入的元素个数
    //是不一定的，所以不能完全按照两倍进行扩容
    
    //假设 capacity = n, size = t, 插入元素个数 = m
    //1. m + t < n，不用扩容
    //2. m + t > n && m < t，此时扩容按照两倍的t进行扩容
    //3. m + t > n && t < m < n，此时扩容按照t + m进行扩容
    //4. m + t > n && m > n，此时按照t + m进行扩容
    cout << "push_back" << endl;
    numbers.push_back(10);
    numbers.push_back(20);
    cout << "numbers.size() = " << numbers.size() << endl
        << "numbers.capacity() = " << numbers.capacity() << endl;
    display(numbers);
    numbers.pop_back();
    display(numbers);
    cout << "numbers.size() = " << numbers.size() << endl
        << "numbers.capacity() = " << numbers.capacity() << endl;

    cout << endl;
    auto iter = numbers.begin();
    ++iter;
    ++iter;
    cout << "*iter = " << *iter << endl;
    cout << "insert" << endl;

    //case 1
    numbers.insert(iter, 11);
    display(numbers);
    cout << "numbers.size() = " << numbers.size() << endl
        << "numbers.capacity() = " << numbers.capacity() << endl;

    //case 2
    /* numbers.insert(iter, 8, 22); */
    /* display(numbers); */
    /* cout << "numbers.size() = " << numbers.size() << endl */
    /*     << "numbers.capacity() = " << numbers.capacity() << endl; */

    //case 3
    /* numbers.insert(iter, 12, 33); */
    /* display(numbers); */
    /* cout << "numbers.size() = " << numbers.size() << endl */
    /*     << "numbers.capacity() = " << numbers.capacity() << endl; */

    //case 4
    numbers.insert(iter, 20, 44);
    display(numbers);
    cout << "numbers.size() = " << numbers.size() << endl
        << "numbers.capacity() = " << numbers.capacity() << endl;
}


int main()
{
    test();

    return 0;
}

