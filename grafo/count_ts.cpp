#include<bits/stdc++.h>
#define N 20
#define ll long long
#define oo (1LL << 62)
#define mod 1000000007LL
#define vi vector<ll>
#define vvi vector<vi>

using namespace std;

int n, m, x;
ll ans, prod;
vvi mat;

int temCiclo(){
    vvi mt = mat;

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                mt[i][j] |= mt[i][k] & mt[k][j];
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        if(mt[i][i])
            return 1;
    }
    return 0;
}

vvi identity(){
    vvi r = vvi(n + 1, vi(n + 1, 0));
    for(int i = 0; i <= n; ++i)
        r[i][i] = 1;
    return r;
}

vvi mult(vvi a, vvi b){
    vvi r = vvi(n + 1, vi(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                r[i][j] = (r[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }   
        }
    }
    return r;
}

vvi fe(){
    int e = n - 1;
    vvi ans = identity();
    while(e){
        if(e & 1) ans = mult(ans, mat);
        mat = mult(mat, mat);
        e >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    int u, v;

    cin >> n >> m;
    prod = 1;
    for(int i = n; i--; ){
        cin >> x;
        prod *= x;
        if(prod >= mod) prod %= mod;
    }
    
    mat = vvi(n + 1, vi(n + 1, 0));

    while(m--){
        cin >> u >> v;
        mat[u][v] = 1;
    }

    if(temCiclo()){
        cout << "0\n";
    }
    else {
        mat = fe();
        ll ans = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cout << mat[i][j] << ' ';
                ans = ans + mat[i][j];
                if(ans >= mod) ans %= mod;
            }
            cout << endl;
        }

        ans = (ans * prod) % mod;
        cout << ans << endl;
    }
    return 0;
}
