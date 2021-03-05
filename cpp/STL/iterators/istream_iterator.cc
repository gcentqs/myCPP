#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;
using std::copy;

void test()
{
    vector<int> numbers;
    istream_iterator<int> isi(cin);
    /* copy(isi, istream_iterator<int>(), numbers.begin()); */
    copy(isi, istream_iterator<int>(), std::back_inserter(numbers));
    
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, "\n"));
}

int main()
{
    test();

    return 0;
}

