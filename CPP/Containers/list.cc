#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
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

//函数对象（仿函数）
struct CompareList
{
    bool operator()(const int &lhs, const int &rhs) const 
    {
        /* cout << "bool operator()(const int &, const int &) const" << endl; */
        return lhs < rhs;
    }
};

void test()
{
    list<int> numbers{3, 1, 7, 5, 2, 4, 9, 8, 1};
    display(numbers);

    //sort
    /* numbers.sort(std::less<int>()); */
    /* display(numbers); */
    /* numbers.sort(std::greater<int>()); */
    /* display(numbers); */
    /* numbers.sort(CompareList()); */
    /* display(numbers); */

    //reverse
    /* numbers.reverse(); */
    /* display(numbers); */

    //unique 先排序再去重
    /* numbers.sort(std::less<int>()); */
    /* numbers.unique(); */
    /* display(numbers); */

    //merge
    /* list<int> numbers2{13, 10, 18, 15, 19, 11, 13}; */
    /* numbers.sort(std::less<int>()); */
    /* numbers2.sort(std::less<int>()); */
    /* numbers.merge(numbers2); */
    /* display(numbers); */
    /* display(numbers2);//empty */

    //splice
    /* list<int> numbers3{3, 0, 8, 5, 9, 1, 3}; */
    /* auto iter = numbers.begin(); */
    /* auto iter3 = numbers3.begin(); */
    /* ++iter3; */
    /* ++iter; */
    /* ++iter; */
    /* numbers.splice(iter, numbers3, iter3); */
    /* display(numbers); */
    /* display(numbers3); */

    auto iter = numbers.begin();
    ++iter;
    ++iter;
    auto iter2 = numbers.end();
    --iter2;
    --iter2;
    cout << "*iter = " << *iter << endl;
    cout << "*iter2 = " << *iter2 << endl;
    numbers.splice(iter, numbers, iter2);
    display(numbers);
}

int main()
{
    test();

    return 0;
}

