#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::copy;

void test()
{
    vector<int> numbers{3, 2, 8, 7, 1};
    ostream_iterator<int> osi(cout, "\n");

    copy(numbers.begin(), numbers.end(), osi);
}

int main()
{
    test();

    return 0;
}

