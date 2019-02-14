#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 10012

using namespace std;

int block[MAXN], v[MAXN], b[MAXN];
int n, q, len;

void init(){
	len = (int) sqrt(n + .0) + 1;
	
	for(int i = 0; i < n; ++i){
		block[i] = i / len;
		b[block[i]] += v[i];
	}
}

int query(int l, int r){
	int ans = 0;
	if(block[l] == block[r]){
		for(int i = l; i <= r; ++i) ans += v[i];
	}
	else{
		for(int i = l, end = (block[l] + 1) * len - 1; i <= end; ++i) 
			ans += v[i];
		for(int i = block[l] + 1; i <= block[r] - 1; ++i)
			ans += block[i];
		for(int i = block[r] * len; i <= r; ++i)
			ans += v[i];
	}
	
	return ans;
}

int main(){_
	cin >> n >> q;
	for(int i = 0; i < n; ++i) cin >> v[i];
	
	init();
	
	int l, r;
	while(q--){
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
	return 0;
}
