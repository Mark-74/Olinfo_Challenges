// Punti: 10.0
#include <bits/stdc++.h>

using namespace std;


int main()
{
    //definito gli oggetti per leggere/scrivere il file
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int number, N, lenght, newNumber=0;

    fin>>number;
    N = number;

    for(int i = 1; i<100; i++){

        int temp = N/pow(10,i);

        if(temp == 0){

            lenght = i;
            i = 100;
        }
    }

    for(int i=lenght-1; i>=0; i--){

        cout<<"N: "<<N<<endl;

        int digit = N/pow(10, i);
        bool sensed = true;

        N -= digit * pow(10, i);

        cout<<"digit: "<<digit<<endl;

        if(digit == 5){
            digit = 2;
        } else if (digit == 6){
            digit = 9;
        } else if (digit == 1){
            digit = 1;
        } else if (digit == 9){
            digit = 6;
        } else if (digit == 2){
            digit = 2;
        } else if (digit == 1){
            digit = 1;
        } else if (digit == 8){
            digit = 8;
        } else if (i == 0 && digit == 0){
            sensed = false;
        } else if (digit == 0){
            digit = 0;
        } else {
            sensed = false;
        }

        newNumber += digit * pow(10, lenght-i-1);

        cout<<"newNumber: "<<newNumber<<endl;


        if(sensed == false){
            i = -1;
            newNumber = number;
            cout<<"not sensed "<<endl;
        }

    }

    if(newNumber > number){
        newNumber = number;
    }

    cout<<"result: "<<newNumber;

    fout<<newNumber;

    return 0;
}
