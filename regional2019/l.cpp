#include<bits/stdc++.h>
#define N 1123

using namespace std;

char mat[N][N];
int acum[N][N], n, m;

int f(int x){
    int cont;
    for(int j = 1; j <= m; ++j){
        cont = 0;
        for(int i = 1; i <= n; ++i){
            if(acum[i][j] >= x) cont++;
            else cont = 0;
            if(cont >= x) return 0;
        }
    }
    return 1;
}

int main(){
    int lo, hi, mid, ans;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> mat[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(mat[i][j] == mat[i][j-1])
                acum[i][j] = acum[i][j-1] + 1;
            else
                acum[i][j] = 1;
        }
    }
    lo = 0, hi = N;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(f(mid)) hi = mid - 1;
        else lo = mid + 1, ans = mid;
    }
    ans *= ans;
    cout << ans << '\n';
    return 0;
}
