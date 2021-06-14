#include<bits/stdc++.h>
using namespace std;

class Singleton{
    static Singleton *obj ;
    Singleton(){}
    public:
        static Singleton*  getInstance(){
            if(obj == nullptr)
                obj = new Singleton;
            return obj;
        }

        void show(){
            cout<<"Hello from singleton"<<endl;
        }
    

};

Singleton* Singleton::obj = nullptr;

int main(){
    Singleton* ptr = Singleton::getInstance();
     //ptr->getInstance();
     ptr->show();
}