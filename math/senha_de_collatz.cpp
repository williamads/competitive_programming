#include<bits/stdc++.h>
#define N 10000005
#define ll long long
#define int long long
#define ii pair<ll, ll>
#define last second
#define nivel first

using namespace std;

int n, k, ans = 0LL;
ii dp[N];

ii f(int u, int pai){
    if(u > n) {
        return {0, u};
    }

    if((dp[u].last != 0)) return dp[u];

    int v;
    ii curr;
    if(u & 1LL) {
        v = 3LL * u + 1;
        dp[u] = f(v, u);
        dp[u].nivel++;
        return dp[u];
    }
    v = u >> 1LL;
    dp[u] = f(v, u);
    dp[u].nivel++;
    return dp[u];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    ans = 0;
    if(n < 4){
        if(n == 1) {
            cout << (k == 1) << endl;
        }
        else if (n == 2){
            if(k == 1) cout << 2 << endl;
            else if (k == 2) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else {
            if(k == 1) cout << 3 << endl;
            else if(k == 2) cout << 1 << endl;
            else cout << 0 << endl;
        }
        return 0;
    }
    dp[1].nivel = 1; dp[1].last = 1;
    ii curr;
    for(int u = 1; u <= n; ++u){
        curr = f(u, u);
        if(curr.nivel >= k) ans++;
        else if(curr.last == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
