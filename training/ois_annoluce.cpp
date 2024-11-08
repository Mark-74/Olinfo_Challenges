// Punti: 40.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N, Q, X, Y, Z, years, result;
    fin>>N;

    vector<double> starsDistance (N);


    for(int i=0; i<N; i++){
        fin>>X>>Y>>Z;
        double distance = sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
        starsDistance[i] = distance;

    }

    sort(starsDistance.begin(), starsDistance.end());

    fin>>Q;


    for(int i=0; i<Q; i++){

        result = 0;
        fin>>years;


        for(int j=0;years>=starsDistance[j] && j<N; j++){

            result ++;
        }

        fout<<result<<endl;
    }



    return 0;
}

