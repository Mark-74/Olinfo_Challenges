// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> graph;
void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<long long>& D) {
    //build graph
    graph.resize(N, vector<pair<int, int>>());
    for(int i = 0; i < M; i++){
        graph[X[i]].push_back({P[i], Y[i]});
    }
    D.clear();
    D.resize(N, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto [cost, cur] = q.top();
        q.pop();
        //already visited
        if(D[cur] != -1)
            continue;
        
        D[cur] = cost;
        for(auto [c, dest] : graph[cur]){
            q.push({cost + c, dest});
        }
    }
}