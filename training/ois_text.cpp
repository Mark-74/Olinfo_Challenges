// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int wordsNumber, maxLettersPerLine, lineLength=0;
    string word;

    fin>>wordsNumber>>maxLettersPerLine;

    vector<string>message(wordsNumber);
    for(int i=0; i<wordsNumber; i++){
        fin>>message[i];
    }

    for(int i=0; i<wordsNumber; i++){
        word= message[i];
        lineLength+=word.length() + 1;

        if(lineLength>maxLettersPerLine+1){
            fout<<endl<<message[i]<<" ";
            lineLength=word.length()+1;
        } else {
            fout<<message[i]<<" ";
        }



        }




    return 0;
}
