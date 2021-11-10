#include <bits/stdc++.h>
using namespace std;

class Human
{
public:
    string name;
    Human(char* str){
        name = string(str);
    }

    Human(string str)
    {
        name = string(str + "s");
    }


    Human (string&& str)
    {
        name = string(str + " - && - s");
    }

    Human (Human&& hm)
    {
        // name = string(str + " - && - s");
        cout<<"In &&"<<endl;
    }
    
    Human (Human& str)
    {
        // name = string(str + " - && - s");
        cout<<"In &"<<endl;
    }
    
private:
    string phoneNo;

public:
    string address;
};

int main()
{

    Human hm{"ok"};// = Human((string("Ok")));
    Human hm2{move(hm)};
    cout << hm.name << endl;
}
