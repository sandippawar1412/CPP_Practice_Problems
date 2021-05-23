/*
Class example: showing
inheritance
static, const data member
*/

#include "../includes.h"

class Peak
{
    string name;
    string color;
};

class Bird
{
    string name;
    static int32_t wingCnt;
    Peak peak; // field as a relation
    const char tag;

public:
    void fly()
    {
        cout << "Bird:Fly wings" << endl;
    }

    virtual void eat() = 0;

    Bird(char t) : tag(t)
    {
        name = "default";
        cout << "Bird: Ctor" << endl;
    }

    ~Bird()
    {
        cout << "Bird: Dtor" << endl;
    }

    static void PrintMe()
    {
        cout << "Printing Bird Class" << endl;
    }
};

class Parrot : public Bird
{
public:
    void fly()
    {
        cout << "Parrot: Fly" << endl;
        Bird::fly(); // reading base method here
    }

    void eat()
    {
        cout << "Parrot eating";
    }

    Parrot(char t) : Bird(t)
    {
        cout << "Parrot: Ctor" << endl;
    }

    ~Parrot()
    {
        cout << "Parrot: Dtor" << endl;
    }
};

int32_t Bird::wingCnt = 2; // Needs to be initialized globally
int main()
{

    //Bird b('a');
    Parrot p('c');
    //p.fly();

    /*
    class Parrot : public Bird then accessible
    class Parrot :  Bird not accessible fly method
    */
    p.Bird::fly();

    Bird::PrintMe();
}
