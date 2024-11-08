// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int trova_massimo(int N, vector<int> V){
    int Max = V[0];
    for(int i = 1; i < N; i++){
        if(V[i] > Max) Max = V[i];
    }
    return Max;
}