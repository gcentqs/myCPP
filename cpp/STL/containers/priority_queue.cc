#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;


void test()
{
    //底层实现是堆
    vector<int> numbers{3, 5, 8, 1, 3, 4, 2, 9};
    /* priority_queue<int> pque(numbers.begin(), numbers.end()); */
    priority_queue<int> pque;

    for (size_t idx = 0; idx != numbers.size(); ++idx)
    {
        pque.push(numbers[idx]);
        cout << "top priority : " << pque.top() << endl;
    }

    while (!pque.empty())
    {
        cout << pque.top() << " ";
        pque.pop();
    }

    cout << endl;
}

int main()
{
    test();

    return 0;
}

