// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    string Output;

    fin>>N;

    if(N%2==0)
    {
        Output="pari";
    }
    else
    {
        Output="dispari";
    }

    //output

    fout<<Output;

    return 0;
}
