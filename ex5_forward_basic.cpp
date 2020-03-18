#include <iostream>
using namespace std;

class Widget {};

void process(const Widget& lvArg) { cout << "process(const Widget& lvArg)\n"; }
void process(Widget&& rvArg) { cout << "void process(Widget&& rvArg)\n"; }

template<typename T>
void logAndProcess(T&& param)
{
    cout << "logAndProcess\n";
    process(std::forward<T>(param));
}

int main()
{
    Widget w;
    logAndProcess(w);
    logAndProcess(std::move(w));
}