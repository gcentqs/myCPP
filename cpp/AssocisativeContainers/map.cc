#include <iostream>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

void test1()
{
    std::pair<string, string> numbers = {"123", "hefei"};
    cout << numbers.first << ": " << numbers.second << endl;
}

void test()
{
    map<string, string> numbers = 
    { 
        {"010", "beijing"}, {"020", "shanghai"},
        std::pair<string, string>("050", "guangzhou"),
        std::pair<string, string>("040", "nanjing"),
        std::pair<string, string>("020", "hefei") 
    };
    /* for (auto &item : numbers) */
    /* { */
    /*     cout << item.first << ": " << item.second << endl; */
    /* } */

    /* cout << numbers.count("020") << endl; */
    /* auto it = numbers.find("020"); */
    /* map<string, string>::iterator it = numbers.find("020"); */
    /* cout << it->first << ": " << it->second << endl; */

    //insert
    auto elem = numbers.insert(std::pair<string, string>("070", "xinjiang"));
    for (auto &item : numbers)
    {
        cout << item.first << ": " << item.second << endl;
    }
    /* cout << elem.second << endl; */
    cout << elem.first->first << ": " << elem.first->second << endl;
    numbers["011"] = "hefei";
    for (auto &item : numbers)
    {
        cout << item.first << ": " << item.second << endl;
    }
}

int main()
{
    test();

    return 0;
}

