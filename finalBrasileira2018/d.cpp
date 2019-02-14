#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 10010
#define sz(x) ((int)((x).size()))

using namespace std;

struct foo{
	string ori, final;
	int arroba, tam;
}v[MAXN];

int n;
unordered_map<string, int> msi;

int main(){_
	int aindaNaoApareceuMais;
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> v[i].ori;
		
		aindaNaoApareceuMais = 1;
		v[i].tam = sz(v[i].ori);
		for(int j = 0; j < v[i].tam; ++j){
			if(v[i].ori[j] == '@'){
				v[i].arroba = j;
				break;
			}
			if(v[i].ori[j] == '.') continue;
			if(v[i].ori[j] == '+') aindaNaoApareceuMais = 0;
			if(aindaNaoApareceuMais) v[i].final += v[i].ori[j];
		}
		v[i].final += v[i].ori.substr(v[i].arroba);
		
		if(msi.find(v[i].final) == msi.end()) msi[v[i].final] = 1;
	}
	
	cout << sz(msi) << endl;
	return 0;
}
