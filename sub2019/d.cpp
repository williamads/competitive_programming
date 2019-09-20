#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define N 100123

using namespace std;

int n, k, t[N], vis[N];
vi adj[N], res;

int dfs(int u){
    vis[u] = 1;

    int m = 0, idx = -1;
    for(int v : adj[u]){
        if(!vis[v]){
            t[v] = dfs(v);
            if(t[v] > m){
                m = t[v];
                idx = v;
            }
        }
    }

    for(int v : adj[u]){
        if(v != idx){
            res.pb(t[v]);
        }
    }
    
    return t[u] = (m + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    int u, v;
    cin >> n >> k;
    for(int v = 2; v <= n; ++v){
        cin >> u;
        adj[u].pb(v);
    }
    
    res.pb(dfs(1));

    sort(res.begin(), res.end(), greater<int>());

    int ans = 0, tam = res.size();
    for(int i = 0; i < min(k, tam); ++i){
        ans += res[i];
    }

    cout << ans << endl;

    return 0;
}
