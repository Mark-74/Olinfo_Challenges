// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
    int n, m;
    fin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fin >> matrix[i][j];
        }
    }
    int islands = 0;
    queue<pair<int, int>> daVisitare;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 1){
                daVisitare.push(make_pair(i, j));
                bool flag = true;
                matrix[i][j] = 0;
                if(i == 0 || i == n-1 || j == 0 || j == m-1) flag = false;
                
                while(!daVisitare.empty()){
                    pair<int, int> attuale = daVisitare.front();
                    daVisitare.pop();
                    if(attuale.first != 0 && matrix[attuale.first-1][attuale.second] == 1){
                        if(attuale.first - 1 == 0) flag = false;
                        matrix[attuale.first-1][attuale.second] = 0;
                        daVisitare.push(make_pair(attuale.first-1, attuale.second));
                    }
                    if(attuale.first != n-1 && matrix[attuale.first+1][attuale.second] == 1){
                        if(attuale.first + 1 == n-1) flag = false;
                        matrix[attuale.first+1][attuale.second] = 0;
                        daVisitare.push(make_pair(attuale.first+1, attuale.second));
                    }
                    if(attuale.second != 0 && matrix[attuale.first][attuale.second-1] == 1){
                        if(attuale.second - 1 == 0) flag = false;
                        matrix[attuale.first][attuale.second-1] = 0;
                        daVisitare.push(make_pair(attuale.first, attuale.second-1));
                    }
                    if(attuale.second != m-1 && matrix[attuale.first][attuale.second+1] == 1){
                        if(attuale.second + 1 == m-1) flag = false;
                        matrix[attuale.first][attuale.second+1] = 0;
                        daVisitare.push(make_pair(attuale.first, attuale.second+1));
                    }
                }
                if(flag){
                    islands++;
                }
                
            }
        }
    }
    fout << islands << endl;
}