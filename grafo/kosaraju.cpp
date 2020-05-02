#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define N 100012
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define pb push_back
#define fs first
#define sc second
#define sz(x) ((int)((x).size()))
#define oo 1000000123
#define mod 1000000007

using namespace std;

int n, m, v[N], vis[N];
vi lista, adj[N], radj[N];

void dfs0(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs0(v);
        }
    }
    lista.pb(u);
}

void dfs1(int u){
    vis[u] = 2;
    cout << u << ' ';
    for(int v : radj[u]){
        if(vis[v] < 2){
            dfs1(v);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int u, v;
    while(m--){
        cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs0(i);
        }
    }
    for(int i = n-1; i >= 0; --i){
        if(vis[lista[i]] < 2){
            dfs1(lista[i]);
            cout << '\n';
        }
    }
    return 0;
}
