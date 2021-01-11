#ifndef __LINE_H__
#define __LINE_H__

class Line
{
public:
    Line(int, int, int, int);
    void printLine() const;
    ~Line();
    class LinePimpl;
private:
    LinePimpl *_pimpl;
};

#endif
