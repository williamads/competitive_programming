#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll long long
#define vi vector<ll>
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)
#define comp(a, b) (a + b)
#define mid(a, b) ((a + b) >> 1)
#define MAXN 100012
#define OUT 0

using namespace std;

ll tree[4*MAXN], lazy[4*MAXN], a[MAXN];

void build(int u, int i, int j){
	if(i == j) {
		tree[u] = a[i];
		lazy[u] = 0;
		return;
	}
	
	build(left(u), i, mid(i, j));
	build(right(u), mid(i, j) + 1, j);
	
	lazy[u] = 0;
	tree[u] = comp(tree[left(u)], tree[right(u)]);
}

void push(int u, int i, int j){
	if(lazy[u] == OUT) return;
	
	tree[u] = lazy[u] * (j - i + 1LL);
	
	if(i != j){
		lazy[left(u)] += lazy[u];
		lazy[right(u)] += lazy[u];
	}
	
	lazy[u] = OUT;
}

ll query(int u, int i, int j, int l, int r){
	if((r < i) || (j < l)) return OUT;
	
	push(u, i, j);
	
	if((l <= i) && (j <= r)) return tree[u];
	
	ll lans = query(left(u), i, mid(i, j), l, r);
	ll rans = query(right(u), mid(i, j) + 1, j, l, r);
	
	return comp(lans, rans);
}

ll update(int u, int i, int j, int l, int r, ll val){
	if((r < i) || (j < l)) return OUT;

	push(u, i, j);
	
	if((l <= i) && (j <= r)){
		lazy[u] += val;
		push(u, i, j);
		return tree[u];
	}
	
	update(left(u), i, mid(i, j), l, r, val);
	update(right(u), mid(i, j) + 1, j, l, r, val);
	
	tree[u] = comp(tree[left(u)], tree[right(u)]);
}

int main(){_
	int n, q, l, r, T, op;
	ll val;
	cin >> T;
	while(T--){
		cin >> n >> q;
		
		for(int i = 0; i < n; ++i) a[i] = 0;
		
		build(1, 1, n);
		
		while(q--){
			cin >> op;
			if(op == 0) { // update
				cin >> l >> r >> val;
				//l--; r--;
				update(1, 1, n, l, r, val);
			}
			else {
				cin >> l >> r;
				//l--; r--;
				cout << query(1, 1, n , l, r) << endl;
			}
		}
	}
	
	return 0;
}
