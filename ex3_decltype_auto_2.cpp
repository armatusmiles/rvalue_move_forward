#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template <typename Container, typename Index>
auto authAndAccess(Container& c, Index i)
{
    return c[i];
}

template <typename Container, typename Index>
decltype(auto) authAndAccess2(Container& c, Index i)
{
    return c[i];
}

template <typename Container, typename Index>
decltype(auto) authAndAccess3(Container&& c, Index i) // c is universal reference
{
    return std::forward<Container>(c)[i];
}

auto fabricMethod()
{
    return vector{1,2,3};
}

int main()
{
    vector v = {1,2,3}; // C++17 feature

    // authAndAccess(v, 2) = 3; // Compile error
    /** return type of authAndAccess is 'int' **/
    
    authAndAccess2(v, 2) = 33; // ok return type is 'int&'
    assert(v[2] == 33);

    // Compile error fabricMethod() is rvalue
    // authAndAccess2(fabricMethod(), 2);
    auto r = authAndAccess3(fabricMethod(), 2);
    assert(r == 3);

    authAndAccess3(v, 1) = 22; // ok return type is 'int&'
    assert(v[1] == 22);
}