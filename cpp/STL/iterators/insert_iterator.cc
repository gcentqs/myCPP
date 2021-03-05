#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::istream_iterator;
using std::back_inserter;
using std::back_insert_iterator;
using std::front_inserter;
using std::front_insert_iterator;
using std::inserter;
using std::insert_iterator;
using std::vector;
using std::list;
using std::copy;
using std::set;

void test()
{
    vector<int> numbers1{1, 3, 7};
    list<int> numbers2{22, 33, 44};

    /* copy(numbers2.begin(), numbers2.end(), back_inserter(numbers1)); */
    //底层调用push_back
    copy(numbers2.begin(), numbers2.end(), back_insert_iterator<vector<int>>(numbers1));
    copy(numbers1.begin(), numbers1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //底层调用push_front
    copy(numbers2.begin(), numbers2.end(), back_insert_iterator<vector<int>>(numbers1));
    copy(numbers1.begin(), numbers1.end(), front_insert_iterator<list<int>>(numbers2));
    copy(numbers2.begin(), numbers2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    set<int> numbers3{143, 231, 645};
    set<int>::iterator iter = numbers3.begin();
    //底层调用insert
    copy(numbers1.begin(), numbers1.end(), insert_iterator<set<int>>(numbers3, iter));
    copy(numbers3.begin(), numbers3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    test();

    return 0;
}

