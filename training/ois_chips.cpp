// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int T, R, G, B, A, C, PointsR, PointsG, PointsB;
    int maxP;

    fin>>T;

    for(int i=0; i<T; i++){
        fin>>A;
        fin>>C;
        fin>>R;
        fin>>G;
        fin>>B;

        PointsR = A*((R+1)*(R+1)+G*G+B*B)+C*min({R+1,G,B});
        PointsG = A*(R*R+(G+1)*(G+1)+B*B)+C*min({R,G+1,B});
        PointsB = A*(R*R+G*G+(B+1)*(B+1))+C*min({R,G,B+1});

        maxP = max({PointsR,PointsG,PointsB});

        if(maxP == PointsR){
            fout<<"RED"<<endl;
        }
        else{
            if(maxP == PointsG){
                fout<<"GREEN"<<endl;
            }
            else{
                fout<<"BLUE"<<endl;
            }
        }


    }

    return 0;
}
