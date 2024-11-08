// Punti: 100.0
#include <fstream>

using namespace std;

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N;
    long cost, M=0, S=0;

    fin>>N;

    for(int i=0; i<N; i++){
        fin>>cost;

        if(cost>M){
            S+=cost;
            M=cost;
        }
    }

    fout<<S;
    return 0;
}
