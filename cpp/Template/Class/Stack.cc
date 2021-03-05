#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//类模板
template <typename T, size_t size = 10>
class Stack
{
public:
    Stack()
    : _top(-1)
    , _data(new T[size]())
    {
        cout << "Stack()" << endl;
    }

    ~Stack();
    bool empty() const;
    bool full() const;
    void push(const T &value);
    void pop();
    T top();

private:
    int  _top;
    T *_data;
};

template <typename T, size_t size>
Stack<T, size>::~Stack()
{
    cout << "~Stack()" << endl;
    if (_data)
    {
        delete [] _data;
        _data = nullptr;
    }
}

template <typename T, size_t size>
bool Stack<T, size>::empty() const
{
    return (_top == -1);
}

template <typename T, size_t size>
bool Stack<T, size>::full() const
{
    return (_top == size-1);
}

template <typename T, size_t size>
void Stack<T, size>::push(const T &value)
{
    if (!full())
    {
        _data[++_top] = value;
    }
    else
    {
        cout << "The stack is full" << endl;
        return;
    }
}

template <typename T, size_t size>
void Stack<T, size>::pop()
{
    if (!empty())
    {
        --_top;
    }
    else
    {
        cout << "The stack is empty" << endl;
        return;
    }
}

template <typename T, size_t size>
T Stack<T, size>::top()
{
    return _data[_top];
}

void test()
{
    Stack<int> stack;
    cout << "empty? " << stack.empty() << endl;
    stack.push(1);
    cout << "empty? " << stack.empty() << endl;
    cout << "full? " << stack.full() << endl;
    for (size_t idx = 2; idx != 15; ++idx)
    {
        stack.push(idx);
    }
    cout << "full? " << stack.full() << endl;

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    cout << "empty? " << stack.empty() << endl;
}

void test2()
{
    Stack<string, 12> stack;
    cout << "empty? " << stack.empty() << endl;
    stack.push("aa");
    cout << "empty? " << stack.empty() << endl;
    cout << "full? " << stack.full() << endl;
    for (size_t idx = 1; idx != 15; ++idx)
    {
        stack.push(string(2, 'a' + idx));
    }
    cout << "full? " << stack.full() << endl;

    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    cout << "empty? " << stack.empty() << endl;
}

int main()
{
    test2();

    return 0;
}

