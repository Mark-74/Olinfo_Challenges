// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    long R,C,K, nR, nC, output = 0;

    fin>>R>>C>>K;

    if(C%K==0){
        nR = C/K;
    } else {
        nR = (C/K)+1;
    }

    if(R%K==0){
        nC = R/K;
    } else {
        nC = (R/K)+1;
    }

    output = nR*nC;

    fout<<output;


    return 0;
}
