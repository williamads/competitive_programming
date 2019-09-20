#include<bits/stdc++.h>
#define N 4123
#define K 1123
#define oo 1e9

using namespace std;

int n, k;
int matrix[N][N], cost[N][N];
int dp[2][N];

int C(int i, int j) {
    return (cost[j][j] - cost[i - 1][j] - cost[j][i - 1] + cost[i - 1][i - 1]) / 2 ;
}

void solve(int i, int l, int r, int start, int end) {
    if(l > r) return;

    int mid = (l + r) >> 1, opt;
    dp[i][mid] = oo;

    for(int k = start; k <= min(mid, end); ++k) {
        if(dp[i ^ 1][k] + C(k + 1, mid) < dp[i][mid]) {
            dp[i][mid] = dp[i ^ 1][k] + C(k + 1, mid); 
            opt = k;
        }
    }
    solve(i, l, mid - 1, start, opt);
    solve(i, mid + 1, r, opt, end);
}


signed main(){
    scanf("%i %i", &n, &k);
    for(int i=1; i <= n; ++i) {
        for(int j=1; j <= n; ++j) {
            scanf("%i", &matrix[i][j]);
        }
    }
    for(int i=1; i <= n; ++i) {
        for(int j=1; j <= n; ++j) {
            cost[i][j] = cost[i - 1][j] + cost[i][j - 1] - cost[i - 1][j - 1] + matrix[i][j];
        }
    }


    for(int i=1; i <= n; ++i) {
        dp[1][i] = C(1, i);
    }

    for(int i=2; i <= k; ++i) {
        solve(i & 1, 1, n, 1, n);
    }
    printf("%i\n", dp[k & 1][n]);

	return 0;
}

