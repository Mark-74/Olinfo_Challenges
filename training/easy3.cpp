// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int n, Numero, sommaPari = -1, sommaDispari = -1;
    int massimo=-1;
    int P1 = -1;
    int P2 = -1;
    int D1 = -1;
    int D2 = -1;

    fin>>n;

    //trovare i 2 numeri pari pi� grandi e sommarli
    for(int i=0; i<n; i++)
    {
        fin>>Numero;

        if(Numero%2==0)
        {
            if(Numero>P1)
            {
                P2 = P1;
                P1 = Numero;
            }
            else{
                if(Numero>P2)
                {
                    P2 = Numero;
                }
            }
        }
        else{
            if(Numero>D1)
            {
                D2 = D1;
                D1 = Numero;
            }
            else{
                if(Numero>D2)
                    D2 = Numero;
            }
        }

    }

    if(P1 >= 0 && P2 >= 0){
        sommaPari=P1+P2;
    }
    if(D1 >= 0 && D2 >= 0){
        sommaDispari=D1+D2;
    }

    massimo = max(sommaPari, sommaDispari);

    fout<<massimo;

    return 0;
}
