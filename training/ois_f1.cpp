// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N, hTot=0, vTot=0;

    fin>>N;

    vector<int> H(N);
    vector<int> V(N);

    for(int i=0; i<N; i++){
        fin>>H[i];
        hTot += H[i];
    }

    for(int i=0; i<N; i++){
        fin>>V[i];
        vTot += V[i];
    }

    if(vTot<hTot){
        fout<<"Verstappen"<<endl;
    } else {
        fout<<"Hamilton"<<endl;
    }


    sort(H.begin(), H.end());
    sort(V.begin(), V.end());

    if(H[0]<V[0]){
        fout<<"Hamilton";
    } else {
        fout<<"Verstappen";
    }

    return 0;
}
