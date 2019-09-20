#include<bits/stdc++.h>
#define MAXN 100123
#define ll unsigned long long
#define int unsigned long long
#define vi vector<ll>
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)
#define mid(a, b) ((a + b) >> 1)
#define comp(a, b) (a + b)
#define OUT 0ULL

using namespace std;

int tam;
vi tree, lazy, eliminado;
ll naruto;
int cont;

void push(int u, int i, int j){
//	if(lazy[u] == OUT) return;
	
	if((!eliminado[u])&&(i != j)){
		tree[u] += lazy[u] * (j - i + 1ULL);
		lazy[left(u)] += lazy[u];
		lazy[right(u)] += lazy[u];
	}
	
	else if(eliminado[u] &&(i != j)){
		tree[u] = 0ULL;
		eliminado[left(u)] = 1;
		eliminado[right(u)] = 1;
		lazy[left(u)] = 0ULL;
		lazy[right(u)] = 0ULL;
	}
	else if((!eliminado[u])&&(i == j)){
		tree[u] += lazy[u] * (j - i + 1ULL);
	} 
	else {
		tree[u] = 0ULL;
	}
	
	eliminado[u] = 0;
	
	lazy[u] = OUT;
}

ll query(int u, int i, int j, int l, int r){
	if((i > r) || (j < l)) return OUT;
	
	push(u, i, j);
	
	if((l <= i) && (j <= r)) return tree[u];
	
	ll lans = query(left(u), i, mid(i, j), l, r);
	ll rans = query(right(u), mid(i, j) + 1, j, l, r);
	
	return comp(lans, rans);
}

ll update(int u, int i, int j, int l, int r, ll value){
	push(u, i, j);
	
	if((i > r) || (j < l)) return OUT;
	
	if((l <= i) && (j <= r)){
		lazy[u] += value;
		push(u, i, j);
		return tree[u];
	}
	
	update(left(u), i, mid(i, j), l, r, value);
	update(right(u), mid(i, j) + 1ULL, j, l, r, value);
	
	return tree[u] = comp(tree[left(u)], tree[right(u)]);
}


ll elim(int u, int i, int j, int l, int r){
	push(u, i, j);
	
	if((i > r) || (j < l)) return OUT;
	
	if((l <= i) && (j <= r)){
		lazy[u] = 0ULL;
		eliminado[u] = 1;
		push(u, i, j);
		return tree[u];
	}
	
	elim(left(u), i, mid(i, j), l, r);
	elim(right(u), mid(i, j) + 1, j, l, r);
	
	return tree[u] = comp(tree[left(u)], tree[right(u)]);
}

void update(int l, int r, ll value) { update(1, 1, tam, l, r, value); }

ll query(int l, int r) { return query(1, 1, tam, l, r); }

void elimina(int l, int r){ elim(1, 1, tam, l, r); }

signed main(){
	int n, c, T;
	int op, l, r, value;
	
	scanf("%llu %llu", &n, &c);
	//cin >> n >> c;
	
	tam = n;
	tree = lazy = vi(4 * (n + 1), 0ULL);
	eliminado = vi(4 * (n + 1), 0ULL);

	while(c--){
		scanf("%llu", &op);

		if(op == 1){
			scanf("%llu %llu %llu", &l, &r, &value);
			//cin >> l >> r >> value;
			update(min(l, r), max(l, r), value);
		}
		else if(op == 2){
			scanf("%llu %llu", &l, &r);
			//cin >> l >> r;
            naruto += query(min(l, r), max(l, r));
			elimina(min(l, r), max(l, r));
			printf("%llu\n", naruto);
            //cout << naruto << endl;
		}
	}

	return 0;
}
