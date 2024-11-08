// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int n;
    fin >> n;
    long long sum = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        fin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    int counter;
    for(counter = 0; sum <= 0; counter++){
        sum -= 2*v[counter];
    }
    fout << counter << endl;
}