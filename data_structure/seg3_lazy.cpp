#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)
#define mid(a, b) ((a + b) << 1)
#define comp(a, b) (a + b)

using namespace std;

int n;
vi tree, lazy, a;

void build(int u, int i, int j){
    lazy[u] = 0;

    if(i == j){
        tree[u] = i;
        return;
    }

    build(left(u), i, mid(i, j), l, r);
    build(right(u), mid(i, j) + 1, j, l, r);

    tree[u] = comp(tree[left(u)], tree[right(u)]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;

    a = vi(n + 2);
    tree = lazy = vi(4 * (n + 2) + 5);

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    build(1, 1, n);

    char op;
    int l, r, val;
    while(cin >> op){
        if(op == 'c'){
            cin >> l >> r;
            //query(1, 1, n, l, r);
        }
        else {
            cin >> l >> r >> v;
            //update(1, 1, n, l, r);
        }
    }
    return 0;
}
