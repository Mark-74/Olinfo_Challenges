// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin >> N;
    vector<int> L(N);
    vector<vector<int>> M(N);
    queue<int> q;
    int result = 0;
    //read L
    for(int i = 0; i<N; i++){
        int j;
        fin >> j >> L[i];
        if(L[i] == 0){
            q.push(i);
            result++;
        }
        //read friends
        for(int k = 0; k<j; k++){
            int new_friend;
            fin >> new_friend;
            M[new_friend].push_back(i); //reversed direction
        }
    }
    //BFS
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        //cycle through friends
        for(int i : M[cur]){
            //if(L[M[cur][i]] == 0) continue; //if already visited
            if(--L[i] == 0){ //if friend reaches 0 friends requested
                result++;
                q.push(i);
            }
        }
    }
    fout << result;
}
