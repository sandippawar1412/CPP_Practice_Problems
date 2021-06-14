#include <bits/stdc++.h>
using namespace std;

class Integer
{
    int *m_item;
public:
    int a;
    Integer():Integer(0)
    {
        cout << "Integer()" << endl;
    }

    Integer(int val)
    {
        m_item = new int{val};
        cout << "Integer(int )" << endl;        
    }

    Integer(const Integer &t)
    {
        if(!m_item)
            m_item = new int{*t.m_item};
        cout << "Integer(const Integer&)" << endl;        
    }

    Integer(Integer &&t)
    {
        m_item = t.m_item;
        delete t.m_item;
        t.m_item = nullptr;        
        cout << "Integer(const Integer&& t)" << endl;        
    }
    ~Integer(){
        cout<<"~Integer()"<<endl;
    }

    int GetValue(){
        return *m_item;
    }
};

// void process(unique_ptr<Integer>& p){
//     cout<<p->GetValue()<<endl;
// }

void process(unique_ptr<Integer> p){
    cout<<p->GetValue()<<endl;
}

void process(shared_ptr<Integer> p){
    cout<<p->GetValue()<<endl;
}
int main(){
    //Single owwnership
    unique_ptr<Integer> uptr(new Integer());
    //process(uptr); can be used with reference process(unique_ptr<Integer>& p)
    process(move(uptr));
    //cout<<uptr->GetValue()<<endl; // Must not be used, as uptr doesn't valid now as its moved

    //Shared Ownership
    shared_ptr<Integer> sptr(new Integer());
    process(sptr);
    cout<<sptr->GetValue()<<endl;
}