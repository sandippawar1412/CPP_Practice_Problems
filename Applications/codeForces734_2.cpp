#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        string str;        
        cin>>str;
        unordered_map<char, int>mp;
        for(auto& ch:str){
            mp[ch]++;
        }
        
        int ones = 0;
        int mul = 0;
        for(auto&m:mp){
            if(m.second == 1)
                ones++;
            else
                mul++;
        }
        cout<<(ones/2 + mul)<<endl;
    }
}