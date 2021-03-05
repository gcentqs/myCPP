#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::for_each;
using std::remove_if;

class Number
{
public:
    Number(size_t data = 0)
    : _data(data)
    {
        /* cout << "Number(size_t = 0)" << endl; */
    }

    void print() const
    {
        cout << _data << " ";
    }

    bool isEven() const
    {
        return (0 == _data % 2);
    }

    bool isPrime() const
    {
        if (1 == _data)
        {
            return false;
        }

        for (size_t idx = 2; idx <= _data/2; ++idx)
        {
            if (_data % idx == 0)
            {
                return false;
            }
        }

        return true;
    }

    ~Number()
    {
        /* cout << "~Number()" << endl; */
    }

private:
    size_t _data;
};

void test()
{
    vector<Number> numbers;
    for (size_t idx = 0; idx != 18; ++idx)
    {
        numbers.push_back(Number(idx));
    }

    for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::print));
    cout << endl;
    numbers.erase(remove_if(numbers.begin(), numbers.end(),
                           std::mem_fn(&Number::isPrime)), numbers.end());
    for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::print));
    cout << endl;
}

int main()
{
    test();

    return 0;
}

