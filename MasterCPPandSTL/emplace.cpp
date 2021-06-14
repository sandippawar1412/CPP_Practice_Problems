#include <bits/stdc++.h>
using namespace std;

class Test
{
public:
    int a;
    Test()
    {
        cout << "Test()" << endl;
    }

    Test(int val)
    {
        cout << "Test(int )" << endl;
        a = val;
    }

    Test(const Test &t)
    {
        cout << "Test(const Test&)" << endl;
        a = t.a;
    }

    Test(const Test &&t)
    {
        cout << "Test(const Test&& t)" << endl;
        a = t.a;
    }
};

//-fno-elide-constructors
int main()
{
    //Test t = 10;
    vector<Test> arr;

    //arr.push_back(10);
    cout << arr.capacity() << endl;
    arr.emplace_back(10);
    // arr.push_back(10);
    cout << arr.capacity() << endl;
    arr.emplace_back(20);
    // arr.push_back(10);
    cout << arr.capacity() << endl;
    arr.emplace_back(30);
    // arr.push_back(10);

    /*
    arr.push_back(10);
        ->Temp obj created and moved
        Test(int )
        Test(const Test&& t)

    arr.emplace_back(10);
        ->Only parameterised ctor called.No Temp obj
        Test(int )
    */
}