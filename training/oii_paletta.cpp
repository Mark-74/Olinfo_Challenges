// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
void update(int f[], int L, long long idx){ //changes f[idx] to 1
    while(idx <= L){
        f[idx] += 1;
        idx += idx&-idx; //add lsb
    }
}
long long sum(int f[], long long idx){ //get sum up to idx
    long long result = 0;
    
    while(idx >= 1){
        result += f[idx];
        idx -= idx&-idx; //sub lsb
    }
    return result;
}
long long paletta_sort(int N, int V[]) {
    vector<long long> p;
    vector<long long> d;
    for(long long i = 0; i < N; i++){
        if(i % 2 == 0){
            if(V[i] % 2 != 0) return -1;
            p.push_back(V[i]);
        }
        else
            d.push_back(V[i]);
            
    }
    long long result = 0;
    int fen[N+1];
    fill(fen, fen+N+1, 0);
    for(int i = p.size()-1; i >= 0; i--){
        result += sum(fen, p[i]+1);
        update(fen, N, p[i]+1);
    }
    fill(fen, fen+N+1, 0);
    for(int i = d.size()-1; i>= 0; i--){
        result += sum(fen, d[i]+1);
        update(fen, N, d[i]+1);
    }
    return result;
}