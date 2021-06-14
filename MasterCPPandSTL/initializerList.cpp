#include <iostream>
#include <initializer_list>
#include <cassert>

using namespace std;

class Bag
{
    int arr[10];
    int size{};

public:
    Bag(initializer_list<int> lst)
    {
        auto it = lst.begin();
        // while (it != lst.end())
        // {
        //     Add(*it);
        //     it++;
        // }
        for(auto x:lst){
            Add(x);
        }
    }
    void Add(int ele)
    {
        assert(size < 10);
        arr[size++] = ele;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    auto lst = {1, 2, 3, 4};
    cout << "Type: " << typeid(lst).name() << endl;

    Bag b{lst};
    b.display();

    Bag b1{7,6,8,9,4};
    b1.display();
}