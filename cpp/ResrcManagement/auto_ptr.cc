#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::auto_ptr;

void test()
{
    int *pt = new int(10);
    auto_ptr<int> ap(pt);
    cout << "*ap = " << *ap << endl
        << "pt = " << pt << endl
        << "ap.get() = " << ap.get() << endl;

    auto_ptr<int> ap2(ap);
    cout << "*ap2 = " << *ap2 << endl
        << "ap2.get() = " << ap2.get() << endl;
    /* cout << "*ap = " << *ap << endl; */
}

int main()
{
    test();

    return 0;
}

