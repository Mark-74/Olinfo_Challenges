// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int A, B, N, sum;
    fin >> A >> B >> N;
    sum = A+B;

    vector<int> classifica(N);
    vector<int> punti(N);

    for(int i = 0; i < N; i++){
        fin >> classifica[i];
    }

    for(int i = 0; i < N; i++){
        fin >> punti[i];
    }

    sort(classifica.begin(), classifica.end());
    sort(punti.begin(), punti.end());

    int offset_right = 1, offset_left = 0, offset = 0;

    //caso migliore
    for(int i = N-1; i >= 0; i--){
        if(classifica[i] > sum){
            offset_right++;
            offset++;
            continue;
        }

        if(classifica[i] + punti[offset_left] > sum){
            offset_right++;
        } else {
            offset_left++;
        }

        if(classifica[i] + punti[N-offset_right] <= sum)
            break;
    }

    fout << offset_right << ' ';

    //caso peggiore
    offset_right = 1;
    for(int i = 0; i < N - offset; i++){
        if(classifica[i] + punti[N-offset_right] > sum){
            offset_right++;
        }
    }

    offset_right += offset;
    fout << offset_right;


    return 0;
}
