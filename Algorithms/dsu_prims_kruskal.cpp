#include <bits/stdc++.h>
using namespace std;

int dsu_find(int u, vector<int>& parent){
    if(u == parent[u])
        return u;
    parent[u] = dsu_find(parent[u], parent);
    return parent[u];
}

void dsu_union(int u, int v, vector<int>& parent){
    parent[v] = u;
}


typedef pair<int, int> IPair;
typedef pair<int, IPair> IIPair;

int kruskal(int N, vector<vector<int>>edges, vector<int>& parent){
    priority_queue<IIPair, vector<IIPair>, greater<IIPair>> minHeap;
    for(auto&e : edges){
        minHeap.emplace(make_pair(e[2], make_pair(e[0], e[1])));
    }
    int min_cost = 0;
    while(!minHeap.empty()){
        auto [cost, edge] = minHeap.top();
        minHeap.pop();
        auto [u, v] = edge;
        int uP = dsu_find(u, parent);
        int vP = dsu_find(v, parent);
        if(uP != vP){
            min_cost += cost;
            dsu_union(uP, vP, parent);
        }
        
    }
    return min_cost;    
}

int prims(int N, vector<vector<int>>edges){
    vector<bool>visited(N+1, false);

    vector<IPair> adj[N+1];
    for(auto& e:edges){
        adj[e[0]].emplace_back(e[1], e[2]);
        adj[e[1]].emplace_back(e[0], e[2]);
    }

    priority_queue<IIPair, vector<IIPair>, greater<IIPair>> minHeap;
    minHeap.emplace(0, make_pair(0, 1));
    visited[0] = true;

    int min_cost = 0;
    while(!minHeap.empty()){
        auto[cost, edge] = minHeap.top();
        minHeap.pop();
        auto [u, v] =  edge;
        if(visited[v])
            continue;
        visited[v] = true;
        min_cost += cost;
        for(auto& [v2, c] : adj[v])
            minHeap.emplace(c, make_pair(v, v2));
    }
    return min_cost;
}

int main(){
    int N = 6;
    vector<pair<int, int>> edges{{1,2}, {2,3}, {4,5}};

    vector<vector<int>>edges2{{1, 2, 7}, {1, 6, 8}, {2, 3, 6}, {2, 6, 3}, {3, 5, 2}, {3, 6, 4}, {3, 4, 5}, {5, 4, 5}, {6, 5, 3}};


    vector<int> parent(N+1);
    for(int i = 1; i<=N; ++i)
        parent[i] = i;

    // for(auto& [u, v] : edges){
    //     int uP = dsu_find(u, parent);
    //     int vP = dsu_find(v, parent);
    //     if( uP != vP){
    //         dsu_union(uP, vP, parent);
    //     }
    // }

    for(int i=1; i<=N; ++i)
        cout<<i<<": "<<parent[i]<<endl;

    cout<<kruskal( N, edges2, parent)<<endl;
    cout<<prims( N, edges2)<<endl;
}