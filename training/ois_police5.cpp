// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
    int N, M, T;
    fin >> N >> M >> T;
    vector<vector<pair<long long, pair<int, bool>>>> graph(N);
    for (int i = 0; i < M; i++)
    {
        long long source, dest, cost, explodes;
        fin >> source >> dest >> cost >> explodes;
        graph[source].push_back({cost, {dest, explodes}});
        // graph[dest].push_back({cost, {source, explodes}});
    }
    // pair<cost, pair<dest, explodes>>
    // Dijkstra
    vector<bool> vis(N, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        auto [dist, cur] = q.top();
        q.pop();
        if (vis[cur])
            continue;
        // update visited
        vis[cur] = true;
        if (cur == N - 1)
            return fout << dist, 0;
        for (auto i : graph[cur])
        {
            if (i.second.second && dist + i.first > T)
                continue;
            q.push({dist + i.first, i.second.first});
        }
    }
    fout << -1;
}