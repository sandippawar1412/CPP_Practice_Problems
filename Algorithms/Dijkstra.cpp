#include <bits/stdc++.h>
using namespace std;

void dijkstra(int N, vector<vector<pair<int, int>>> &adjList, vector<int> &minDist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, 1);

    while (!q.empty())
    {
        auto [u, dist] = q.top();
        q.pop();

        if (dist > minDist[u])
            continue;

        for (auto &[v, d] : adjList[u])
        {            
            if (dist + d < minDist[v])
            {
                minDist[v] = dist + d;
                q.emplace(dist+d, v);
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
