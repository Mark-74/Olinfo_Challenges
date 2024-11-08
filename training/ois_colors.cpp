// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int N, K;
    fin >> N >> K;
    vector<int> groups(N, 0);
    long long result = 1;
    long long mod = 1e9+7;
    for(int i = 0; i < N; i++){
        int in;
        fin >> in;
        if(in == 0){
            groups[0]++;
            result = (result * K--) % mod;
        } else{
            result = (result * groups[in-1]) % mod;
            groups[in]++;
            groups[in-1]--;
        }
    }
    fout << result;
        
}