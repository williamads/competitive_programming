// seg3 com lazy de max ele que substitui intervalo por um valor
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define N 300123
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define pb push_back
#define fs first
#define sc second
#define oo 1000000123
#define sz(x) ((int)((x).size()))
#define OUT -oo
#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)
#define mid(a, b) ((a + b) >> 1)

using namespace std;

int n, m;
vll tree, lazy, a;

void build(int u, int i, int j){
    lazy[u] = OUT;
    if(i == j){
        tree[u] = a[i];
        return;
    }     
    build(left(u), i, mid(i, j));
    build(right(u), mid(i, j) + 1, j);
    tree[u] = max(tree[left(u)], tree[right(u)]);
}

void push(int u, int i, int j){
    if(lazy[u] == OUT) return;
    tree[u] = lazy[u];
    if(i != j){
        lazy[left(u)] = lazy[right(u)] = lazy[u];
    }
    lazy[u] = OUT;
}

ll query(int u, int i, int j, int l, int r){
    if(r < i || l > j) return OUT;
    push(u, i, j);
    if(l <= i && j <= r) return tree[u];
    ll lans = query(left(u), i, mid(i, j), l, r);
    ll rans = query(right(u), mid(i, j) + 1, j, l, r);
    return max(lans, rans);
}

void update(int u, int i, int j, int l, int r, ll val){
    push(u, i, j);
    if(r < i || l > j) return;
    if(l <= i && j <= r) {
        lazy[u] = val;
        push(u, i, j);
        return;
    }
    update(left(u), i, mid(i, j), l, r, val);
    update(right(u), mid(i, j) + 1, j, l, r, val);
    tree[u] = max(tree[left(u)], tree[right(u)]);
}

int main(){
    ios_base::sync_with_stdio(0);
    int l, r;
    ll val;
    char op;
    cin >> n;
    a = vll(n + 1);
    tree = lazy = vll(4 * (n + 3));
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    cin >> m;
    while(m--){
        cin >> op;
        if(op == 'q'){
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
        else if(op == 'u'){
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
    }
    return 0;
}
