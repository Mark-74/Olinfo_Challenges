// Punti: 100.0
#include <bits/stdc++.h>
using namespace std;

struct Node{
	long long sum_value;
	long long min_value;

	//lazy propagation
	long long update;
	bool add;
	bool has_update;

	Node(long long sum = 0, long long min = 0, long long upd = 0, bool add = false, bool has_upd = false)
        : sum_value(sum), min_value(min), update(upd), add(add), has_update(has_upd) {}
};

vector<Node> tree;
int N, padding;

void init(vector<long long> a){
	N = a.size();

	//making N a power of 2
	int i;
    for(i = 1; i < N;){
        i <<= 1;
    }
    padding = i - N;
    N = i;
    a.resize(N, INT_MAX);

    tree.resize(N*2);

    for(int i = 0; i < N; i++){
        tree[N+i] = Node(a[i], a[i]);
    }

    for(int i = N-1; i >= 1; i--){
        tree[i] = Node(tree[i*2].sum_value + tree[i*2+1].sum_value, min(tree[i*2].min_value, tree[i*2+1].min_value));
    }

}

void propagate(int node, int nl, int nr){
	if(!tree[node].has_update) return;

	//update node's values
	if(tree[node].add){
		tree[node].sum_value += (nr-nl) * tree[node].update;
		tree[node].min_value += tree[node].update;
	} else {
		tree[node].sum_value = (nr-nl) * tree[node].update;
		tree[node].min_value = tree[node].update;
	}

	tree[node].has_update = false;

	//propagate to children if they're not leaves
	if(nl != nr-1){
		//left
		//tree[node*2].add = tree[node*2].has_update ? tree[node].add : tree[node*2].add;
		if(tree[node*2].has_update && tree[node].add){
			tree[node*2].update += tree[node].update;
		} else{
			tree[node*2].update = tree[node].update;
			tree[node*2].add = tree[node].add;
		}
		tree[node*2].has_update = true;

		//right
		if(tree[node*2+1].has_update && tree[node].add){
			tree[node*2+1].update += tree[node].update;
		} else{
			tree[node*2+1].update = tree[node].update;
			tree[node*2+1].add = tree[node].add;
		}
		tree[node*2+1].has_update = true;
	}

	tree[node].update = 0;
}

long long query_sum(int node, int nl, int nr, int l, int r){
	if(r <= nl || l >= nr) return 0;
	propagate(node, nl, nr);
	if(l <= nl && nr <= r) return tree[node].sum_value;

	long long left = query_sum(node*2, nl, (nl+nr)/2, l, r);
	long long right = query_sum(node*2+1, (nl+nr)/2, nr, l, r);

	return left + right;
}

long long query_min(int node, int nl, int nr, int l, int r){
	if(r <= nl || l >= nr) return INT_MAX;
	propagate(node, nl, nr);
	if(l <= nl && nr <= r) return tree[node].min_value;

	long long left = query_min(node*2, nl, (nl+nr)/2, l, r);
	long long right = query_min(node*2+1, (nl+nr)/2, nr, l, r);

	return min(left, right);
}

int query_lower(int node, int nl, int nr, int l, int r, int threshold){
	if(r <= nl || l >= nr) return -1;
	propagate(node, nl, nr);
	if(tree[node].min_value > threshold) return -1;
	if(nr-1 == nl){
		if(tree[node].min_value <= threshold) return nl;
		else return -1;
	} 

	int left = query_lower(node*2, nl, (nl+nr)/2, l, r, threshold);
	if(left == -1)
		return query_lower(node*2+1, (nl+nr)/2, nr, l, r, threshold);
	
	return left;

}

long long get_sum(int l, int r){
	//cout << "get_sum" << endl;
	return query_sum(1, 0, N, l, r);
}

long long get_min(int l, int r){
	//cout << "get_min" << endl;
	return query_min(1, 0, N, l, r);
}

int lower_bound(int l, int r, long long x){
	//cout << "lower_bound" << endl;
	return query_lower(1, 0, N, l, r, x);
}

// void update(int node, int nl, int nr, int obj, long long x, bool add){ //if true adds else it sets
// 	if(obj < nl || obj >= nr) return;
// 	if(nl == obj && nr - nl == 1){
// 		if(add){
// 			tree[node].sum_value += x;
// 			tree[node].min_value += x;
// 		} else {
// 			tree[node] = Node(x, x);
// 		}

// 		//updated leaf, return
// 		return;
// 	}

// 	update(node*2, nl, (nl+nr)/2, obj, x, add);
// 	update(node*2+1, (nl+nr)/2, nr, obj, x, add);

// 	tree[node].min_value = min(tree[node*2].min_value, tree[node*2+1].min_value);
// 	tree[node].sum_value = tree[node*2].sum_value + tree[node*2+1].sum_value;
// }

void update_range(int node, int nl, int nr, int l, int r, long long x, bool add){
	if(r <= nl || l >= nr) return;
	propagate(node, nl, nr);
	if(l <= nl && nr <= r){
		tree[node].has_update = true;
		tree[node].update = x;
		tree[node].add = add;

		return;
	}

	update_range(node*2, nl, (nl+nr)/2, l, r, x, add);
	update_range(node*2+1, (nl+nr)/2, nr, l, r, x, add);

	propagate(node*2, nl, (nl+nr)/2);
	propagate(node*2+1, (nl+nr)/2, nr);

	tree[node].sum_value = tree[node*2].sum_value + tree[node*2+1].sum_value;
	tree[node].min_value = min(tree[node*2].min_value, tree[node*2+1].min_value);
}

ifstream fin("input.txt");
ofstream fout("output.txt");

void add(int l, int r, long long x){
	//cout << "add" << endl;
	update_range(1, 0, N, l, r, x, true);
}

void set_range(int l, int r, long long x){
	//cout << "set_range" << endl;
	update_range(1, 0, N, l, r, x, false);
}

#ifndef EVAL


int main() {
	int n, q;
	fin >> n >> q;

	
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		fin >> a[i];
	init(a);
	
	for (int i = 0; i < q; i++) {
	 	int op, l, r;
	 	long long x;
	 	fin >> op;
	 	fin >> l >> r;
	 	if (op == 2 or op == 3 or op == 5)
	 		fin >> x;
	 	if (op == 1) fout << get_sum(l, r) << "\n";
	 	if (op == 2) add(l, r, x);
	 	if (op == 3) set_range(l, r, x);
	 	if (op == 4) fout << get_min(l, r) << "\n";
	 	if (op == 5) fout << lower_bound(l, r, x) << "\n";
	}
	
	return 0;
}
#endif
