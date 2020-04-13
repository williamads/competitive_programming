#include<bits/stdc++.h>
#define ii pair<int, int>
#define fs first
#define sc second

using namespace std;

int n, m, a, b, u, v, op;
set<ii> adj;
ii p;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    while(m--){
        cin >> op >> a >> b;
        u = min(a, b);
        v = max(a, b);
        if(op == 0){
            if(adj.find(ii(u, v)) != adj.end()) cout << "1\n";
            else cout << "0\n";
        }
        else {
            adj.insert(ii(u, v));
        }
    }
    return 0;
}
