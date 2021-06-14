#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

void msgPrint(){
    cout<<"last message"<<endl;
}

//constructor delegate
class Init{
    public:
        int a = 201;
    public:
        Init():Init(10){
            cout<<"empty ctr"<<endl;
        };    
        Init(int var){
            a = var;
            cout<<"para ctr"<<endl;
        };
};


//keywords in class default, delete, 
class Init2{
    public:
    int a;
    Init2() = default;
    Init2(int var){
        a = var;
    }
    Init2(const Init2& ) = delete;    

    void setValue(int v){
        a = v;
    }

    void setValue(float ) = delete;
};


int main(){
    //uniform initializers
    int a{};
    int arr[8]{};
    int *ptr = new int{};
    //char *ptr2 = new char[10]{"Hello"};
    int *ptr2 = nullptr;
    // *ptr2 = 2;

    /*fucntion called just before exit*/
    atexit(msgPrint);

    /*function ptrs */
    int(*fun)(int, int) = gcd;
    int(*fun2)(int, int) = &gcd;
    
    cout<<fun(10,20)<<endl;
    cout<<(*fun2)(30,8)<<endl;

    Init var;
    cout<<var.a<<endl;
    
    Init2 var2;
    var2.setValue(100);
    //var2.setValue(100.0f); //use of deleted function
    //Init2 var3(var2); //error: use of deleted function 'Init2::Init2(const Init2&)'
}


