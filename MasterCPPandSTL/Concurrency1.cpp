#include<iostream>
#include<list>
#include<unistd.h>
#include<thread>
#include<string>
#include<mutex>
using namespace std;

std::mutex g_Mutex;
list<int> gData;
const int size = 100000;


void Download(const string &fname){
    cout<<"Download Started: "<<fname<<endl;
    for(int i=0; i<size; ++i){   
        lock_guard<mutex> lg(g_Mutex);// its object, so destuctor will be called incase of issue        
        // g_Mutex.lock();     
        gData.push_back(i);
         if(i==500) //causing deadlock as its locked and terminated
             return; //better to use lock_guard
        // g_Mutex.unlock();
    }
    cout<<"Download Finished"<<endl;
}


void Download2(const string &fname){
    cout<<"Download2 Started: "<<fname<<endl;
    for(int i=0; i<size; ++i){ 
        g_Mutex.lock();            
        gData.push_back(i);
        g_Mutex.unlock();     
    }
    cout<<"Download2 Finished"<<endl;
}

int main(){
    string fname{"test.txt"};
    cout<<"Main: Before download"<<endl;
    thread t(Download, cref(fname)); //ref for non-constant
    thread t2(Download2, cref(fname)); //ref for non-constant
    // t.detach();
    
    cout<<"Main: After download"<<endl;
    // system("pause");
    if(t.joinable())
        t.join();
    t2.join();

    cout<<gData.size()<<endl;
}