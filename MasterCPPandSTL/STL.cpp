#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> m;
    m.emplace(1, "asd");
    m.insert(make_pair(10, "OK"));
    for (auto &a : m)
    {
        cout << a.first << " " << a.second << endl;
    }

    unordered_map<int, string> ump;
    ump.emplace(100, "first");
    ump.emplace(200, "second");
    ump.emplace(300, "second");
    ump.emplace(400, "second");

    for (const auto &u : ump)
    {
        cout << "Bucket: " << ump.bucket(u.first) << " - " << u.first << ":" << u.second << endl;
    }
    cout << "Bucket Size: " << ump.bucket_count() << endl;
    cout << "LoadFactor: " << ump.load_factor() << endl;


    set<int> st{1,2,3,5,6};
    //st.contains(4); //in c++20

    //auto node = st.extract(5); //in c++17
    //node.value() = 10;
    //st.insert(move(node));
}