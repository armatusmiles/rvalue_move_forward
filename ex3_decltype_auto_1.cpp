#include <iostream>
#include <vector>
using namespace std;

class Widget {
public:
    Widget() { cout << "Widget()\n"; }
    Widget(const Widget&) { cout << "Copy()\n";}
};

// TODO TRANSLATE
// Главная разница в том что auto отбрасывает квалификаторы (*,&, const), a delctype - нет
int main()
{
    Widget w; // call constructor
    const Widget& cw = w;
    
    // It call copy
    auto mw1 = cw;

    // It don't call copy constructor, just assign reference.
    // decltype(auto) == const Widget& 
    decltype(auto) mw2 = cw; 
}