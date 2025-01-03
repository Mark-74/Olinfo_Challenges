// Punti: 100.0
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
vector<long long>dp, calc, last;
long long calculate(int pos, int prev){
    long long tot = 0, maxi = 0;
    for(int i : v[pos]){
        if(i == prev) continue;
        long long a = (dp[i] == -1 ? calculate(i, pos) : dp[i]);
        tot += a;
        if(a > maxi){
            maxi = a;
            last[pos] = i;
        }
    }
    return dp[pos] = tot - maxi + 1;
}
void find(int pos, int prev){
    long long l1 = -1, l2 = -1;
    if(prev == -1)
        calc[pos] = calculate(pos, prev);
    else{
        l1 = last[prev];
        l2 = last[pos];
        // calculate prev
        if(last[prev] == pos){
            dp[prev] = dp[pos] = -1;
            calculate(prev, pos);
        }
        else
            dp[prev] -= dp[pos];
        // calculate pos
        if(l1 == pos)
            calc[pos] = calculate(pos, -1);
        else if(l2 != -1 && dp[l2] < dp[prev])
            calc[pos] = (dp[pos] += dp[l2]);  
        else
            calc[pos] = calculate(pos, -1);
    }
    for(int i : v[pos]){
        if(i == prev) continue;
        if(calc[i] != -1) continue;
        long long a = dp[pos], b = dp[i];
        find(i, pos);
        dp[pos] = a; dp[i] = b;
    }
    if(l1 != -1 && l2 != -1){
        last[prev] = l1;
        last[pos] = l2;
    }
}
int main(){
    int n; cin >> n;
    v.resize(n);
    dp.resize(n, -1);
    calc.resize(n, -1);
    last.resize(n, -1);
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    find(0, -1);
    for(int i=0; i<n; i++)
        cout << calc[i] << " ";
    return 0;
}