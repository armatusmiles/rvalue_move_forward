#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Constructor\n";}
    A(const A&) { cout << "Copy()\n";}
    A(A&&) { cout << "Move()\n";}
};

void foo(A a)
{}

void foo2(A&& a)
{}

template<typename T>
void foo3(T&&) {} // Take universal reference(!)

int main()
{
    A a1, a2, a3, a4, a5, a6, a7;
    const A ac;
    cout << "\n";

    foo(a1); // copy constructor
    foo(std::move(a2)); // move constructor
    foo(static_cast<A&&>(a3)); // move constructor
    foo(std::move(a4)); // move constructor
    foo(std::move(ac)); // copy constructor bacause const can't be moved
    cout << "\n";

    // Compile error a4 isn't rvalue
    //foo2(a4);

    foo2(static_cast<A&&>(a5)); // pass object by rvalue reference. (Constructors don't not called)
    foo2(std::move(a6)); // pass object by rvalue reference. (Constructors don't not called)
    foo2(A()); //  pass object by rvalue reference. Call constructor only
    
    foo3(a7); // pass object by lvalue reference
    foo3(std::move(a7)); // pass object by rvalue reference
}