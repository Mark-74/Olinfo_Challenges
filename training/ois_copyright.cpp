// Punti: 100.0
#include <bits/stdc++.h>

#define MAXN 1000010
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

//aggiorno stringa del copyriht e restituisco la lunghezza della nuova stringa
int update_copyright(int N, char S[]) {

    //converto array di char in string
    string copyrightString(S);

    //cerco una sottostringa per capire dove si trovano gli anni del copyright
    int posEnd = copyrightString.find(". All rights reserved.");

   //calcolo l'inizio dell'utlimo anno del copyright (l'unico che mi serve per cacpire cosa/come modificare
    int posStartLastYear =posEnd - 4;

    //estraggo dalla stringa l'ultimo anno del copyright (4 caratteri)
    string lastYear = copyrightString.substr(posStartLastYear, 4);

    //se ultimo anno diverso da 2017 --> devo aggiungere la stringa ,2018
    if (lastYear != "2017") {
        copyrightString.insert(posEnd, ", 2018"); // add ", 2018"
    }
    else // se ultimo anno 2017
    {
       //se ho un intervallo (lo capisco se prima dell'utlimo anno c'� un -) modifico 2017 in 2018
       if (copyrightString.substr(posStartLastYear - 1, 1) == "-")
           copyrightString[posStartLastYear + 3] = '8';
       else // ho 2017 come anno singolo lo trasformo in un interallo 2017-2018, quindi aggiungo -2018
           copyrightString.insert(posEnd, "-2018");
    }

    //modifico arry di caratteri con la stringa aggiornata
    strcpy(S, copyrightString.c_str());
    //restituisco lunghezza della stringa aggiornata
    return copyrightString.length();
}


char S[MAXN];

int main() {

    int N, i;

    fin >> N;

    //per leggere correttamente input (spazi bianchi e a capo)
    fin >> std::noskipws;

    //leggo carattere per carattere
    for(i=0; i<N; i++)
    {
        fin >> S[i];

    }


    N = update_copyright(N, S);


    //output
    fout << N;
    for(i=0; i<N; i++)
        fout << S[i];


    return 0;
}