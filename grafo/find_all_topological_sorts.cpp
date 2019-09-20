#include<iostream>
#include<vector>
 
#define vi vector<int>
#define pb emplace_back
#define N 20
 
using namespace std;
 
vi adj[N];
int grau[N];
int n, m;
 
void f(vi &res, int vis){
    int flag = 0;
    for(int u = 1; u <= n; ++u){
        if(!(vis & (1 << u)) && grau[u] == 0){
 
            for(int v : adj[u]) grau[v]--;
 
            res.pb(u);
            vis |= (1 << u);
 
            f(res, vis);
 
            res.pop_back();
            vis ^= (1 << u);
 
            for(int v : adj[u]) grau[v]++;
 
            flag = 1;
        }
    }
    if(!flag){
	    for(int v : res) cout << v << ' ';
	    cout << endl;
    }
}
 
int main(){
    int u, v;
    cin >> n >> m;
    while(m--){
        cin >> u >> v;
        adj[u].pb(v);
        grau[v]++;
    }
 
    vi res;
    f(res, 0);
 
    return 0;
}

