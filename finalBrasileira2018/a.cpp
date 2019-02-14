#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define vi vector<int>
#define pb push_back
#define MAXN 100
#define sz(x) ((int)((x).size()))
#define ll long long

using namespace std;

ll a, b;

int main(){_
	scanf("%lld.%lld", &a, &b);
	a = a * 100LL + b;
	
	cout << (36000LL / __gcd(a, 36000LL)) << endl;
	return 0;
}
