#include<bits/stdc++.h>
#define N 100123
#define ll long long

using namespace std;

struct query{
    int l, r;
    ll val;
}op[N];

int n, m, k;
ll v[N], qtd_op[N], ans[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> v[i];

    for(int i = 1; i <= m; ++i){
        cin >> op[i].l >> op[i].r >> op[i].val;
    }

    int a, b;
    for(int i = 1; i <= k; ++i){
        cin >> a >> b;
        qtd_op[a]++;
        qtd_op[b + 1]--;
    }

    op[1].val *= qtd_op[1];
    for(int i = 2; i <= m; ++i){
        qtd_op[i] += qtd_op[i - 1];
        op[i].val *= qtd_op[i];
    }

    /*
    for(int i = 1; i <= m; ++i)
        cout << op[i].val << ' ';
    cout << '\n';
    */
    
    for(int i = 1; i <= m; ++i){
        ans[op[i].l] += op[i].val;
        ans[op[i].r + 1] -= op[i].val;
    } 

    for(int i = 1; i <= n; ++i){
        ans[i] += ans[i - 1];
        v[i] = v[i] + ans[i];
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}
