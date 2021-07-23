#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int no;
        cin>>no;
        long long coin1 = no/3;
        long long coin2 = coin1+1;
        if(coin1 + 2*coin1 == no)
            cout<<coin1<<" "<<coin1<<endl;
        else if(coin1*2 + coin2 == no)
            cout<<coin2<<" "<<coin1<<endl;
        else    
            cout<<coin1<<" "<<coin2<<endl;
        
    }
}