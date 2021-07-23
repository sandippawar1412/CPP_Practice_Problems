#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int N, K;
        vector<int>vec;
        cin>>N>>K;
        unordered_map<int, int>mp;
        while(N--){
            int inp;
            cin >> inp;
            vec.emplace_back(inp);
            mp[inp]++;
        }
        vector<int>ans;
        for(auto& a:vec){
            if(mp[a] > K)
                ans.emplace_back(0);
            else
                ans.emplace_back(mp[a]);
            --mp[a];
        }
        for(auto& a:ans){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}