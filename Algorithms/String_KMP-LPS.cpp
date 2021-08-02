#include <bits/stdc++.h>
using namespace std;

// O(N)
vector<int> lps_function(string s)
{    
    int n = (int)s.length();
    vector<int> lps(n, 0);
    int len = 0;

    lps[0] = 0;
    int i =  1;
    while(i < n){
        if(s[i] == s[len]){
            lps[i] = ++len;
            ++i;
        }
        else if( len != 0)
            len = lps[len - 1];
        else
            ++i; //lps[i] = 0;
    }
    return lps;
}

int main()
{
    string s = "aabxaabxSaabxaabxay";
    vector<int> lps;
    cout << setw(15) << "Input String: " << s << endl;
    lps = lps_function(s);
   
    // lps
    for (auto &n : lps)
        cout << n << " ";
    cout << endl;
}