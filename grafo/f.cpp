#include<bits/stdc++.h>
 
#define vi vector<int>
#define pb emplace_back
#define N 20
#define mod 1000000007LL
#define ll long long
#define oo (1LL << 62)
 
using namespace std;
 
vi adj[N];
int grau[N];
int n, m;
ll ans, dp[530000];

ll f(int vis){
    if(vis == ((1 << (n+1)) - 1)){
        if(ans >= mod) ans %= mod;
        return 1;
    }

    if(dp[vis] != oo) return dp[vis];

    ll curr = 0;
    for(int u = 1; u <= n; ++u){
        if(!(vis & (1 << u)) && grau[u] == 0){
 
            for(int v : adj[u]) grau[v]--;
 
            vis |= (1 << u);
 
            curr += f(vis);
            if(curr >= mod) curr %= mod;
 
            vis ^= (1 << u);
 
            for(int v : adj[u]) grau[v]++;
        }
    }

    return dp[vis] = curr;
}
 
int main(){
    int u, v;
    ll x;
    ll mult = 1;
    scanf("%d %d", &n, &m);
    //cin >> n >> m;
    for(int i = 0; i < n; ++i){
        scanf("%lld", &x);
        //cin >> x;
        mult *= x;
        if(mult >= mod) mult %= mod;
    }
    while(m--){
        scanf("%d %d", &u, &v);
        //cin >> u >> v;
        adj[u].pb(v);
        grau[v]++;
    }

    for(int i = 0; i < 530000; ++i){
        dp[i] = oo;
    }
    ans = f(1);
 
    ans = ((ans * mult)%mod);
    printf("%lld\n", ans);
 
    return 0;
}
