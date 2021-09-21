#include <bits/stdc++.h>
using namespace std;

//Only distance no parent info
vector<int> dijkstra(int A, vector<vector<int>> &B, int C)
{
    vector<vector<pair<int, int>>> adj(A + 1); // vec[u]->{[v1, w1], [v2, w2]} ;
    for (auto &e : B)
    {
        adj[e[0]].emplace_back(e[1], e[2]);
        adj[e[1]].emplace_back(e[0], e[2]);
    }

    unordered_map<int, int> visited; // with distance

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, C);
    while (!pq.empty())
    {
        auto [dist, u] = pq.top();
        pq.pop();
        if (visited.count(u) != 0)
            continue;

        visited[u] = dist;
        for (auto &[v, d] : adj[u])
            pq.emplace(dist + d, v);
        
        if (visited.size() == A)
            break;
    }

    vector<int> ans(1, 0);
    for (int i = 1; i <= A; ++i)
    {
        if (visited.count(i) == 0)
            ans.emplace_back(-1);
        else
            ans.emplace_back(visited[i]);
    }

    return ans;
}

//Return dist and parent
vector<pair<int, int>> dijkstraWithParent(int A, vector<vector<int>> &B, int C)
{
    vector<vector<pair<int, int>>> adj(A + 1); // vec[u]->{[v1, w1], [v2, w2]} ;
    for (auto &e : B)
    {
        adj[e[0]].emplace_back(e[1], e[2]);
        adj[e[1]].emplace_back(e[0], e[2]);
    }

    unordered_map<int, pair<int, int>> visited; // with distance

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.emplace(0, make_pair(C, C));
    while (!pq.empty())
    {
        auto [dist, path] = pq.top();
        auto u = path.first;
        auto parent = path.second;
        pq.pop();
        if (visited.count(u) != 0)
            continue;

        visited[u] = {dist, parent};
        for (auto &[v, d] : adj[u])
        {
            pq.emplace(dist + d, make_pair(v, u));
        }

        if (visited.size() == A)
            break;
    }

    vector<pair<int, int>> ans(1);
    for (int i = 1; i <= A; ++i)
    {
        if (visited.count(i) == 0)
            ans.emplace_back(-1, i);
        else
            ans.emplace_back(visited[i]);
    }

    return ans;
}

int main()
{
    vector<vector<int>> edges{{1, 2, 7}, {1, 6, 8}, {2, 3, 6}, {2, 6, 3}, {3, 5, 2}, {3, 6, 4}, {3, 4, 5}, {5, 4, 5}, {6, 5, 3}};
    int n = 6;
    vector<int> dist = dijkstra(n, edges, 1);
    for (int i = 1; i <= n; ++i)
        cout << i << " : " << dist[i] << endl;

    cout<<"Dist to each node With Parent from single source"<<endl;
    vector<pair<int, int>> path = dijkstraWithParent(n, edges, 1);
    for (int i = 1; i <= n; ++i)
        cout << i << " : " << path[i].first << " <- " << path[i].second << endl;
    return 0;
}