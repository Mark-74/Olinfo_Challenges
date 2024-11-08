// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N;
    fin>>N;
    long sum=N;

    vector<long> Scores(N);

    for(int i=0; i<N; i++){
        fin>>Scores[i];
    }

    sort(Scores.begin(), Scores.end());

    for(int i=1; i<N; i++){
        if(Scores[i]>Scores[i-1]){
            sum+=N-i;
        }
    }

    fout<<sum;

    return 0;
}
