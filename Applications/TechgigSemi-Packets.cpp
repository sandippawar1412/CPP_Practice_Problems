/*
2
6 1
->11
1
80
->156
*/

/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int packets;
    cin >> packets;
    long long int res = 0;
    while(packets--){
        long long int packet;
        cin >> packet;       		
        if(packet == 1){
            res += 1;
            continue;
        }
        res += 1;
        for(long long i = 2; i*i <= packet; ++i){
            if(!(packet % i)){                
                res += packet;
                packet /= i;
				--i;
            }
        }  
        res += packet;
    }   
    cout<<res;
    

    return 0;
}