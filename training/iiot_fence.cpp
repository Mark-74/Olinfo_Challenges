// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    int N;
    fin >> N;
    vector<long long> fence(N);
    vector<pair<int,int>> max_suffix(N);
    for(int i = 0; i < N; i++){
        fin >> fence[i];
    }
    pair<int,int> _lastmax = {fence[N-1], N-1};
    for(int i = N-1; i >= 0; i--){
        if(fence[i] > _lastmax.first){
            _lastmax.first = fence[i];
            _lastmax.second = i;
        }
        max_suffix[i] = _lastmax;
    }
    for(int current = 0; current < N-1; current++){
        long long _max = current +1;
        bool found = false;
        for(int j = current+1; j < N; j++){
            if(max_suffix[j].first < fence[current]){
                _max = max_suffix[j].second;
                break;
            }
            if(fence[j] > fence[_max]){
                _max = j;
            }
            if (fence[j] > fence[current]){
                _max = j;
                found = true;
                break;
            }
        }
        for(int j = current+1; j < _max; j++){
            fence[j] = -1;
        }
        current = _max-1;
    }
    long long result = 0;
    int sx = 0;
    for(int i = 1; i < N; i++){
        if(fence[i] != -1){
            result += (i - sx)*min(fence[sx], fence[i]);
            sx = i;
        }
    }    
    fout << result << endl;
}