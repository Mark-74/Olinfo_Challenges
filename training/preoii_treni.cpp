// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix;
int trova_massimo(int N, int a[], int b[], int current, int saltato){
    if(current >= N) return 0;
    if(matrix[current][saltato] != -1) return matrix[current][saltato];
    if(saltato == 1){
        matrix[current][saltato] = max({trova_massimo(N, a, b, current+1, 0) + a[current],
                                        trova_massimo(N, a, b, current+1, 0) + b[current],
                                        trova_massimo(N, a, b, current+1, 1)}); 
    } else {
        matrix[current][saltato] = max({trova_massimo(N, a, b, current+1, 0) + a[current],
                                        trova_massimo(N, a, b, current+1, 1)});
    }
    return matrix[current][saltato];
}
int tempo_massimo(int N, int a[], int b[])
{
    matrix.resize(N, (vector<int>(2, -1)));
    int result = trova_massimo(N, a, b, 0, 1);
    
    return result;
}
