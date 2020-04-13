#include<bits/stdc++.h>
#define N 100123
#define vi vector<int>
#define pb emplace_back

using namespace std;

int n, m, vis[N], comp[N];
vi adj[N], radj[N], proc;

//making process pos order
void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
    proc.pb(u);
}

void scc(int u, int c){
    vis[u] = 2;
    comp[u] = c;
    cout << u << ' ';
    for(int v : radj[u])
        if(vis[v] < 2)
            scc(v, c);
}

int main(){
    ios_base::sync_with_stdio(0);
    int u, v;
    cin >> n >> m;
    for(int i = m; i--; ){
        cin >> u >> v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    int c = 0;
    for(int i = n - 1; i >= 0; --i){
        if(vis[proc[i]] < 2){
            cout << "comp " << c+1 << ": ";
            scc(proc[i], ++c); 
            cout << '\n';
        }
    }
    return 0;
}
