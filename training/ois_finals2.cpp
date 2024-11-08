// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main() {
  // definito gli oggetti per leggere/scrivere il file
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int N, P, max = 0, current, points = 0, addPoints;
  fin >> N >> P;
  for (int i = 0; i < 3; i++) {
    fin >> addPoints;
    points += addPoints;
  }
  // squadre
  for (int i = 0; i < N - 1; i++) {
    current = 0;
    // colonne
    for (int j = 0; j < 3; j++) {
      fin >> addPoints;
      current += addPoints;
    }
    current += P * 100;
    if (current > max) {
      max = current;
    }
  }
  if (points > max) {
    fout << 0;
  } else {
    fout << max - points + 1;
  }
}
