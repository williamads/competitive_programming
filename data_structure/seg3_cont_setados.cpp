#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)
#define mid(a, b) ((a + b) >> 1)
#define comp(a, b) (a + b)

using namespace std;

int n, q;
vi tree, lazy, tree1;

void push(int u, int i, int j){
    if(lazy[u] == 0) return;

    tree[u] += lazy[u] * (j - i + 1);
    tree1[u] = (tree[u] != 0) * (j - i + 1);

    if(i != j){
        lazy[left(u)] += lazy[u];
        lazy[right(u)] += lazy[u];
    }

    lazy[u] = 0;
}

void update(int u, int i, int j, int l, int r, ll val){
    push(u, i, j);

    if((i > r) || (j < l)) return;

    if((l <= i) && (j <= r)) {
        lazy[u] += val;
        push(u, i, j);
        return;
    }

    update(left(u), i, mid(i, j), l, r, val);
    update(right(u), mid(i, j) + 1, j, l, r, val);

    tree[u] = comp(tree[left(u)], tree[right(u)]);
    tree1[u] = comp(tree1[left(u)], tree1[right(u)]);
}

ll query(int u, int i, int j, int l, int r){
    if((i > r) || (j < l)) return 0;

    push(u, i, j);

    if((l <= i) && (j <= r)) return tree1[u];

    ll lans = query(left(u), i, mid(i, j), l, r);
    ll rans = query(right(u), mid(i, j) + 1, j, l, r);

    return comp(lans, rans);
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> q;

    tree = tree1 = lazy = vi(4 * (n + 3) + 5);

    string op;
    int l, r, val;
    while(q--){
        cin >> op;
        if(op == "ADD"){
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
            cout << tree[10] << '\n';
            cout << lazy[10] << '\n';
        }
        else if(op == "CON"){
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;    
}

//8 1000
//ADD 2 5 1
//ADD 3 6 -1
