#include <bits/stdc++.h>
using namespace std;

mutex mu;
condition_variable condVar;
int cnt = 0;

bool chkEven()
{
    return cnt % 2 == 0;
}

bool chkOdd()
{
    return cnt % 2 == 1;
}

void even(int start, int end)
{
    while (cnt < end)
    {
        unique_lock<mutex> ul(mu);
        condVar.wait(ul, chkEven);
        cout << "Even: " << cnt++ << endl;
        // ul.unlock(); // Not compulsary to have
        condVar.notify_one();
    }
}

void odd(int start, int end)
{
    while (cnt < end)
    {
        unique_lock<mutex> ul(mu);
        // condVar.wait(ul, chkOdd);
        condVar.wait(ul, []()
                     { return cnt % 2 == 1; }); // Lambda
        cout << "Odd: " << cnt++ << endl;
        // ul.unlock();
        condVar.notify_one();
    }
}

int main()
{
    thread tobj1(even, 1, 100);
    thread tobj2(odd, 1, 100);
    tobj1.join();
    tobj2.join();
    cout << "Done" << endl;
}
