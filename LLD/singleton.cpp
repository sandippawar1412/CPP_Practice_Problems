#include <bits/stdc++.h>
using namespace std;

class Singleton
{
private:
    static Singleton *obj; // = nullptr;
    Singleton(){};

public:
    static Singleton *getObject()
    {
        if (obj == nullptr)
            obj = new Singleton();
        return obj;
    }
    void printMe()
    {
        cout << "Printed Singleton" << endl;
    }
};

Singleton *Singleton::obj = nullptr; // This is must

int main()
{
    Singleton *obj1 = Singleton::getObject();
    obj1->printMe();
}