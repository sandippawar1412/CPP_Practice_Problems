#include <bits/stdc++.h>
using namespace std;

class Human
{
public:
    string name;
    Human(char *str)
    {
        name = string(str);
    }

    Human(string str)
    {
        name = string(str + "s");
    }

    Human(string &&str)
    {
        name = string(str + " - && - s");
    }

    Human(Human &&hm)
    {
        // name = string(str + " - && - s");
        cout << "In &&" << endl;
    }

    Human(Human &str)
    {
        // name = string(str + " - && - s");
        cout << "In &" << endl;
    }

private:
    string phoneNo;

public:
    string address;
};

class Test
{
    int age;

public:
    int *getAgeAddr()
    {
        return &age;
    }

    static void check()
    {
        int x = 10;
        if (x == 10)
        {
            int x = 9;
            cout << x << endl;
        }
    }
};

int main()
{
    Human hm{"ok"}; // = Human((string("Ok")));
    Human hm2{move(hm)};
    cout << hm.name << endl;

    Test t;
    int *ptr = t.getAgeAddr();

    t.check();
}
