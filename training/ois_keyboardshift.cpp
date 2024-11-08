// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int n;
    fin >> n;

    string sequence;
    fin >> sequence;
    vector<char> letters(sequence.begin(), sequence.end());

    string alphabet = "qwertyuiopasdfghjklzxcvbnm";
    vector<char> lAlphabet(alphabet.begin(), alphabet.end());


    for(int i = 0; i<n; i++)
    {
        for(int v = 0; v<26; v++)
        {
            if(letters[i] == lAlphabet[v])
            {
                fout<<lAlphabet[v+1];
            }
        }
    }

    return 0;
}
