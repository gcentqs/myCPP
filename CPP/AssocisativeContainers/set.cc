#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::set;

void test()
{
    /* int arr[6] = {1, 5, 2, 3, 9, 5}; */
    /* set<int> numbers(arr, arr+6); */
    set<int> numbers = {1, 5, 2, 3, 9, 5, 8, 7, 2};

    for (auto &elem : numbers)
    {
        cout << elem << " ";
    }
    cout << endl;

    /* set<int>::iterator it; */
    /* for (it = numbers.begin(); it != numbers.end(); ++it) */
    /* { */
    /*     cout << *it << " "; */
    /* } */
    /* cout << endl; */

    /* cout << numbers.count(1) << endl; */
    /* auto it = numbers.find(10); */
    /* if (it == numbers.end()) */
    /* { */
    /*     cout << "it does not exist" << endl; */
    /* } */
    /* else */
    /* { */
    /*     cout << "it does exist : " << *it << endl; */
    /* } */

    //insert
    numbers.insert(100);
    int arr[3] = {101, 99, 1000};
    numbers.insert(arr, arr+3);
    for (auto &elem : numbers)
    {
        cout << elem << " ";
    }
    cout << endl;

    /* cout << numbers[1] << endl; */
    set<int>::iterator it = numbers.begin();
    /* *it = 1000; */
}

int main()
{
    test();

    return 0;
}

