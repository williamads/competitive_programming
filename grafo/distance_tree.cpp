#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define N 500123
#define M 512
#define vi vector<int>
#define vvi vector<vi>
#define endl '\n'

using namespace std;

ll t, n, ans, ans2;
vi adj[N];
vvi dp;

void dfs(int u, int p){
    int tam = adj[u].size(), v;
    dp[u][0] = 1LL;
    for(int i = 0; i < tam; ++i){
        v = adj[u][i];
        if(v != p){
            dfs(v, u);
            for(int l = 1; l <= t; ++l)
                dp[u][l] += dp[v][l-1];
        }
    }
    //cout << "u " << u << endl;
    ans += dp[u][t];
    for(int i = 0; i < tam; ++i){
        v = adj[u][i];
        if(v != p){
            //cout << "v " << v << endl;
            for(int l = 1; l < t; ++l){
                ans2 += dp[v][l-1] * (dp[u][t-l] - dp[v][t-l-1]);
                //cout << ans2 << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int u, v;
    cin >> n >> t;
    dp = vvi(n + 2, vi(t + 2, 0));
    for(int i = 0; i < n - 1; ++i){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    /*
    for(int i = 1; i <= n; ++i){
        cout << i << ": ";
        for(int x = 0; x <= t; ++x){
            cout << dp[i][x] << ' ';
        }
        cout << endl;
    }
    */
    cout << (ans + (ans2 / 2LL)) << endl;
    return 0;
}
