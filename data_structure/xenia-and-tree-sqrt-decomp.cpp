#include<bits/stdc++.h>
#define bs 317
#define N 100123
#define vi vector<int>
#define oo 10000123
#define ii pair<int, int>
#define fs first
#define sc second

using namespace std;

int n, q;
vi adj[N];

struct LCA{
    int l;
    int timer;
    vector<int> tin, tout, dist, adj[N];
    vector<vector<int>> up;

    void dfs_lca(int v, int p){
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p){
                dist[u] = dist[v] + 1;
                dfs_lca(u, v);
            }
        }

        tout[v] = ++timer;
    }

    bool is_ancetor(int u, int v){
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v){
        if (is_ancetor(u, v))
            return u;
        if (is_ancetor(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancetor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    void preprocess(int root, int n) {
        tin.resize(n+1);
        tout.resize(n+1);
        timer = 0;
        l = ceil(log2(n+1));
        up.assign(n+1, vector<int>(l + 1));
        dist.assign(n+1, oo);
        dist[root] = 0;
        dfs_lca(root, root);
    }
};

LCA bl;
vi unprocess;
int ans[N];

int dist(int u, int v){
    return bl.dist[u] + bl.dist[v] - 2 * bl.dist[bl.lca(u, v)];
}

void process(){
    queue<ii> q;
    int u, v, p;
    ii topo;

    for(int u : unprocess){
        ans[u] = 0;
        q.push(ii(u, -1));
    }
    
    unprocess.clear();

    while(!q.empty()){
        topo = q.front();
        q.pop();
        u = topo.fs;
        p = topo.sc;
        for(int v : adj[u]){
            if(v != p){
                if(ans[v] > ans[u] + 1){
                    ans[v] = ans[u] + 1;
                    q.push(ii(v, u));
                }
            }
        }
    }
}

int main(){
    int u, v, op, resp;
    scanf("%d %d", &n, &q);
    for(int i = 0; i <= n; ++i) ans[i] = oo;
    for(int i = n - 1; i--; ){
        scanf("%d %d", &u, &v);
        bl.adj[u].push_back(v);
        bl.adj[v].push_back(u);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bl.preprocess(1, n);
    unprocess.push_back(1);
    int cases = 0;
    while(q--){
        if(cases == bs) cases = 0, process();
        cases++;
        scanf("%d %d", &op, &u);
        if(op == 1){
            unprocess.push_back(u);
        }
        else{
            resp = ans[u];
            for(int v : unprocess){
                resp = min(resp, dist(u, v));
            }
            printf("%d\n", resp);
        }
    } 
    return 0;    
}
