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

    cout << "push_back" << endl;
    numbers.push_back(10);
    numbers.push_back(20);
    display(numbers);
    numbers.pop_back();
    display(numbers);

}

void test2()
{
    deque<int> numbers{1, 3, 5, 7, 9, 2, 4, 6, 8, 3};
    display(numbers);

    cout << "push_back" << endl;
    numbers.push_back(11);
    numbers.push_back(21);
    display(numbers);
    numbers.pop_back();
    display(numbers);

    cout << "push_front" << endl;
    numbers.push_front(100);
    numbers.push_front(1000);
    display(numbers);
    numbers.pop_front();
    display(numbers);
}

void test3()
{
    list<int> numbers{1, 3, 5, 7, 9, 2, 4, 6, 8, 3};
    display(numbers);

    cout << "push_back" << endl;
    numbers.push_back(12);
    numbers.push_back(22);
    display(numbers);
    numbers.pop_back();
    display(numbers);

    cout << "push_front" << endl;
    numbers.push_front(100);
    numbers.push_front(1000);
    display(numbers);
    numbers.pop_front();
    display(numbers);

    cout << "insert" << endl;
    auto iter = numbers.begin();
    ++iter;
    ++iter;
    cout << "*iter = " << *iter << endl;
    numbers.insert(iter, 788);
    display(numbers);
    cout << "*iter = " << *iter << endl; 

    numbers.insert(iter, 3, 44);
    display(numbers);
    cout << "*iter = " << *iter << endl; 

    cout << "insert vector" << endl;
    vector<int> vec{61, 62, 63};
    numbers.insert(iter, vec.begin(), vec.end());
    display(numbers);
    cout << "*iter = " << *iter << endl; 
}

void test4()
{
    cout << "sizeof(vector<int>) = " << sizeof(vector<int>) << endl;
    cout << "sizeof(vector<char>) = " << sizeof(vector<char>) << endl;

    vector<int> numbers{1, 4, 3, 2, 5, 8, 7, 9};
    int *p = numbers.data();
}

int main()
{
    test3();

    return 0;
}

