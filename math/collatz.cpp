#define ll long long
#define int long long

using namespace std;

unordered_map<ll, ll> dp;
int n, k, ans = 0LL;

ll f(int u){
    if(dp.count(u)) return dp[u];
    
    if(u > n) return dp[u] = 0LL;

    int v;
    if(u & 1LL) {
        v = 3LL * u + 1;
        return dp[u] = f(v) + 1LL;
    }
    v = u >> 1LL;
    return dp[u] = f(v) + 1LL;
}

signed main(){
    while(cin >> n >> k){
    ans = 0;
    dp.clear();
    if(n >= 1) ans++;
    if(n >= 2) ans++;
    if(n >= 4) ans++;
    if(n == 3){
        if(k == 2) cout << 1 << endl;
        else if(k == 1) cout << 3 << endl;
        else if(k > 2) cout << 0 << endl;
        continue;
        return 0;
    }
    dp[1] = dp[2] = dp[4] = k-1;
    for(int u = 1; u <= n; ++u){
        if(f(u) >= k) ans++;
    }
    cout << ans << endl;
    }
    return 0;
}
