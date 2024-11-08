// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int G;
    fin >> G;
    for (int i = 0; i < G; i++){
        long long N;
        fin >> N;
        fout << 2 * (N - (1ll << (63 - __builtin_clzll(N)))) + 1 << endl;
    }
}