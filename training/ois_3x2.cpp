// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int N;
    long sTot=0;

    fin>>N;

    vector<int> l(N);

    for(int i=0; i<N; i++){
        fin>>l[i];
    }
    sort(l.begin(), l.end());

    for(int i=N-1; i>=0;i--){
        if((N-i)%3!=0){
            sTot+=l[i];
        }
    }

    fout<<sTot;

    return 0;
}
