#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Data
{
public: Data(int data = 10)
    : _data(data)
    {
        cout << "Data(int = 10)" << endl;
    }

    int getData() const
    {
        return _data;
    }

    ~Data()
    {
        cout << "~Data()" << endl;
    }

private:
    int _data;
};

class SecondLayer
{
public:
    SecondLayer(Data *data)
    : _data(data)
    {
        cout << "SecondLayer(Data *)" << endl;
    }

    /* Data *operator->() */
    /* { */
    /*     return _data; */
    /* } */
    Data &operator*()
    {
        return *_data;
    }

    ~SecondLayer()
    {
        cout << "~SecondLayer()" << endl;
        if (_data)
        {
            delete  _data;
            _data = nullptr;
        }
    }

private:
    Data *_data;
}; 

class ThirdLayer 
{
public:
    ThirdLayer(SecondLayer *psl)
    : _psl(psl)
    {
        cout << "ThirdLayer(SecondLayer *)" << endl;
    }

    /* SecondLayer &operator->() */
    /* { */
    /*     return *_psl; */
    /* } */

    SecondLayer *operator->()
    {
        return _psl;
    }

    ~ThirdLayer()
    {
        cout << "~ThirdLayer()" << endl;
        if (_psl)
        {
            delete  _psl;
            _psl = nullptr;
        }
    }

private:
    SecondLayer *_psl;
};

void test()
{
    SecondLayer sl(new Data(20));
    /* cout << sl->getData() << endl; */
    /* cout << sl.operator->()->getData() << endl; */

    /* cout << (*sl).getData() << endl; */

    cout << endl;
    ThirdLayer tl(new SecondLayer(new Data()));
    cout << tl->getData() << endl;//简写
    cout << tl.operator->().operator->()->getData() << endl;
}

int main()
{
    test();

    return 0;
}

