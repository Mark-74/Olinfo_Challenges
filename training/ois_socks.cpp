// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int n, c, colore;

    unordered_map<int,int> calzini;
    fin>>n>>c;

     long scambi = 0;
     int nColori=0;

    //per ogni calzino della lista

    for(int i=0; i<n; i++){

        //leggo il colore

        fin>>colore;

        //cerco il colore nella mappa

        auto it = calzini.find(colore);

        //se il colore non c'è

        if(it == calzini.end()){
            //dovrò aggiungere il colore alla mappa
            calzini.insert(make_pair(colore, nColori));
            //aggiornare il valore degli scambi

            scambi += nColori;

            //aggiornare il numero di colori presenti nella mappa

            nColori ++;
        }
    else {
        //altrimenti
            //aggiornare il valore dgli scambi

            scambi += it ->second;
    }



    }


    //output numero degli scambi
    fout<<scambi;

    return 0;
}
