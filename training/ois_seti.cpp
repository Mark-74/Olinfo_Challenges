// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<long long> memo;
long long mod = 1e9+7;
int f(int i){
    //passo base
    if(i < 0) return 1;
    if(memo[i] != -1) return memo[i];
    //accendere antenna i
    long long a = f(i - v[i] -1) % mod;
    //spegnere antenna i
    long long s = f(i-1) % mod;
    return memo[i] = (a + s) % mod;
}
int main(){
    int N;
    cin >> N;
    v.resize(N);
    memo.resize(N, -1);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    cout << f(N-1) << endl;    
    return 0;
}