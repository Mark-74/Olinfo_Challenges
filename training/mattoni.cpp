// Punti: 100.0
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<int> piles(n, 0);

    //query 1 : 3 -> 1 0 -1 0 0
    for(int i=0; i < m; i++){
        int l, r; cin >> l >> r;
        piles[--l]++;
        if(r != n) piles[r]--;
    }

    vector<int> f(n, 0);

    //calculating final situation
    f[0] = piles[0];
    for(int i=1; i< n; i++){
        f[i] = f[i-1] + piles[i];
    }

    nth_element(f.begin(), f.begin() + n/2, f.end());
    cout << f[n/2];
}
