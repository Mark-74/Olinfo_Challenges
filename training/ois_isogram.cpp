// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int N = 0, result = 0;
	fin >> N;
	map<char, int> dict;
	bool flag = true;
	string bigballs = "";
	getline(fin, bigballs);
	for(int i = 0; i < N; i++){
		string frase = "";
		getline(fin, frase);
		for(int z = 0; z < frase.size(); ++z){
			if(((int)frase[z] < 32 || (int)frase[z] > 64) && ++dict[tolower(frase[z])] > 2){
				flag = false;
				break;
			}
		}
		if(flag)
			result++;
		
		dict.clear();
		flag = true;
	}
	fout << result << endl;
}