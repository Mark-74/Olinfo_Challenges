// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main(){
    //double because of integer division :(
    long double N;
    fin >> N;
    long double result = N*(N-1) / 4;
    fout << result;
        
}