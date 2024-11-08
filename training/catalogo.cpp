// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;
map<long long, int> catalogo;
void aggiungi(long long int id){
    catalogo[id]++;
}
void togli(long long int id){
    catalogo[id]--;
}
int conta(long long int id){
    return catalogo[id];
}