// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int distance, jumps=0;

    fin>>distance;

    for(int i=0; distance > 0; i++){
        if(distance-pow(2,i)<0){
            distance-=pow(2,i-1);
            jumps++;
            i=0;
            if(distance == 1){
                distance-=1;
                jumps++;
            }

        }
    }



    fout<<jumps;

    return 0;
}
