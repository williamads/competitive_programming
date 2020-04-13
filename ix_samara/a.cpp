#include<bits/stdc++.h>
#define ll long long
#define Tipo int
#define ii pair<Tipo, Tipo>
#define fs first
#define sc second
#define vi vector<Tipo>
#define pb emplace_back
#define endl '\n'
#define point 100000
#define water 200000
#define inter 300000
 
using namespace std;
 
int n, m, di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1}, vis[60][60], cont;
int mat[60][60];
 
int out(int i, int j){
	if(i <= 0 || j <= 0 || i > n || j > m) return 1;
	return 0;
}
 
int pode(int i, int j){
	if((i > 0) && (i <= n) && (j > 0) && (j <= m) && !vis[i][j] && (mat[i][j] == point)) return 1;
	return 0;
}
 
void ff(int i, int j){
	vis[i][j] = 1;
	mat[i][j] = cont;
	for(int k = 0; k < 4; ++k){
		if(pode(i + di[k], j + dj[k]))
			ff(i + di[k], j + dj[k]);
	}
}
 
int pai[10000];
 
int id(int u){
	if(pai[u] != u) return pai[u] = id(pai[u]);
	return u;
}
 
void join(int u, int v){
	u = id(u), v = id(v);
	pai[v] = u;
}
 
vi getv(int i, int j){
	int x;
	vi r;
	set<int> st;
	for(int k = 0; k < 4; ++k){
		if(!out(i + di[k], j + dj[k])){
			x = mat[i + di[k]][j + dj[k]];	
			if(x != water && x != inter && x != point){
				st.insert(id(x));
			}
		}
	}
	for(int l : st) r.pb(l);
	return r;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	char c;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> c;
			if(c == '.') mat[i][j] = point;
			else if(c == '#') mat[i][j] = water;
			else mat[i][j] = inter;
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(pode(i, j)){
				++cont;
				ff(i, j);
			}
		}
	}
 
	for(int i = 0; i <= cont + 10; ++i)
		pai[i] = i;
 
	int ambi = 0, impo = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(mat[i][j] == inter){
				vi r = getv(i, j);
				int t = r.size();
				if(t == 0) mat[i][j] = water;
				else if(t == 1) ambi = 1;
				else{
					mat[i][j] = id(r[0]);
					for(int i = 1; i < t; ++i){
						if(id(r[0]) != id(r[i])) join(r[0], r[i]);
						else ambi = 1;
					}
				}
				if(ambi) i = 1000, j = 1000;
			}
		}
	}
 
	for(int i = 2; i <= cont; ++i) if(id(1) != id(i)) impo = 1;
 
	if(impo) cout << "Impossible" << endl;
	else if(ambi) cout << "Ambiguous" << endl;
	else{
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(mat[i][j] == water) cout << "#";
				//else if(mat[i][j] == inter) cout << "?";
				else if(mat[i][j] == point) cout << ".";
				else cout << ".";
			}
			cout << endl;
			//if(i != n) cout << endl;
		}
	}
	return 0;
}
