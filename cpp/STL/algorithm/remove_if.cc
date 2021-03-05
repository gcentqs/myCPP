#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::remove_if;
using std::vector;
using std::ostream_iterator;
using std::copy;

bool func(int number)
{
    return number > 5;
}

void test()
{
    vector<int> numbers{2, 5, 6, 1, 3, 5, 8, 9};
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    /* auto iter = remove_if(numbers.begin(), numbers.end(), func); */
    /* auto iter = remove_if(numbers.begin(), numbers.end(), [](int number){ */
    /*                       return number > 5; */
    /*                       }); */
    /* auto iter = remove_if(numbers.begin(), numbers.end(), std::bind1st(std::less<int>(), 5)); */
    auto iter = remove_if(numbers.begin(), numbers.end(), std::bind2nd(std::greater<int>(), 5));

    numbers.erase(iter, numbers.end());
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    test();

    return 0;
}

