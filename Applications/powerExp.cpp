#include<bits/stdc++.h>
using namespace std;
static int MOD = 1e9 + 7;
int powerExp(long long int a, int exp){
    int ans = 1;
    while(exp){
        if(exp&1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        exp >>= 1;
    }
    return ans;
}
int main(){
    int N = 8, M = 4;
    cout<<powerExp(powerExp(2, N)-1, M)<<endl;
}