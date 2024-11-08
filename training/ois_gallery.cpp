// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main() {
  int N;
  fin >> N;
  vector<pair<int, int>> points(N);
  for(int i = 0; i < N; i++)
    fin >> points[i].first >> points[i].second;
  sort(points.begin(), points.end());
  set<pair<int, int>> signorS;
  for(auto [x, y] : points)
    signorS.insert({x, y});
  
  int half = N/2;
  long double medium = -1;
  for(int i = 0; i < half; i++){
    auto [x1, y1] = points[i];
    auto [x2, y2] = points[N-i-1];
    if(medium == -1) medium = (x1+x2) / 2;
    
    if(y1 != y2){
      if(signorS.count({x2, y1}) == 0)
        return fout << "NO", 0;
    }
    if((x1+x2) / 2 != medium)
      return fout << "NO", 0;
  }
  if(N%2 == 1 && points[half].first != medium)
    return fout << "NO", 0;
  
  fout << "YES";
}
