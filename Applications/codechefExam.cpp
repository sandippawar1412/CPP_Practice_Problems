#include <iostream>
#include <set>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K, F;
        cin >> N >> K >> F;
        set<pair<int, int> > st;
        bool pass = false;
        while (N--)
        {
            int s, e;
            cin >> s >> e;
            st.insert(make_pair(s,e));
        }
        
        int i=0;
        auto it = st.begin();
        K -= it->first;
        if(it->first >= K)
            pass = true;
        else 
            K -= it->first;
        
        auto it2 = it;
        for(it++,i++; !pass && i<st.size(); i++,it++,it2++){
            int dif = (it->first - it2->second);
            if( dif >= K)
                pass = true;
            else //if( dif > 0)
                K -=  dif;
            
        }
        if(i == st.size() && ( F - it2->second) >= K)
            pass = true;
        
        if (pass)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}
