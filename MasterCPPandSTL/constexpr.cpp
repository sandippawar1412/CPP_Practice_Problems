#include <iostream>
using namespace std;

constexpr int GetNumber()
{
    return 100;
}

int GetNumber2()
{
    return 100;
}

int main()
{

    const int i = GetNumber(); // Resolved at compile time constexpr
    int arr[i]{1, 2, 3, 4};

    const int j = GetNumber2(); // Run time
    int arr2[j];
}