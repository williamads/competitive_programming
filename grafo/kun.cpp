#include<bits/stdc++.h>
#define ll long long
#define oo 1000000123
#define ii pair<int, int>
#define fs first
#define sc second
#define vi vector<int>
#define pb emplace_back
#define vvi vector<vi>
#define vii vector<ii>
#define sz(x) ((int)((x).size()))
#define N 100123

using namespace std;

int matchA[N], matchB[N], marcB[N];
vi adj[N];

bool dfs(int u) {
    for(int v : adj[u]) {
        if(marcB[v]) continue;
        marcB[v] = 1;

        if(matchB[v] == -1 || dfs(matchB[v])) {
            matchB[v] = u;
            matchA[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n = 14, m = 14;
    // 0...n-1  -> 0...m-1
    adj[2].pb(13); 
    adj[7].pb(8);
    adj[7].pb(5);
    adj[4].pb(8);

    for(int i = 0; i <= n; ++i)
        matchA[i] = matchB[i] = -1;

    bool aux = true;
    int resp = 0;
    while(aux) {
        for(int j = 0; j < m; ++j) marcB[j] = 0;
        aux = false;
        for(int i = 0; i < n; ++i) {
            if(matchA[i] != -1) continue;
            if(dfs(i)) {
                resp++;
                aux = true;
            }
        }
    }

    cout << resp << '\n';
    return 0;
}
