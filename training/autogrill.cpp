// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
set<long long> s;
void inizia() {
    return;
}
void apri(long long p) {
    s.insert(p);
}
void chiudi(long long p) {
    s.erase(p);
}
long long chiedi(long long p) {
    if(s.empty())
        return -1;
    
    if(s.count(p) == 1)
        return p;
    auto lower = prev(s.lower_bound(p));
    auto upper = s.upper_bound(p);
    if(lower == s.end())
        if(upper == s.end())
            return -1;
        else
            return *upper;
    
    if(upper == s.end())
        return *lower;
    if(abs(p - *lower) < abs(p - *upper))
        return *lower;
    else
        return *upper;
}