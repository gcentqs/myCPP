#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Child;

class Parent
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }

    ~Parent()
    {
        cout << "~Parent()" << endl;
    }
    
    shared_ptr<Child> pParent;
};

class Child
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }

    ~Child()
    {
        cout << "~Child()" << endl;
    }

    weak_ptr<Parent> pChild;
};

void test()
{
    shared_ptr<Parent> parent_ptr(new Parent());
    shared_ptr<Child> child_ptr(new Child());
    cout << "parent_ptr.use_count() = " << parent_ptr.use_count() << endl;
    cout << "child_ptr.use_count() = " << child_ptr.use_count() << endl;

    cout << endl;
    parent_ptr->pParent = child_ptr;
    child_ptr->pChild = parent_ptr;
    cout << "parent_ptr.use_count() = " << parent_ptr.use_count() << endl;
    cout << "child_ptr.use_count() = " << child_ptr.use_count() << endl;
}

int main()
{
    test();

    return 0;
}

