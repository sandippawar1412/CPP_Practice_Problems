#include <bits/stdc++.h>
using namespace std;

#define WEAK_PTR

#ifndef WEAK_PTR
class Printer
{
    shared_ptr<int> sptr{};

public:
    void SetValue(const shared_ptr<int> sharedp)
    {
        sptr = sharedp;
    }

    void Print()
    {
        cout << "Reference Count: " << sptr.use_count() << endl;
        cout << "Value pointed by ptr: " << *sptr.get() << endl;        
    }
};

#else
/* 
problem in above example is, we want all references should be deleted if *ptr>100, 
but it won't happen. only reference count will be reduced and deleted only if its 0.
we can use Weak ptr in this case as below
*/

class Printer
{
    weak_ptr<int> sptr{};

public:
    void SetValue(const weak_ptr<int> sharedp)
    {
        sptr = sharedp;
    }

    void Print()
    {
        cout << "Reference Count: " << sptr.use_count() << endl;
        if(sptr.expired()){
            cout << "Shared Ptr Expired !!" << endl ;
            return;
        }
        auto wp = sptr.lock();
        cout << "Value pointed by ptr: " << *wp << endl;
    }
};
#endif

int main()
{
    int var = 100;
    shared_ptr<int> ptr(new int{var});
    Printer p;
    p.SetValue(ptr);
    if (*ptr > 100)
    {
        ptr = nullptr;
    }
    p.Print();
}
/*
//#undef WEAK_PTR
//OUTPUT
//var = 101
Reference Count: 1
Value pointed by ptr: 101

//var = 100
Reference Count: 2
Value pointed by ptr: 100
--------------------
//#define WEAK_PTR
//OUTPUT:
//var = 101
Reference Count: 0
Shared Ptr Expired !!

//var = 100
Reference Count: 1
Value pointed by ptr: 100
*/