// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int N, K, maxSum = -100000, sum = 0, last;
  fin >> N >> K;
  vector<int> muffins(N);
  for (int i = 0; i < N; i++) {
    fin >> muffins[i];
  }
  last = 0;
  for (int j = 0; j < K; j++) {
    sum += muffins[j];
  }
  maxSum = sum;
  for (int i = K; i < N; i++) {
    sum = sum - muffins[last] + muffins[i];
    last++;
    if (maxSum < sum) {
      maxSum = sum;
    }
  }
  fout << maxSum;
  return 0;
}