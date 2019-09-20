#include<bits/stdc++.h>
#define N 105
#define L (1 << 31) + 100
#define mod 10000
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

int n, l, s, t;
vvi mat;

vvi identity(int o){
    vvi id = vvi(o + 1, vi(o + 1, 0));
    for(int i = 0; i <= o; ++i)
        id[i][i] = 1;
    return id;
}

vvi mult(vvi a, vvi b){
    int o = n;
    vvi ans = vvi(o + 1, vi(o + 1, 0));
    for(int i = 1; i <= o; ++i){
        for(int j = 1; j <= o; ++j){
            for(int k = 1; k <= o; ++k){
                ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) %mod )%mod;
            }
    }
    return ans;
}

vvi fe(vvi &mat, int e){
    vvi ans = identity(n);
    while(e){
        if(e & 1) ans = mult(ans, mat);
        mat = mult(mat, mat);
        e >>= 1;
    }
    return ans;
}

void show(vvi &mat){
    cout << "### matriz ###\n";
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);

    int x;
    while(cin >> n >> l){
        mat = vvi(n + 1, vi(n + 1, 0));
        cin >> s >> t;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < 4; ++j){
                cin >> x;
                mat[i][x]++; 
            }
        }
       // show(mat);
        vvi ans = fe(mat, l);
        cout << ans[s][t] << endl;
    }

    return 0;
}
