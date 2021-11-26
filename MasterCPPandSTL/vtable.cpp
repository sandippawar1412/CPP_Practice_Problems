/*
    Only member functions mentioned virtual will have entry in vtable, once in base it marked as virtual
    its ok even in multi level inheritance its not made virtual in lower classes.

    Base:print1 is virtual, it has entry in vtable of Derived, Derived2 even its not virtual in Derived

    BaseLprint2 is compile time bound, no entry in vtable, same with dtor if not made virtual

*/

#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual void print1()
    {
        cout << "Base: print1" << endl;
    }

    void print2()
    {
        cout << "Base: print2" << endl;
    }

    virtual ~Base()
    {
        cout << "Base: Dtor" << endl;
    }
};

class Derived : public Base
{
public:
    void print1()
    {
        cout << "Derived: print1" << endl;
    }

    void print2()
    {
        cout << "Derived: print2" << endl;
    }

    ~Derived()
    {
        cout << "Derived: Dtor" << endl;
    }
};

class Derived2 : public Derived
{
public:
    void print1()
    {
        cout << "Derived2: print1" << endl;
    }

    void print2()
    {
        cout << "Derived2: print2" << endl;
    }

    ~Derived2()
    {
        cout << "Derived2: Dtor" << endl;
    }
};

int main()
{
    Base *bptr = new Derived2();
    bptr->print1();
    bptr->print2();
    delete bptr;
}
/*
Derived2: print1
Base: print2
Derived2: Dtor
Derived: Dtor
Base: Dtor
*/
