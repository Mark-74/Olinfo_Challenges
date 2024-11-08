// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    for(int i = 0; i < N; i++){
        D[i] = INF;
    }
    vector<vector<pair<int, int>>> graph(N);
    for(int i = 0; i < M; i++){
        graph[X[i]].push_back({Y[i], P[i]});
    }
    //Dijkstra
    vector<bool> vis(N);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    D[0] = 0;
    q.push({0, 0});
    while (!q.empty())
    {
        auto [dist, cur] = q.top();
        q.pop();
        if(vis[cur]) continue;
        // update visited
        vis[cur] = true;
        for (pair<int, int> i : graph[cur])
        {
            if(D[i.first] > dist + i.second){
                q.push({dist + i.second, i.first});
                D[i.first] = dist + i.second;
            }
        }
    }
    for(int i = 0; i < N; i++)
        if(D[i] == INF) D[i] = -1;
}
