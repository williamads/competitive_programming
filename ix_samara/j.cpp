#include<bits/stdc++.h>
#define N 200123
#define ll long long
#define Tipo int
#define ii pair<Tipo, Tipo>
#define fs first
#define sc second
#define vi vector<Tipo>
#define vvi vector<vi>
#define pb emplace_back
#define endl '\n'
#define water -1
#define point N + 20

using namespace std;

int n, m, um;
vvi mat;
vi adj[2*N], vis;

int ff(int u){
    vis[u] = 1;
    int tam = adj[u].size();
    if(adj[u].size() == 1) return u;
    for(int v : adj[u]){
        if(!vis[v]){
            int r = ff(v);
            if(r)
                return r;
        }
    }
    return 0;
}

int dfs(int u){
    vis[u] = 2;
    int tam = adj[u].size();
    if(tam > 2) return 1;
    for(int v : adj[u]){
        if(vis[v] < 2){
            if(dfs(v))
                return 1;
        }
    }
    return 0;
}

int out(int i, int j){
    return (i < 1 || j < 1 || i > n || j > m || mat[i][j] == water);
} 

int h(int i, int j) {
    return (i * m) + j;
}
int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0);
    char c;
    cin >> n >> m;
    mat = vvi(n+1, vi(m+1));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> c;
            if(c == '#') mat[i][j] = water;
            else if(c == '.') mat[i][j] = h(i, j);
            else if (c == '1'){
                um = h(i, j);
                mat[i][j] = um;
            }
            else mat[i][j] = h(i, j);
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(mat[i][j] != water){
                for(int l = 0; l < 4; ++l){
                    if(!out(i + di[l], j + dj[l])){
                        adj[h(i, j)].pb(h(i + di[l], j + dj[l]));
                    }
                }
            }      
        }
    }

    vis = vi((n + 2) * (m + 2));
    int folha = ff(um);
    if(folha == 0) cout << "YES\n";
    else if(dfs(folha)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
