#include <string.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Array
{
public:
    Array(size_t size = 10)
    : _size(size)
    , _data(new char[_size]())
    {
        cout << "Array(size_t = 10)" << endl;
    }

    char operator[](size_t idx)
    {
        if (idx < _size)
        {
            return _data[idx];
        }
        else
        {
            static char charnull = '\0';
            return charnull;
        }
    }

    size_t size() const
    {
        return _size;
    }

    void print() const
    {
        for (size_t idx = 0; idx != _size; ++idx)
        {
            cout << _data[idx] << " ";
        }
        cout << endl;
    }

    ~Array()
    {
        cout << "~Array()" << endl;
        if (_data)
        {
            delete [] _data;
            _data = nullptr;
        }
    }

private:
    size_t _size;
    char *_data;
};

int main()
{
    const char *pstr = "helloworld";
    Array arr(strlen(pstr) + 1);
    for (size_t idx = 0; idx != arr.size(); ++idx)
    {
        /* arr[idx] = pstr[idx]; */
        arr.operator[](idx) = pstr[idx];
    }

    arr.print();

    return 0;
}

