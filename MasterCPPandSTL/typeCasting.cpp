#include<bits/stdc++.h>
using namespace std;

class Test{
    int m;
public:
        Test(){
            m = 3;
        }
        explicit Test(int a){
            m = a;
        }
        explicit operator int(){
            return m;
        }
};

int main(){
    int a = 2;
    float b = static_cast<int>(10.9);
    char* p = reinterpret_cast<char*>(&a);
    const int c = 4;
    //int *d =  reinterpret_cast<int*>(&c);
    int *d =  const_cast<int* >(&c);

   // Test obj1 = 3; // implicit coversion, calling parameterised ctor
   // It errors out when ctor marked explicit
    Test obj1(10);

    //int var = obj1;// error:cannot convert 'Test' to 'int' in initialization
    //need to use type conversion operator

    int var = static_cast<int>(obj1);

}