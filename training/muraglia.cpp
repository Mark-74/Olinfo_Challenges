// Punti: 100.0
#include <utility>
#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
int n, padding;
int query_right(int node, int node_low, int node_high, int query_low, int query_high, int x){
    if(node_low > query_high || node_high < query_low) return -1;       //nodo non compreso nel range della query
    if(tree[node] <= x) return -1;                                      //nodo non comprende valori maggiori di x
    if(node_low == node_high) return node_low;
    int mid = (node_high + node_low) / 2;
    int left = query_right(2*node, node_low, mid, query_low, query_high, x);
    if(left != -1) return left;
    return query_right(2*node+1, mid +1, node_high, query_low, query_high, x);
}
int query_left(int node, int node_low, int node_high, int query_low, int query_high, int x){
    if(node_low > query_high || node_high < query_low) return -1;      //nodo non compreso nel range della query
    if(tree[node] <= x) return -1;                                     //nodo non comprende valori maggiori di x
    if(node_low == node_high) return node_low;
    int mid = (node_high + node_low) / 2;
    int right = query_left(2*node+1, mid +1, node_high, query_low, query_high, x);
    if(right != -1) return right;
    return query_left(2*node, node_low, mid, query_low, query_high, x);
}
pair<int, int> chiedi(int x) {
    int right = query_right(1, 0, n-1, x, n-1, tree[n+x]);
    if(right == -1) right = n - padding - 1;
    int left = query_left(1, 0, n-1, 0, x, tree[n+x]);
    if(left == -1) left = 0;
    return {left, right};
}
void cambia(int x, int h) {
    tree[n + x] = h;
    for(int i = (n + x)/2; i >= 1; i /= 2){
        tree[i] = max(tree[i*2], tree[i*2+1]);
    }
    return;
}
void inizializza(int N, vector<int> H) {
    //building the segment tree
    //making N a power of 2
    int i;
    for(i = 1; i < N;){
        i <<= 1;
    }
    padding = i - N;
    N = i;
    H.resize(N);
    /*
    while(__builtin_popcount(N) != 1) {
        N++;
        H.push_back(0);
    }
    */
    //resizing the tree accordingly
    tree.resize(2 * N);
    n = N;
    //filling the tree
    for(int i = 0; i < N; i++) {
        tree[N + i] = H[i];
    }
    for(int i = N - 1; i >= 1; i--){
        tree[i] = max(tree[2*i], tree[2*i + 1]);
    }
	return;
}
