#include<bits/stdc++.h>
#define ll long long
#define M 1010
#define N 1010
#define G 1000100
#define K 1010
#define ii pair<ll, ll>
#define fs first
#define sc second
#define vi vector<ll>
#define pb emplace_back
#define vii vector<ii>
#define oo (1LL << 62)

using namespace std;

ll mana[M], dano[M];
ii par[G];
ll pesoNo[N];
ll dp[K];
ll m, n, g, k;
vii adj[2*N+100];

void mataOsMonstro(){
    for(int i = 1; i < K; ++i) dp[i] = oo;
    dp[0] = 0LL;

    for(ll i = 1; i < K; ++i){
        for(int j = 0; j < m; ++j){
            if(i - dano[j] >= 0){
                dp[i] = min(dp[i], dp[i - dano[j]] + mana[j]);
            }
            else{
                dp[i] = min(dp[i], mana[j]);
            }
        }
    }
}

ll djk(){
    priority_queue<ii, vii, greater<ii> > pq;

    vi dist(2*N+500, oo);
    dist[1] = 0;
    pq.push(ii(0, 1));

    ii topo;
    int u, v, tam;
    ll d, w;
    while(!pq.empty()){
        topo = pq.top(); pq.pop();
        u = topo.sc;
        d = topo.fs;

        if(d > dist[u]) continue;
        if(u == n + N) return dist[u];

        tam = adj[u].size();
        for(int i = 0; i < tam; ++i){
            v = adj[u][i].fs, w = adj[u][i].sc;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
            }
        }
    }
    //cout << (n+N) << ' ' << dist[n + N] << endl;
    return -1;
}

int main(){
    while(scanf("%lld %lld %lld %lld", &m, &n, &g, &k) && (n || m || g || k)){
    
        for(int i = 0; i < m; ++i){ // lendo as magias
            scanf("%lld %lld", &mana[i], &dano[i]);
        }

        int u, v, salao;
        for(int i = 0; i < g; ++i){ // lendo a adj
            scanf("%lld %lld", &par[i].fs, &par[i].sc);
        }
        
        mataOsMonstro();

        ll pv, maior = -1;
        for(int i=1; i <= n; ++i) {
            pesoNo[i] = 0;
        }
        for(int i = 0; i < k; ++i){
            scanf("%d %lld", &salao, &pv);
            pesoNo[salao] += dp[pv];
            maior = max(maior, pv);
        }
        for(int i=1; i <= n; ++i) {
            adj[i].pb(ii(i + N, pesoNo[i]));
        }

        int ul, vl;
        for(int i = 0; i < g; ++i){
            u = par[i].fs;
            v = par[i].sc;

            ul = u + N;
            vl = v + N;
            adj[vl].pb(ii(u, 0));
            adj[ul].pb(ii(v, 0));
        }
        printf("%lld\n", djk());
        for(int i=0; i <= n + 1; ++i) {
            adj[i].clear();
            adj[i + N].clear();
        }
    }

    return 0;
}
