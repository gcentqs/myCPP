#include <iostream>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::string;

//删除器
struct FileCloser
{
    void operator()(FILE *fp) const
    {
        if (fp)
        {
            fclose(fp);
            cout << "fclose()" << endl;
        }
    }
};

void test()
{
    string msg = "helloworld\n";
    unique_ptr<FILE, FileCloser> up(fopen("hefei", "a+"));
    fwrite(msg.c_str(), 1, msg.size(), up.get());
}

void test2()
{
    string msg = "HelloHefei\n";
    shared_ptr<FILE> sp(fopen("hefei", "a+"), FileCloser());
    fwrite(msg.c_str(), 1, msg.size(), sp.get());
}

int main()
{
    /* test(); */
    test2();

    return 0;
}

