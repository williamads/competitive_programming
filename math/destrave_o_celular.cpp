#include<bits/stdc++.h>
#define N 300
#define mod 1300031
#define int long long

using namespace std;

struct matrix{
    int r, c;
    int grid[N+5][N+5];
}mt, id, neutral;

void make_identity() {
    for(int i=0; i < N; ++i) {
        id.grid[i][i] = 1;
    }
}

void mkMat(int o){
    int u, v;
    mt.r = mt.c = o * o;
    for(int i = 0; i < o; ++i){
        for(int j = 0; j < o; ++j){
            u = i * o + j;
            for(int k = 0; k < o; ++k){
                for(int l = 0; l < o; ++l){
                    v = k * o + l;
                    if(__gcd(abs(i - k), abs(j - l)) == 1){
                        mt.grid[u][v] = 1;
                    }
                }
            }
            mt.grid[u][u] = 0;
        }
    }
}

void show(matrix mat){
    for(int i = 0; i < mat.r; ++i){
        for(int j = 0; j < mat.c; ++j){
            //cout << mat.grid[i][j] << ' ';
        }
        //cout << endl;
    }
}

matrix identity(int o){
    id.r = id.c = o;
    return id;
}

matrix mult(matrix a, matrix b){
    matrix ans;
    ans = neutral;
    ans.r = ans.c = a.r;
    int o = ans.r;
    for(int i = 0; i < o; ++i){
        for(int j = 0; j < o; ++j){
            for(int k = 0; k < o; ++k){
                ans.grid[i][j] = (ans.grid[i][j] + a.grid[i][k] * b.grid[k][j]);
            }
            if(ans.grid[i][j] > mod) ans.grid[i][j] %= mod;
        }
        
    }
    return ans;
}

matrix fe(matrix m, int e){
    matrix r = identity(m.r);
    //show(r);
    while(e){
        if(e & 1) r = mult(r, m);
        m = mult(m, m);
        e >>= 1;
    }

    return r;
}


int n, p, ans;

signed main(){
    make_identity();
    
    while(scanf("%lld %lld", &n, &p) && (n || p)){
        mkMat(n);
        
        mt = fe(mt, p-1);
        //show(mt);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                ans = (ans + mt.grid[i][j]) % mod;
            }
        }
        
        printf("%lld\n", ans);
        mt = neutral;
        ans = 0;
    }
    return 0;
}
