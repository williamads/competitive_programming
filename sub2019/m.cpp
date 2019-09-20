#include<bits/stdc++.h>
#define N 100123
#define int long long
#define ll long long
 
using namespace std;
 
int n;
ll c, T, p[N];
 
int f(ll t){
    ll curr = 0, cont = 1, ti;
    for(int i = 0; i < n; ++i){
        if(curr + p[i] <= t * T) {
            curr += p[i];
        }
        else{
            curr = p[i];
            cont++;
            if(curr > t * T) return 0;
        }
    }
    return (cont <= c);
}
 
ll bb(){
    ll lo = *max_element(p, p + n);
    ll hi = 10000000123LL;
    lo = 1LL;//(lo + T - 1LL) / T;
    ll mid;
 
    while(lo < hi){
        mid = lo + (hi - lo) / 2LL;
        if(f(mid)) hi = mid;
        else lo = mid + 1;
    }
 
    return lo;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
 
    cin >> n >> c >> T;
    for(int i = 0; i < n; ++i) cin >> p[i];
 
    cout << bb() << endl;
    return 0;
}
