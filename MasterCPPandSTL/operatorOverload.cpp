/*
Move elision
operator overloading
*/
#include <bits/stdc++.h>
using namespace std;

class Integer
{
private:
    int *m_item;

public:
    Integer() : Integer(0)
    { //Default
        cout << "CTOR() Called" << endl;
    }

    Integer(int a)
    { //Parameterized
        cout << "CTOR(int ) Called" << endl;
        m_item = new int{a};
    }

    Integer(const Integer &b)
    { //copy
        cout << "CTOR(const Intger& ) Called" << endl;
        m_item = new int{*b.m_item};
    }

    Integer(Integer &&b)
    { //move
        cout << "CTOR(const Intger&& ) Called" << endl;
        m_item = b.m_item;
        b.m_item = nullptr;
    }

    ~Integer()
    {
        cout << "Default DTOR Called" << endl;
    }

    int GetValue() const
    {
        return *m_item;
    }

    void SetValue(int val)
    {
        if (!m_item)
            m_item = new int{0};
        *m_item = val;
    }

    //Overloaded Operators
    Integer operator+(const Integer &b) const
    {
        Integer temp;
        //temp.SetValue( b.GetValue());
        *temp.m_item = *m_item + *b.m_item;
        return temp;
    }

    Integer operator-(const Integer &obj2)
    {
        Integer temp;
        *temp.m_item = *m_item - *obj2.m_item;
        return temp;
    }

    Integer &operator=(const Integer &obj)
    {
        if (this != &obj)
        {
            delete m_item;
            m_item = new int{*obj.m_item};
        }
        /**m_item = *obj.m_item;*/
        return *this;
    }

    Integer &operator=(Integer &&obj)
    {
        if (this != &obj)
        {
            delete m_item;
            m_item = obj.m_item;
            obj.m_item = nullptr;
        }
        return *this;
    }

    Integer &operator++()
    { // pre increment
        ++(*m_item);
        return *this;
    }

    bool operator==(const Integer b)
    {
        return *m_item == *b.m_item;
    }

    // Integer operator++(int ){ // post increment
    //     Integer temp(*this);
    //     ++(*m_item);
    //     return temp;
    // }

    //function call operator
    void operator()()
    {
        cout << *m_item << endl;
    }

    friend Integer operator++(Integer &obj, int);
    
};

ostream &operator<<(ostream &outf, Integer &obj)
{
    outf << obj.GetValue();
    //outf << *obj.m_item;
    return outf;
}

istream &operator>>(istream &inp, Integer &obj)
{
    int val;
    inp >> val;
    obj.SetValue(val);
    return inp;
}

// Integer& operator++ (Integer& obj){
//     ++(*obj.m_item);
//     return obj;
// }

Integer operator++(Integer &obj, int)
{
    Integer temp(obj);

    ++(*obj.m_item);
    return temp;
}

Integer Add(int a, int b)
{
    //Integer temp(a+b);
    //return temp; //named return value optimization

    return Integer(a + b); //Return value optimization // better
}

Integer operator*(const Integer &a, const Integer &b)
{
    Integer temp;
    temp.SetValue(a.GetValue()*b.GetValue());
    return temp;
}

Integer operator/(const Integer &a, const Integer &b)
{
    Integer temp;
    temp.SetValue(a.GetValue() / b.GetValue());
    return temp;
}

bool operator==(const Integer &a, const Integer &b)
{
    return (a.GetValue() == b.GetValue());
}

Integer operator+(int a, Integer &obj)
{
    Integer temp;
    temp.SetValue(a + obj.GetValue());
    return temp;
}

int main()
{
    /*
    Integer var1 = 4;=>expected=> Integer var1 = Integer (4)
                    => but compiler does=> Integer var1(4);
CTOR(int ) Called
Default DTOR Called
Move elision-> rather than creating temp object and copying compiler smartly selected parameterise ctor

If we switch off copy elision, we can see move constructor called
g++ .\operatorOverload.cpp -fno-elide-constructors
CTOR(int ) Called
CTOR(const Intger&& ) Called
Default DTOR Called
Default DTOR Called


*/
    cout << "In MAin" << endl;
    //Integer var2 = var1;          //copy ctor called
    /*
    Integer var1;
    Integer var3 = (var1 + var1); //Move elision 
With off->
CTOR() Called -> var1
CTOR() Called -> temp 
CTOR(const Intger&& ) Called -> temp return
CTOR(const Intger&& ) Called -> var3

with elision on->
CTOR() Called ->var1
CTOR() Called ->temp
Default DTOR Called
Default DTOR Called
*/
    //Integer var1(0);
    //cout<<(var1 + var1).GetValue()<<endl;

    //Integer var1 = Add(2,3); //Move elision

    Integer var1 = 6;
    Integer var2 = var1 * var1;
    Integer var3 = var1 / var1;
    var1++;
    var1++;
    ++var1;
    ++var1;
    var2++;
    var2++;
    var2++;
    var3++;
    cout << var2.GetValue() << " " << var3++.GetValue() << endl;

    cout << var3 << endl;
    Integer obj;
    cout << "Enter Any No: ";
    cin >> obj;
    cout << obj << endl;

    Integer var4 = var1 + 6; // as var.operator+(5)

    Integer var5 = 7 + var1; // global overload required
    var5();
}