#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll unsigned long long
#define vi vector<ll>
#define pb push_back

using namespace std;

vi dig;
ll memo[20][2][11];

vi getDig(ll x){
	vi r;
	r.clear();
	
	do{
		r.pb(x % 10);
		x /= 10;
	}while(x);
	
	return r;
}

ll solve(int idx, int restrito, int last){
	if(idx == -1) return 1;
	
	if(~memo[idx][restrito][last]) return memo[idx][restrito][last];
	
	ll limit = (restrito ? dig[idx] : 9);
	
	ll ans = 0LL;
	for(int d = 0; d <= limit; ++d){
        if(abs(d - last) <= 1)
            ans += solve(idx - 1, (d < dig[idx] ? 0 : restrito), d);
	}
	return memo[idx][restrito][last] = ans;
}

ll f(ll x){
	dig.clear();
	dig = getDig(x);
	memset(memo, -1, sizeof memo);
    ll ans = 0;
    for(int i = dig.back() - 1; i >= 0; ++i)
        ans += solvenr(dig.size() - 2, 1, i);
	return solve(dig.size() - 2, 1, dig.back()) + ans;
}

ll bb(ll n){
	ll lo = 1, hi = -1, mid;
	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(mid - f(mid) >= n) hi = mid;
		else lo = mid + 1; 
	}
	return lo;
}

int main(){_
	ll n;
	while(cin >> n){
		cout << f(n) << endl;
	} 
	
	return 0;
}
