// Punti: 38.0
#include <bits/stdc++.h>
using namespace std;
int main() {
  // definito gli oggetti per leggere/scrivere il file
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int racers, overtakings, overtakingCar, overtakenMost, maxTimes = 0;
  fin >> racers >> overtakings;
  vector<int> positions(racers);
  for (int i = 0; i < racers; i++) {
    fin >> positions[i];
  }
  vector<int> overtakenTimes(racers); // i = carNumber-1
  
  for (int i = 0; i < racers; i++) {
    overtakenTimes[i] = 0;
  }
  //positions update
  for (int i = 0; i < overtakings; i++) {
    fin >> overtakingCar;
    // overtaking
    int position = std::find(positions.begin(), positions.end(), overtakingCar) - positions.begin();
    int overtaken = positions[position - 1];
    positions[position - 1] = positions[position];
    positions[position] = overtaken;
    // adding overtaken value
    overtakenTimes[overtaken - 1]++;
    // printing the car that has been overtaken the most
    for (int j = 0; j < racers; j++) {
      if (maxTimes < overtakenTimes[j]) {
        overtakenMost = j + 1;
        maxTimes = overtakenTimes[j];
      } else if(maxTimes == overtakenTimes[j]){
        if(overtakenMost > j+1){ overtakenMost = j+1;}
      }
    }
    // output
    fout << overtakenMost << endl;
  }
}
