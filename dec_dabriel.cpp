// URI - 2475. Questao do Gabriel de otimizacao de DP com Divide And Conquer
#include<bits/stdc++.h>
#define A 512
#define P 10123
#define ll long long

using namespace std;

const ll oo = (1LL << 62);
int p, a;
ll dp[A][P], acum[P], x;

ll C(ll i, ll j){
    return (acum[j] - acum[i-1]) * (j - i + 1LL);
}

void solve(int i, int l, int r, int start, int end){
    if(l > r) return;
    int mid = (l + r) >> 1;
    dp[i][mid] = oo;
    int opt = -1;
    for(int k = start; k <= min(mid, end); ++k){
        if(dp[i-1][k-1] + C(k, mid) < dp[i][mid]){
            dp[i][mid] = dp[i-1][k-1] + C(k, mid);
            opt = k;
        }
    }
    solve(i, l, mid - 1, start, opt);
    solve(i, mid + 1, r, opt, end);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> p >> a;
    for(int i = 1; i <= p; ++i){
        cin >> x;
        acum[i] = acum[i-1] + x;
        dp[0][i] = oo;
    }
    for(int i = 0; i <= a; ++i) dp[i][0] = 0;
    for(int i = 1; i <= a; ++i) solve(i, 1, p, 1, p);
    cout << dp[a][p] << '\n';
    return 0;
}
