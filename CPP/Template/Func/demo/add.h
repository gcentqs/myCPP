#ifndef __ADD_H__
#define __ADD_H__

//函数模板的声明与实现不能分开，否则会报错，如果一定要分开，可以在头文件中
//#include "add.cc"
template<class T>
T add(T x, T y);

/* int add(int x, int y); */

#include "add.cc"

#endif
