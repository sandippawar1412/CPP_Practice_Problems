#include <bits/stdc++.h>
using namespace std;

void dijkstra(int N, vector<vector<pair<int, int>>> &adjList, vector<int> &minDist)
{
    queue<pair<pair<int, int>, long long>, vector<pair<pair<int, int>, long long>> > q1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});

    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();

        int node = p.second;
        int dist = p.first;
        if (dist > minDist[node])
            continue;

        for (auto &edge : adjList[node])
        {
            int v = edge.first;
            int newDist = dist + edge.second;

            if (newDist < minDist[v])
            {
                minDist[v] = newDist;
                q.push({newDist, v});
            }
        }
    }
}

int main()
{
    int numNodes = 5; //Number of Vertices
    int nE = numNodes*(numNodes-1)/2;
    vector<vector<pair<int, int>>> adjList(nE + 1); // Adjacency list
    vector<int> minDist(numNodes + 1, INT_MAX);
    minDist[1] = 0;

    // adjList[1].emplace_back(2, 1);
    // adjList[1].emplace_back(3, 6);
    // adjList[2].emplace_back(3, 2);
    adjList[1].emplace_back(2, 30);
    adjList[1].emplace_back(3, 10);
    adjList[2].emplace_back(5, 10);
    adjList[3].emplace_back(4, 10);
    adjList[4].emplace_back(5, 10);


    dijkstra(numNodes, adjList, minDist);
    for (int i = 0; i <= numNodes; ++i)
    {
        cout << minDist[i] << endl;
    }
}
