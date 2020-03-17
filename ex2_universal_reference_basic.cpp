#include <assert.h>
#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
void f(T&& param)
{

}

int main()
{
    int x = 1;
    const int cx = x;
    const int& rx = x;
    f(x);  // x - lvalue, T and param - int&
    f(cx); // cx - lvalue, T and param - const int&
    f(rx); // rx - lvalue, T and param - const int&
    f(27); // 27 - rvalue, T - int, param - int&&
}
