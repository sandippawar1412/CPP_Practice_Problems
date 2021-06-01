#include "../includes.h"
int main()
{
    vector<int>A = {60, 94, 63, 3, 86, 40, 93, 36, 56, 48, 17, 10, 23, 43, 77, 1, 1, 93, 79, 4, 10, 47, 1, 99, 91, 53, 99, 18, 52, 61, 84, 10, 13, 52, 3, 9, 78, 16, 7, 62};
    sort(A.begin(),A.end());
    int i=0;
    for(auto &ele:A)
    {
        cout<<i<<" "<<ele<<endl;
        i++;
    }

    cout<<log2(201326595)<<" "<<log2(5)<<~ ~5<<endl;  
}