// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N, v, precedente;
    int somma = 0;

    fin>>N;

    for(int i=0; i<N; i++)
    {
        fin>>v;
        if(v == -1)
        {
            v = precedente;
        }
        precedente = v;
        somma += v;
    }

    fout<<somma;


    return 0;
}
