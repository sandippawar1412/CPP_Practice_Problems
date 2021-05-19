/*
Given a number(N) find out all numbers nb  such that summation of nb and sum_of_digits(nb) equals the number.
All the result numbers nb should be returned in a vector.
inp: 100
out: 86 
explanation-> 86+[8+6] -> 86+14 -> 100
a<=N<=10^9

*/

#include <iostream>
#include <vector>
using namespace std;
int sum_of_digits(int num)
{
    int sum = 0;
    while (num)
    {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

vector<int> solve(int inp)
{
    vector<int> ans;
    for (int i = max(inp / 2, inp - 99); i <= inp; i++)
    {
        if ((i + sum_of_digits(i)) == inp)
            ans.push_back(i);
    }
    if (!ans.size())
        ans.push_back(-1);
    return ans;
}

int main()
{
    int inp = 1000000000;
    cin >> inp;
    int num = inp;
    int sum = 0;
    while (inp <= num)
    {
        vector<int> ans = solve(inp);

        cout << "\nNum:" << inp << "->";
        for (auto &ele : ans)
        {
            if (ele != -1)
            {
                cout << " " << inp - ele << ":" << ele;
                sum = max(inp - ele, sum);
            }
            else 
                cout<<" "<<ele;
        }
        inp++;
    }
    cout << "\nMax diff: " << sum;
}