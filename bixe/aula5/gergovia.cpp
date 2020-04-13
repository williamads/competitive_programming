#include<bits/stdc++.h>
#define N 100123
#define int long long
#define ll long long

using namespace std;

int n;
int ans, v[N];

ll vabs(ll x){
    if(x < 0) x *= -1LL;
    return x;
}

signed main(){
    ios_base::sync_with_stdio(0);
    while((cin >> n) && n){
        for(int i = 0; i < n; ++i){
            cin >> v[i];
        }

        ans = 0;
        for(int i = 0; i < n; ++i){
            ans += vabs(v[i]);
            v[i + 1] += v[i];
        }

        cout << ans << '\n';
    }
    return 0;
}
