#include<iostream>
#include <iomanip> 
using namespace std;

int main()  {
    int i=2;
    long l=3;
    char c='e';
    float f=12.12;
    double d=123.1231231;
    
    
    cin>>i>>l>>c>>f>>d;
    
    cout<<i<<endl;
    cout<<l<<endl;
    cout<<c<<endl;
    cout<<fixed<<setprecision(3)<<f<<endl;
    cout<<fixed<<setprecision(9)<<d<<endl;
    return 0;
}