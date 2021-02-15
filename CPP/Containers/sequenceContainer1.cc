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

void test()
{
    //初始化
    /* vector<int> numbers(10, 2); */

    /* int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 3}; */
    /* vector<int> numbers(arr, arr+10); */

    vector<int> numbers{1, 4, 3, 2, 5, 8, 7, 9};

    //遍历
    /* for (size_t idx = 0; idx != numbers.size(); ++idx) */
    /* { */
    /*     cout << numbers[idx] << " "; */
    /* } */
    /* cout << endl; */

    /* vector<int>::iterator iter; */
    /* for (iter = numbers.begin(); iter != numbers.end(); ++iter) */
    /* { */
    /*     cout << *iter << " "; */
    /* } */
    /* cout << endl; */

    /* auto iter = numbers.begin(); */

    for (auto &elem : numbers)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test2()
{
    /* deque<int> numbers(10, 3); */

    /* int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 3}; */
    /* deque<int> numbers(arr, arr+10); */

    deque<int> numbers{1, 3, 5, 7, 9, 2, 4, 6, 8, 3};

    for (size_t idx = 0; idx != numbers.size(); ++idx)
    {
        cout << numbers[idx] << " ";
    }
    cout << endl;

    for (deque<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    for (auto &elem : numbers)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test3()
{
    list<int> numbers(10, 4);

    /* int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 3}; */
    /* list<int> numbers(arr, arr+10); */

    /* list<int> numbers{1, 3, 5, 7, 9, 2, 4, 6, 8, 3}; */

    //list 不支持下标访问
    /* for (size_t idx = 0; idx != numbers.size(); ++idx) */
    /* { */
    /*     cout << numbers[idx] << " "; */
    /* } */
    /* cout << endl; */

    for (list<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    for (auto &elem : numbers)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    test3();

    return 0;
}

