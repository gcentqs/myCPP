#include <iostream>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::reverse_iterator;

void test()
{
    vector<int> numbers{1, 4, 7, 9, 6, 2};
    /* vector<int>::iterator iter; */
    /* vector<int>::const_iterator citer; */
    vector<int>::reverse_iterator riter = numbers.rbegin();
    for (; riter != numbers.rend(); ++riter)
    {
        cout << *riter << " ";
    }
    cout << endl;
}

int main()
{
    test();

    return 0;
}

