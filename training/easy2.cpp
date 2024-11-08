// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    //definire i dati
    int n, v1, v2, somma;
    int massimo=-1;

    //leggere l'input e salvalo dentro a n
    fin>>n;

    //ripetere n volte
    for(int i=0; i<n; i++)
    {
        //leggi input e mettilo dentro v1
        fin>>v1;
        //leggi input e mettilo dentro v2
        fin>>v2;

        //somma la coppia
        somma=v1+v2;

        //controllo se la somma e pari e se � maggiore del massimo
        if(somma%2==0 && somma>massimo)
        {
            //se pari e maggiore
            massimo=somma;
        }
    }

    //output
    fout<<massimo;

    return 0;
}
