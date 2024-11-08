// Punti: 60.0
    #include <bits/stdc++.h>
    using namespace std;
    int quadri(int N, long long M, int V[]){
        for(int i = 0; i < N; i++){
            if(V[i] > M){
                return 0;
            }
        }
        int B = N;
        for(int i = 0; i < N; i++){
            int current = V[i];
            bool flag = false;
            for(int j = 1; j < B && (i+j) < N; j++){
                current+= V[i+j];
                if(current > M){
                    B--;
                    flag = true;
                }
            }
            if(!flag && i == 0){
                break;
            }
        }
        return B;
    }