// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    map<long long, int> m;
    long long n, distance, complete_distance;
    fin >> n >> distance >> complete_distance;
    for (int i = 0; i < n; i++)
    {
        long long pos;
        fin >> pos;
        if(pos - distance < 0){
            m[0] += 1;
        } else{
            m[pos - distance] += 1;
        }
        if(pos + distance + 1 <= complete_distance){
            m[pos + distance + 1] -= 1;
        }
    }
    long long count = 0, min_count = m[0];
    for(auto i : m){
        count += i.second;
        min_count = min(min_count, count);
        //fout << i.first << " " << i.second << " " << count << " " << min_count << endl;
    }
    fout << min_count << endl;
    return 0;
}
