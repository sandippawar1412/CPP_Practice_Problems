/*
Shortest Path between source and destination(1-N)
only catch.. edge distance is from source(sort of)

5 5
1 2 30
1 3 10
2 5 40
3 4 20
4 5 30
=>30
*/

/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;

int64_t findShortestDistance(int N, vector<vector<pair<int, int>>> &edgesList)
{
    vector<int64_t> nodeDistance(N + 1, INT64_MAX);
    nodeDistance[1] = 0;

    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> heap;
    heap.push({0, 1});//dummy <cost, source> pair

    while (!heap.empty())
    {
        pair<int64_t, int> ele = heap.top();
        heap.pop();

        if (ele.first > nodeDistance[ele.second])
            continue;

        if (ele.second == N) //if we reach to Nth node, we can return.
            return ele.first;

        for (auto &edge : edgesList[ele.second])
        {
            int v = edge.first;
            int64_t newDist = ele.first + max(edge.second - ele.first, 0LL);

            if (newDist < nodeDistance[v])
            {
                nodeDistance[v] = newDist;
                heap.push({newDist, v});
            }
        }
    }
    return nodeDistance[N];
}

int main(int argc, char *a[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> edgesList(N + 1);
    int R;
    cin >> R;
    for (int i = 0; i < R; ++i)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        edgesList[v1].emplace_back(make_pair(v2, cost));
        edgesList[v2].emplace_back(make_pair(v1, cost));
    }

    int64_t dist = findShortestDistance(N, edgesList);

    if (dist == INT64_MAX)
        cout << "NOT POSSIBLE";
    else
        cout << dist;
}