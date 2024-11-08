// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int n, m, a, b;
    fin >> n >> m >> a >> b;
    if(b / m >= a){
        fout << n * a;
        return 0;
    }
    //a questo punto il carnet è più conveniente del biglietto singolo
    long long result = 0;
    for(int i = 0; i < n/m; i++){
        result += b;
    }
    result += (n % m) * a > b ? b : (n % m) * a;
    fout << result;
}