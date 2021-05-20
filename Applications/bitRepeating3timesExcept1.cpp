#include "includes.h"

/*
 Integers repeating 3 times except 1 integer. Return that integer.
*/
int solve(vector<int> &inp)
{
    int one = 0, two = 0;
    for (auto &ele : inp)
    {
        one = (one ^ ele) & ~two;
        two = (two ^ ele) & ~one;
    }
    return one;
}

int solve_approach2(vector<int> &inp)
{
    int32_t bitCount[32] = {0};

    for (vector<int>::iterator it = inp.begin(); it != inp.end(); it++)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((*it) & (1 << i))
                bitCount[i]++;
        }
    }

    int32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (bitCount[i] % 3)
            ans ^= (1 << i);
    }
    return ans;
}

int main()
{
    vector<int> inp = {3, 4, 4, 5, 4, 5, 5, 6, 3, 3};

    cout << solve(inp) << endl;
    cout << solve_approach2(inp) << endl;
    return 0;
}