// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt"); //InputFileStream = fin
    ofstream fout ("output.txt"); //OutputFileStream = fout


    //definire i dati
//per ogni dato devo definire il tipo e il nome
//ogni dato deve essere definito prima dui essere usato
    int n;
    int massimo = -1001; //definito il dato massimo e inizializzato il valore 1001
    int v;


    //leggere l'input e salvalo dentro a n
    fin>>n; //leggi fin e salva il suo valore in n

    //ripetere n volte qualcosa
    for(int i=0; i<n; i++) //definisci dato i e verifica la condizione, se vera esegui tra le parentesi e poi aggiungi 1 a i
    {
        //leggi input e salvalo dentro v
        fin>>v;

        //verificare se il valore di v � maggiore del valore di massimo
        if(v>massimo)
        {//se la condizione � vera
            massimo=v; //copia il valore di v dentro a massimo
        }
    }

    //output
    fout<<massimo;//scrivi il valore di massimo sul file


    return 0;
}
