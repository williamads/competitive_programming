#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 10123
#define sz(x) ((int)((x).size()))
#define ll long long
#define ii pair<ll, ll>
#define iii pair<int, ii>
#define vi vector<ll>
#define vii vector<ii>
#define viii vector<iii>
#define pb push_back
#define fs first
#define sc second
#define oo (1LL << 62)

using namespace std;

int n, m;
viii adj[MAXN]; // fs = v, sc = ii( fs = Distance, sc = Coast )
vi dist, previous;

ll djk(){
	priority_queue<ii, vii, greater<ii> > pq;
	previous.assign(n + 2, oo);
	dist.assign(n + 2, oo);
	
	dist[1] = 0;
	previous[1] = 0;
	
	pq.push(ii(0, 1));
	
	while(!pq.empty()){
		ii topo = pq.top(); pq.pop();
		
		int u = topo.sc, d = topo.fs;
		
		if(dist[u] < d) continue;
		
		int tam = sz(adj[u]);
		for(int i = 0; i < tam; ++i){
			int v = adj[u][i].fs;
			ll w = adj[u][i].sc.fs, c = adj[u][i].sc.sc;
			
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				previous[v] = c;
				pq.push(ii(dist[v], v));
			}
			else if(dist[u] + w == dist[v]){
				previous[v] = min(previous[v], c);
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += previous[i];
		//cout << previous[i] << endl;
	}
	return ans;
}

int main(){_
	int u, v;
	ll w, c;
	
	cin >> n >> m;
	while(m--){
		cin >> u >> v >> w >> c;
		adj[u].pb(iii(v, ii(w, c)));
		adj[v].pb(iii(u, ii(w, c)));
	}
	
	cout << djk() << endl;
	return 0;
}
