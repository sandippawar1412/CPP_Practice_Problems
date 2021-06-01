#include <iostream>
#include <set>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
	    int N, M, K;
	    cin>>N >>M >>K;
	    set<int> st1;
	    set<int> st2;
	    cout<<N<<M<<K;
	    while(K--){
	        int no;
	        cin >>no;
	        if(no<=N){
	            if(st1.find(no) != st1.end())
	                st2.insert(no);
	            else
	                st1.insert(no);
            }
	    }
	    cout<<st2.size();
	    for(auto& ele:st2){
	        cout<<" "<<ele;
	    }
	    cout<<endl;
	    
	}
	return 0;
}
