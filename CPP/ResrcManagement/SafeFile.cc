#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
public:
    SafeFile(FILE *fp = nullptr)
    : _fp(fp)
    {
        cout << "SafeFile(FILE *)" << endl;
        if (nullptr == _fp)
        {
            cout << "nullptr == _fp" << endl;
        }
    }

    void write(const string &msg)
    {
        fwrite(msg.c_str(), 1, msg.size(), _fp);
    }

    ~SafeFile()
    {
        cout << "~SafeFile()" << endl;
        if (_fp)
        {
            fclose(_fp);
            cout << "fclose(_fp)" << endl;
        }
    }
    
private:
    FILE *_fp;
};

int main()
{
    string msg = "helloworld";
    SafeFile sf(fopen("test.txt", "a+"));
    sf.write(msg);
    SafeFile sf1;

    return 0;
}

