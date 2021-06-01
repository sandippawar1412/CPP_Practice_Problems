/*
Fib(N) in o(1)
using Binet's golden ratio formula
*/
//#include "../includes.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 3;
    double goldenRatio = (1 + sqrt(5)) / 2;

    int ans = round(pow(goldenRatio, N) / sqrt(5));
    cout << ans << endl;  
}