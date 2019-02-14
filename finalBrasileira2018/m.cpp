#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define vi vector<int>
#define pb push_back
#define MAXN 100
#define sz(x) ((int)((x).size()))

using namespace std;

int v[MAXN], n;
vi ans;

int main(){_
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	
	ans.pb(v[n - 1]);
	
	for(int i = n - 2; i >= 0; --i){
		if(v[i] >= ans[sz(ans) - 1]) ans[sz(ans) - 1] = v[i];
		else ans.pb(v[i]);
	}
	
	cout << sz(ans) << endl;
	return 0;
}
