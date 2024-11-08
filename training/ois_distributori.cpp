// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N, M, K;
    int kmFatti = 0;
    int output = 0;

    fin>>N>>M>>K;
    vector<int>d(N);

    for(int i=0; i <N; i++){
        fin>>d[i];
        if(M < d[i] - kmFatti){
            output +=1;
            kmFatti=d[i-1];
        }
    }
    if(M < K - kmFatti){
        output += 1;
    }

    fout<<output;

    return 0;
}
