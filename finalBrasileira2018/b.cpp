#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define vi vector<int>
#define pb push_back
#define MAXN 200100
#define sz(x) ((int)((x).size()))
#define ll long long

using namespace std;

ll v[MAXN], n, comp, raio;
unordered_map<ll, int> f;
int cont;

int main(){_
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> v[i];
		comp += v[i];
		v[i] = comp;
		f[comp] = 1;
	}
	
	for(int i = 0; i < n; ++i){
		f[v[i] + comp] = 1;
	}
	
	if(comp & 1) cout << "N\n";
	else{
		raio = comp >> 1LL;
		for(int i = 0; i < n; ++i){
			if(f.find(v[i] + raio) != f.end()) ++cont;
		}

		if(cont >= 4) cout << "Y\n";
		else cout << "N\n";
	}
	return 0;
}
