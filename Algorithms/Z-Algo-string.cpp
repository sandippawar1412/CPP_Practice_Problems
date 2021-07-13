#include <bits/stdc++.h>
using namespace std;

// Brute Force Z function: O(N^2)
vector<int> z_function_bf(string s)
{
    int N = static_cast<int>(s.length());
    vector<int> Z(N, 0);
    for (int i = 1; i < N; ++i)
    {
        while (i + Z[i] < N && s[Z[i]] == s[i + Z[i]])
            ++Z[i];
    }
    return Z;
}
// O(N)
vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> z_function2(string s)
{
    vector<int> z(s.size());
    int N = s.length();
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < N; ++i)
    {
        if (i > r)
        {
            l = i;
            r = 0;
            while (i + r < N && s[i + r] == s[r])
                ++r;
            z[i] = r;
            r = l + r - 1;
        }
        else
        {
            if (i + z[i - l] - 1 < r)
            {
                z[i] = z[i - l];
            }
            else
            {
                l = i;
                while (r < N && s[r] == s[r - i])
                    ++r;
                z[i] = r - l;
                --r;
            }
        }
    }
    return z;
}

int main()
{
    string s = "aabxaabxSaabxaabxay";
    vector<int> z;
    // vector<int> z  = z_function2(s);
    // Brute Force Z function
    cout << setw(15) << "Input String: " << s << endl;
    z = z_function_bf(s);
    cout << setw(15) << "Brute Force: ";
    for (auto &n : z)
        cout << n << " ";
    cout << endl;

    // Optimised Z function
    cout << setw(15) << "Optimised1: ";
    z = z_function(s);
    for (auto &n : z)
        cout << n << " ";
    cout << endl;

    // Optimised Z function
    cout << setw(15) << "Optimised2: ";
    z = z_function2(s);
    for (auto &n : z)
        cout << n << " ";
    cout << endl;
}