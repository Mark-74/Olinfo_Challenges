// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;


int main()
{
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");

	int n, val;

    vector<int> valoriImpianti;

	fin>>n;


	for(int i=0; i<n; i++)
    {
        fin>>val;

        valoriImpianti.push_back(val);

    }

    int pos;
    for(int i =0; i<n; i++)
    {
        pos=i+1;
        int energia=valoriImpianti[i];
        //verifico se posso raggiungere i distributori dopo di me
        for(int j=i+1; j<n&&energia>=10; j++)
        {
            energia = energia-10+valoriImpianti[j];
        }
        if(energia>=10)
        {
            //verifico se posso raggiungere i distributori prima di me
            for(int j=0; j<i&&energia>=10; j++)
            {
                energia = energia-10+valoriImpianti[j];
            }
            if(energia==10)
            {
                fout<<pos;
                return 0;
            }
        }

    }


    return 0;
}
