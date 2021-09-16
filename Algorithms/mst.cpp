#include <bits/stdc++.h>
using namespace std;

//Consider starts from 1 than 0
int prims2(int n, vector<vector<int>> edges){
    //adj[0] will be empty, u->v, cost
    vector<vector<pair<int, int>>>adj(n + 1);
    for(auto& edge: edges){
        adj[edge[0]].emplace_back(edge[1], edge[2]);
        adj[edge[1]].emplace_back(edge[0], edge[2]);
    }

    //pq, cost->u, v
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    vector<bool> visited(n+1, false);
    
    int mst_cost = 0;

    //dummy edge 0 -> 1 with 0 cost
    minHeap.emplace(0, make_pair(0, 1));

    while(!minHeap.empty()){
        auto p = minHeap.top();
        minHeap.pop();
        int e_cost = p.first;
        auto e = p.second;
        if(visited[e.second] == true)
            continue;
        
        cout<<"Visited: "<<e.second<<endl;
        visited[e.second] = true;
        mst_cost += e_cost;
        
        for(auto& edge: adj[e.second])
            minHeap.emplace(edge.second, make_pair(e.first, edge.first));

    }
    return mst_cost;
}

int main(){
    // vector<vector<int>> edges{{1,2,5},{2,3,5}, {0,1,5}, {0,4, 3}, {1,4,1}};
    // int n = 5;

    // vector<vector<int>> edges{{0,1,7},{0,5,8}, {1,2,6}, {1,5,3}, {2,4,2}, {2,5,4}, {2,3,5}, {4,3,5}, {5,4,3}};
    // int n = 6;

    vector<vector<int>> edges{{1,2,7},{1,6,8}, {2,3,6}, {2,6,3}, {3,5,2}, {3,6,4}, {3,4,5}, {5,4,5}, {6,5,3}};
    int n = 6;
    int mst_cost = prims(n, edges);
    
    cout<<"Cost: "<< mst_cost<<endl;
     return 0;
}


