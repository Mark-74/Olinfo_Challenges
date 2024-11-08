// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int fastExp(int base, int exp, int N){
    if(exp == 0) return 1;
    long long res = fastExp(base, exp/2, N);
    res = (res * res) % N;
    if(exp % 2 == 1){
        res = (res * base) % N;
    }
    return res;
}
void decifra(int N, int d, int L, int messaggio[], char plaintext[]){
    for(int i = 0; i < L; i++){
        int c = messaggio[i];
        plaintext[i] = (char)fastExp(c, d, N);
    }
    plaintext[L] = '\0';
}