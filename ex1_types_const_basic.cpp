#include <assert.h>
#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
void f1(T& param)
{
    param++;    
}

void f1_ex()
{
    int x = 2;
    f1(x); // int&

    /** Compile error. const qualifier is a port of 'T' type **/
    // const int cx = x;
    // f1(cx); // T == const int&

    int& b = x;
    f1(b); // int&
    assert(x == 4);
}

template<typename T>
void f2(T* param)
{
    (*param)++;
    // TODO
    // It need to discuss why the pointer address is same.
    // I think because stack allocate the same address for pointer variable.
    cout << "Pointer address: " << &param << "\n";
    cout << "Pointer refer to " << param << "\n\n";
    param = NULL;
}

void f2_ex()
{
    int x = 2;
    cout << "X object address before pass to function: " << &x << "\n";
    f2(&x); // int*

    /** Compile error. The pointer to const int can't be incremented. **/
    // const int *px = &x; 
    // f2(px); // T == const int*

    static int a = 2;
    /** There is const pointer (not pointer to const object)
     *  But T == int* because parameter will be a copy of pointer to same object **/
    int * const cpx  = &x;
    cout << "Cpx pointer address before pass to function: " << &cpx << "\n";
    f2(cpx);
    assert(x == 4);
}

template<typename T>
void f3(T param)
{
    assert(typeid(T) == typeid(const char*));
    assert(typeid(T) != typeid(char*));
    assert(typeid(T) != typeid(char* const));
}

void f3_ex()
{
    const char* const ptr = "test string";
    f3(ptr); // T == const char* const, param == const char*
}

int main()
{
    f1_ex();
    f2_ex();
    f3_ex();
}