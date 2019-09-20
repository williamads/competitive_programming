#include<bits/stdc++.h>
#define int long long
#define oo 1e18

using namespace std;

int solve(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * a) % m;

    map<int, int> vals;
    for (int p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur))
            vals[cur] = p;
        cur = (cur * an) % m;
    }

    for (int q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

signed main(){
	ios_base::sync_with_stdio(0);
	int a, b, m, x;
	
	while((cin >> a >> b >> m) && (a || m || b)) {
		if(__gcd(a, m) != 1){
			cout << "-1" << endl;
			continue;
		}
		x = solve(a, b, m);
		if (x == oo){
			cout << "-1" << endl;
			continue;
		}
		x = x % phi(m);
		cout << x << endl;
	}
	return 0;
}
