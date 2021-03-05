#include "Line.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;



class Line::LinePimpl
{
public:
    LinePimpl(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1)
    , _pt2(x2, y2)
    {
        cout << "LinePimpl(int, int, int, int)" << endl;
    }

    void printLinePimpl()
    {
        _pt1.print();
        cout << "------->";
        _pt2.print();
        cout << endl;
    }

    ~LinePimpl()
    {
        cout << "~LinePimpl()" << endl;
    }

private:
    class Point
    {
    public:
        Point(int ix = 0, int iy = 0)
        : _ix(ix)
        , _iy(iy)
        {
            cout << "Point(int = 0, int = 0)" << endl;
        }

        void print()
        {
            cout << "(" << _ix << ", " << _iy << ")" << endl;
        }

        ~Point()
        {
            cout << "~Point()" << endl;
        }

    private:
        int _ix;
        int _iy;
    };

private:
    Point _pt1;
    Point _pt2;
};

Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LinePimpl(x1, y1, x2, y2))
{
    cout << "Line(int, int, int, int)" << endl;
}

Line::~Line()
{
    cout << "~Line" << endl;
    if (_pimpl)
    {
        delete _pimpl;
        _pimpl = nullptr;
    }
}

void Line::printLine() const
{
    _pimpl->printLinePimpl();
}
