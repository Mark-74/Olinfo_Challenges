// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, voto, sommaVoti, sommaVotiMax=0;
    int vincitoreRound;

    //leggere dal file quanti sono i ristoranti
    fin>>N;

    //per ogni
    for(int i=0; i<N; i++)
    {

        sommaVoti = 0; //ad ogni round resetto la somma dei voti


        //leggi tutti gli N+1 voti di ogni risoratore, calcola la somma

            for(int v=0; v<N+1; v++)
            {
                fin>>voto;
                sommaVoti+=voto;

            }
            sommaVoti+=1; //per annullare il -1 che ho letto prima
        //verifica chi � il vincitore
        if(sommaVoti>sommaVotiMax)
        {
            sommaVotiMax=sommaVoti;
            vincitoreRound=i+1;
        }

        //stampa il vincitore del round in file

        fout<<vincitoreRound<<endl;
    }



    return 0;
}
