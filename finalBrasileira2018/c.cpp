#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 10123
#define sz(x) ((int)((x).size()))

using namespace std;

int n, D[MAXN];
double C[MAXN];
double desc[] = {0.0, 0.0, 0.5, 0.75, 0.75, 0.75, 0.75, 0.0, 0.0};
double memo[MAXN][130][9];

double f(int i, int tRestante, int nivel){
	if(i >= n) return 0.0;
	
	double &ans = memo[i][tRestante][nivel];
	
	if(ans != -1.0) return memo[i][tRestante][nivel];
	
	ans = f(i + 1, max(120 - D[i], 0), 2) + C[i]; // Pegar outro ticket
	if((nivel <= 6) && (tRestante > 0)){
		ans = min(ans, f(i + 1, max(tRestante - D[i], 0), min(nivel + 1, 7)) + C[i] - C[i] * desc[nivel]); // Continuar com mesmo
	}
	
	return ans;
}

int main(){_
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> D[i] >> C[i];
	}
	
	for(int i = 0; i < MAXN; ++i){
		for(int j = 0; j < 130; ++j){
			for(int k = 0; k < 9; ++k){
				memo[i][j][k] = -1.0;
			}
		}
	}
	
	cout << fixed << setprecision(2);
	cout << f(0, 0, 0) << endl;
	return 0;
}
