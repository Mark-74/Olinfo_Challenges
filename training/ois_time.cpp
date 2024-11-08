// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int Hd, Hs, Md, Ms, Hf, Check = 0, Mf;

    fin>>Hd>>Md>>Hs>>Ms;

    Mf = 60-Md+Ms;
    if(Mf >= 60){
        Check = 1;
        Mf = Mf-Check*60;
    }

    Hf=23-Hd+Hs + Check;

    if(Hf >= 24){
        Hf-=24;
    }

    fout<<Hf<<" "<<Mf;



    return 0;
}
