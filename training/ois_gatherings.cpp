// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin = ifstream("input.txt");
ofstream fout = ofstream("output.txt");
int main(){
    int n, minDistance;
    fin >> n >> minDistance;
    vector<int> values(n);
    for(int i = 0; i < n; i++){
        fin >> values[i];
    }
    int l = 0, r = 0;
    long long result = 0;
    for(; r < n; r++){
        if(values[r] - values[l] >= minDistance){
            r--;
            result += r - l;
            l++;
        }
    }
    while(r - l != 0){
        result += r - l - 1;
        l++;
    }
    fout << result;
}