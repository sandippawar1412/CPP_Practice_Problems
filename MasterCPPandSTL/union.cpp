#include <iostream>
using namespace std;

union Test
{
    int x;
    char y;
    Test(int v) : x(v){};
    ~Test(){};
};

class A
{
    int var;

public:
    A(int a) : var(a) {}
    ~A()
    {
        cout << "~A()" << endl;
    }
};

class B
{
    char var;

public:
    B(char c) : var(c) {}
    ~B() {}
};

union Test2
{
    A a;
    B b;
    Test2() {}
    ~Test2() {}
};

int main()
{
    Test t(2);
    cout << t.x << " " << t.y << endl;

    Test2 t2;
    new (&t2.a) A{10};
    t2.a.~A();

    Test2 t3;
    new (&t3.b) B{'a'};
}
