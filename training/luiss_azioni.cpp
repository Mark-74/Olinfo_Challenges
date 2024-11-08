// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N,fMax=0;
    fin>>N;

    int Q[N];

    for(int i=0; i<N; i++){
        fin>>Q[i];
    }

    for(int i=0; i<N-1; i++){
        if(abs(Q[i]-Q[i+1])>fMax){
            fMax=abs(Q[i]-Q[i+1]);
        }
    }



    fout<<fMax;


    return 0;
}
