#include <bits/stdc++.h>

using namespace std;

//There can be returen types of APIs, which are different
//Mange how we reuire it in swiggy class.


//-- This API classes will be provided not implemented by us
class JustPayAPI
{
public:
    void printMe()
    {
        cout << "JustPayAPI" << endl;
    }
};

class RazorPayAPI
{
public:
    void print()
    {
        cout << "RazorPayAPI" << endl;
    }
};

//---------------------
class PaymentProviderInterface
{
public:
    virtual void printName() = 0;
};

class JustPayAdaptor : public PaymentProviderInterface
{
    JustPayAPI api;

public:
    void printName()
    {
        api.printMe();
    }
};

//It can be singleton
class RazorPayAdaptor : public PaymentProviderInterface
{
    RazorPayAPI api;

public:
    void printName()
    {
        api.print();
    }
};

class Swiggy
{
    PaymentProviderInterface *paymentProvider;

public:
    Swiggy(PaymentProviderInterface *paymentProvider) : paymentProvider(paymentProvider) {}
    void print()
    {
        paymentProvider->printName();
    }
};

int main()
{
    Swiggy *swg = new Swiggy(new RazorPayAdaptor());

    swg->print();
}
