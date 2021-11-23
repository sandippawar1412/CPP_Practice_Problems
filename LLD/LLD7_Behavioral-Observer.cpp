/*
Adding new client like  LinkedIn, etc. 
It should be able to subscribe to BitCoinInfo
*/

#include <bits/stdc++.h>
using namespace std;

class BitCoinObserver;

class BitCoinInfo
{
public:
    unordered_set<BitCoinObserver *> observers;
    virtual void setState(string msg) = 0;
    virtual string getState() = 0;
    void attach(BitCoinObserver *observer)
    {
        observers.emplace(observer);
    }

    void dettach(BitCoinObserver *observer)
    {
        observers.erase(observer);
    }

    void update();
    // {
    //     cout << "*** BitCoinInfo Updated ***" << endl;
    //     for (auto &o : observers)
    //         o->takeAction();
    // }
};

class BitCoinObserver
{
public:
    BitCoinInfo *bitCoinInfoObj;
    virtual void takeAction() = 0;
};

class Twitter : public BitCoinObserver
{
public:
    Twitter(BitCoinInfo *obj)
    {
        bitCoinInfoObj = obj;
        bitCoinInfoObj->attach(this);
    }
    void takeAction()
    {
        cout << "TwitterObserver: " << bitCoinInfoObj->getState() << endl;
    }
    void addMsg(string msg)
    {
        bitCoinInfoObj->setState("Twitter: " + msg);
    }
};

class WhatsApp : public BitCoinObserver
{
public:
    WhatsApp(BitCoinInfo *obj)
    {
        bitCoinInfoObj = obj;
        bitCoinInfoObj->attach(this);
    }
    void takeAction()
    {
        cout << "WhatsAppObserver: " << bitCoinInfoObj->getState() << endl;
    }
    void addMsg(string msg)
    {
        bitCoinInfoObj->setState("WhatsApp: " + msg);
    }
};

// void Twitter::addMsg(string msg)
// {
//     bitCoinInfoObj->setState(msg);
// }
// void WhatsApp::addMsg(string msg)
// {
//     bitCoinInfoObj->setState(msg);
// }
void BitCoinInfo::update()
{
    cout << "*** BitCoinInfo Updated ***" << endl;
    for (auto &o : observers)
        o->takeAction();
}

class EventStream : public BitCoinInfo
{
public:
    deque<string> eventq;

    void setState(string msg)
    {
        eventq.push_back(msg);
        update();
    }

    string getState()
    {
        return eventq.back();
    }
};

int main()
{
    BitCoinInfo *bitCoinInfo = new EventStream;

    Twitter *tweet = new Twitter(bitCoinInfo);
    WhatsApp *waMsg = new WhatsApp(bitCoinInfo);

    tweet->addMsg("This is tweet Message");

    waMsg->addMsg("This is wa Message");
}