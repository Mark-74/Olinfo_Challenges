// Punti: 100.0
#include <vector>
using namespace std;
long long mod = 1e9+7;
// int modulo_neg(long long val, int n){
//     return ((val % n) + n) % n;
// }
vector<int> execute(int N, int K, int D, vector<int> A) {
    //passo base
    if(K == 1) return A;
    vector<int> prev = execute(N, K/2, D, A);
    vector<int> cur(N, 1);
    for(int i = 0; i < N; i++){
        int pos = (i - (long long)D * (K / 2)) % N;
        if(pos < 0) pos = (pos + N) % N;
        cur[i] = ((long long)prev[i] * prev[pos]) % mod;
    }
    if(K%2 != 0){
        for(int i = 0; i < N; i++){
            int pos = (i - (long long)D * (K-1)) % N;
            if(pos < 0) pos = (pos + N) % N;
            cur[i] = ((long long)cur[i] * A[pos]) % mod;
        }
    }
    return cur;
    /*
    5 4 2
    3 1 5 1 2
    
    start       1           2             3              4               5 
    A 3 1 5 1 2 | 1 2 3 1 5 | 1 5  1 2  3 | 2  3  1 5  1 | 5  1  2  3  1 |  3  1  5  1  2
    B 1 1 1 1 1 | 3 1 5 1 2 | 3 2 15 1 10 | 3 10 15 2 30 | 6 30 15 10 30 | 30 30 30 30 30
    N=5 K=4 D=2
    0, 1, 2, 3, 4
    0, 1, 2, 3, 4 K=1
    0*3, 1*4, 2*0, 3*1, 4*2 K=2
    0*3*1, 1*4*2, 2*0*3, 3*1*4, 4*2*0 K=3
    0*3*1*4, 1*4*2*0, 2*0*3*1, 3*1*4*2, 4*2*0*3 K=4
    …
    */
}
