#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::vector;

void print(int number)
{
    cout << number << " ";
}

void test()
{
    vector<int> numbers{1, 5, 2, 4, 9, 7, 3};
    for_each(numbers.begin(), numbers.end(), print);
    cout << endl;

    //匿名函数 lambda表达式
    for_each(numbers.begin(), numbers.end(), [](int number){
             cout << number << " ";
             });
    cout << endl;
}

void test2()
{
    vector<int> numbers{1, 5, 2, 4, 9, 7, 3, 2};
    for_each(numbers.begin(), numbers.end(), [](int number){
             cout << number << " ";
             });
    cout << endl;
    
    cout << endl;
    int ret = std::count(numbers.begin(), numbers.end(), 0);
    cout << "ret = " << ret << endl;

    cout << endl;
    auto iter = std::find(numbers.begin(), numbers.end(), 7);
    cout << "*iter = " << *iter << endl;

    cout << endl;
    std::sort(numbers.begin(), numbers.end());
    bool flag = std::binary_search(numbers.begin(), numbers.end(), 0);
    cout << "flag = " << flag << endl;
}

int main()
{
    test2();

    return 0;
}

