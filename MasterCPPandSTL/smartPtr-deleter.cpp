/*
Deleter: specify using functions or objects
prefered struct objects
*/
#include <iostream>
#include <memory>

using namespace std;

struct Free
{
    void operator()(int *p)
    {
        free(p);
        cout << "P deleted using Free() in member function" << endl;
    }
};

void deleter(int *p)
{
    free(p);
    cout << "P deleted using Free() in global function" << endl;
}

void unique_deleter()
{
    unique_ptr<int, Free> ptr((int *)malloc(sizeof(int)), Free{});
    *ptr = 100;
    cout << "Value of ptr var: " << *ptr << endl;

    unique_ptr<int, void (*)(int *)> ptr2((int *)malloc(sizeof(int)), deleter);
    *ptr2 = 101;
    cout << "Value of ptr2 var: " << *ptr2 << endl;
}

void shared_deleter()
{
    shared_ptr<int> ptr((int *)malloc(sizeof(int)), Free{});
    *ptr = 100;
    cout << "Value of ptr var: " << *ptr << endl;

    shared_ptr<int> ptr2((int *)malloc(sizeof(int)), deleter);
    *ptr2 = 101;
    cout << "Value of ptr2 var: " << *ptr2 << endl;
}

int main()
{
    cout << "Unique ptr with deleter" << endl;
    unique_deleter();
    cout << "Shared ptr with deleter" << endl;
    shared_deleter();
}