#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> IPair;
typedef pair<int, IPair> IIPair;

vector<int> dijkstra(int N, vector<vector<int>> edges, int s){

    vector<IPair>adj[N+1];
    for(auto& e: edges){
        adj[e[0]].emplace_back(e[1], e[2]);
        adj[e[1]].emplace_back(e[0], e[2]);
    }

    unordered_map<int, int>pathCost;
    // pathCost[s] = 0;
    // for(int i = 0; i<=N; ++i){
    //     pathCost[i] = -1;
    //     if(i == s)
    //         pathCost[i] = 0;
    // }


    priority_queue<IPair, vector<IPair>, greater<IPair>> minHeap;
    minHeap.emplace(0, s);
    while(!minHeap.empty()){
        auto [cost , v] = minHeap.top();
        minHeap.pop();

        if(pathCost.count(v))
            continue;

        pathCost[v] = cost;
        for(auto& [newV, c] : adj[v]){
            minHeap.emplace(c + cost, newV);
        }

        if(pathCost.size() == N)
            break;
    }

    vector<int> ans(N+1, -1);

    for(int i=1; i<=N; ++i){
        if(pathCost.count(i))
            ans[i] = pathCost[i];        
    }
    return ans;
}

int main(){
    vector<vector<int>> edges{{1, 2, 7}, {1, 6, 8}, {2, 3, 6}, {2, 6, 3}, {3, 5, 2}, {3, 6, 4}, {3, 4, 5}, {5, 4, 5}, {6, 5, 3}};
    int n = 6;
    vector<int> dist = dijkstra(n, edges, 1);
    for (int i = 1; i <= n; ++i)
        cout << i << " : " << dist[i] << endl;
}
