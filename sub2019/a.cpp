#include<bits/stdc++.h>
#define N 1010
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int n, m, k;
vi adj[N], vis;

struct Circle{
    int x, y, r;
} circle[N];

int hasIntercection(int i, int j){
    Circle a = circle[i], b = circle[j];
    return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)) <= ((a.r + b.r) * (a.r + b.r));
}

void mkAdj(){
    // cicle - circle
    for(int i = 0; i < k - 1; ++i){
        for(int j = i + 1; j < k; ++j){
            if(hasIntercection(i, j)){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    // circle - line
    for(int i = 0; i < k; ++i){
        if(circle[i].x - circle[i].r <= 0){
            adj[k + 1].pb(i);
            adj[i].pb(k + 1);
        }
        if(circle[i].y - circle[i].r <= 0){
            adj[k + 2].pb(i);
            adj[i].pb(k + 2);
        }
        if(circle[i].x + circle[i].r >= n){
            adj[k + 4].pb(i);
            adj[i].pb(k + 4);
        }
        if(circle[i].y + circle[i].r >= m){
            adj[k + 3].pb(i);
            adj[i].pb(k + 3);
        }
    }
}

void show(){
    for(int i = 0; i < k + 5; ++i){
        cout << i << ": ";
        for(int v : adj[i]){
            cout << v << ' ';
        }
        cout << endl;
    }
}

int ct;

void dfs(int u){
    vis[u] = ct;

    for(int v : adj[u]){
        if(vis[v] < ct){
            dfs(v);
        }
    }
}

int block(){
    vis = vi(k + 6);
    ct = 1;
    dfs(k + 1);
    if((vis[k + 2] == ct) || (vis[k + 4] == ct)) return 1;

    ct = 2;
    dfs(k + 3);
    if((vis[k + 2] == ct) || (vis[k + 4] == ct)) return 1;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i){
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
    }

    mkAdj();

    //show();

    if(block()) cout << "N\n";
    else cout << "S\n";

    return 0;
}
