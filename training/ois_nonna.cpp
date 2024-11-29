// Punti: 100.0
#include <stdio.h>
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000
int P[MAXN];
int N, K;
vector<vector<int>> m;
int dp(int status, int index){
    if(status >= K)
        return status;
    //siamo usciti dal range e non siamo ancora arrivati a K.
    if(index == N)
        return INT_MAX; //il risultato deve essere ignorato
    
    //check se risultato già calcolato
    if(m[index][status] != -1)
        return m[index][status];
    
    int mangio, non_mangio;
    mangio = dp(status + P[index], index + 1);
    non_mangio = dp(status, index + 1);
    m[index][status] = min(mangio, non_mangio);
    
    return min(mangio, non_mangio);
}
int mangia(int N, int K, int P[]) {
    m = vector<vector<int>> (N, vector<int>(10000, -1));
    return dp(0, 0);
}
int main() {
    FILE *fr, *fw;
    int i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));
    fprintf(fw, "%d\n", mangia(N, K, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
