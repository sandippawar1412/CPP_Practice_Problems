#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    vector<int> vec;

public:
    Stack(int siz)
    {
        vec.resize(siz);
    }
    Stack() {}
    void push(int ele)
    {
        vec.emplace_back(ele);
    }
    int pop()
    {
        if (empty())
        {
            return -1;
        }
        int t = vec.back();
        vec.pop_back();
        return t;
    }
    int top()
    {
        return vec.back();
    }
    size_t size()
    {
        return vec.size();
    }

    bool empty()
    {
        return vec.size() == 0;
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(12);
    st.pop();
    st.push(2);
    st.push(122);
    st.top();

    while (!st.empty())
        cout << st.pop() << endl;
    cout << st.pop() << endl;
    return 0;
}