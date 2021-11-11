/*
Interface and compositions
IS-A and HAS-A relationship

Dog IS-A Animal but HAS-A walking behavior
*/

#include <bits/stdc++.h>

using namespace std;

class Animal
{
public:
    string name;
    int height;
    int weight;
};

//Interface
class Walkable
{
public:
    virtual void walk() = 0;
    virtual ~Walkable(){};
};

class WalkingBehavior
{
public:
    virtual void walk() = 0;
    virtual ~WalkingBehavior() {} //must
};

class SlowWalkingBehavior : public WalkingBehavior
{
public:
    void walk()
    {
        cout << "SlowWalkingBehavior" << endl;
    }
};

class FastWalkingBehavior : public WalkingBehavior
{
public:
    void walk()
    {
        cout << "FastWalkingBehavior" << endl;
    }
};

//Interface
class Audible
{
public:
    virtual void makeSound() = 0;
    virtual ~Audible(){};
};

class SpeakingBehavoir
{
public:
    virtual void makeSound() = 0;
    virtual ~SpeakingBehavoir(){};
};

class SlowSpeakingBehavoir : public SpeakingBehavoir
{
public:
    void makeSound()
    {
        cout << "SlowSpeakingBehavoir" << endl;
    }
};

class FastSpeakingBehavoir : public SpeakingBehavoir
{
public:
    void makeSound()
    {
        cout << "FastSpeakingBehavoir" << endl;
    }
};

class Dog : Animal, Walkable, Audible
{
    WalkingBehavior *walkingBehavior;
    SpeakingBehavoir *speakingBehavoir;

public:
    Dog(WalkingBehavior *wb, SpeakingBehavoir *sb)
    {
        walkingBehavior = wb;
        speakingBehavoir = sb;
    }

    void walk()
    {
        walkingBehavior->walk();
    }

    void makeSound()
    {
        speakingBehavoir->makeSound();
    }
};

int main()
{
    Dog *d = new Dog(new FastWalkingBehavior, new SlowSpeakingBehavoir);
    d->walk();
    d->makeSound();

    Dog *d2 = new Dog(new SlowWalkingBehavior, new FastSpeakingBehavoir);
    d2->walk();
    d2->makeSound();
}
