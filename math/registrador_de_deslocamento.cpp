#include<iostream>
#include<unordered_map>
#include<math.h>
#define ll long long
#define oo (1LL << 35)
#define N 35

using namespace std;

struct matrix {
    int r;
    int c;
    ll data[N][N];
};

matrix identity, neutral;

inline void initialize_identity() {
    identity.r = N;
    identity.c = N;
    for(int i=0; i < N; ++i) identity.data[i][i] = 1;
}

inline matrix make_identity(int n) {
    identity.r = n;
    identity.c = n;
    return identity;
}

inline void initialize_matrix(matrix &a, int n, int m) {
    a.r = n;
    a.c = m;
    for(int i=0; i < a.r; ++i) {
        for(int j=0; j < a.c; ++j) {
            a.data[i][j] = 0;
        }
    }
}

inline void show_matrix(matrix a) {
    puts("##### matrix a ######");
    for(int i=0; i < a.r; ++i) {
        for(int j=0; j < a.c; ++j) {
            printf("%lli ", a.data[i][j]);
        }
        puts("");
    }
}


inline matrix matrix_product(matrix a, matrix b) {
    matrix res;
    res = neutral;
    res.r = a.r;
    res.c = b.c;
    for(int i=0; i < a.r; ++i) {
        for(int j=0; j < b.c; ++j) {
            for(int k=0; k < b.c; ++k) {
                res.data[i][j] ^= a.data[i][k] & b.data[k][j];
            }
        }
    }
    return res;
}

inline matrix fe(matrix b, int e, int n) {
    matrix res = make_identity(n);
    while(e) {
        if(e & 1) res = matrix_product(res, b);
        b = matrix_product(b, b);
        e >>= 1;
    }
    return res;
}

inline ll matrix_to_int(matrix a) {
    ll res = 0;
    for(int i=0; i < a.c; ++i) {
        res |= a.data[0][i] << i;
    }
    return res;
}

inline matrix dec_to_bin(int n, int size) {
    matrix res;
    res = neutral;
    res.r = 1;
    res.c = size;
    for(int i=0; i < size; ++i) {
        res.data[0][i] = (n & 1);
        n >>= 1;
    };
    return res;
}

inline ll phi(ll n) {
    ll result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


ll v[N], x;
int init, fim;

inline ll solve(matrix a, ll b, matrix t, ll m, int size, ll trans) {
    ll n = (ll) sqrt (m + .0) + 1;

    matrix an = fe(t, n, size); 

    unordered_map<ll, ll> vals;
    matrix curr = an, partial;
    ll query;
    for (int p = 1; p <= n; ++p) {
        partial = matrix_product(a, curr);
        query = matrix_to_int(partial);
        if (!vals.count(query)) {
            vals[query] = p;
        }
        curr = matrix_product(curr, an);
    }
    ll ans = oo, cur = b, subtrans, lsb;

    for (int q = 0; q <= n; ++q) {
        query = cur;
        if (vals.count(query)) {
            ans = min(ans, vals[query] * n - q);
        }
        subtrans = trans;

        subtrans &= cur;
        lsb = 0;
        while(subtrans) {
            subtrans -= (subtrans & -subtrans);
            lsb ^= 1;
        }
        cur |= (lsb << size);
        cur >>= 1;
    }
    return ans;
}


matrix init_v, fim_v, rt;
ll ans;
int n, t;
ll trans;

int main() {
    initialize_identity();
    while(scanf("%i %i", &n, &t)&& (n || t)) {
        rt = neutral;
        rt.r = n;
        rt.c = n;
        trans = 0LL;

        for(int i=0; i < t; ++i) {
            scanf("%lli", &x);
            rt.data[x][n - 1] = 1;
            trans |= (1LL << x);
        }
        for(int i=0; i < n - 1; ++i) {
            rt.data[i + 1][i] = 1;
        }
        scanf("%x %x", &init, &fim);

        init_v = dec_to_bin(init, n);
        fim_v = dec_to_bin(fim, n);
        fim = matrix_to_int(fim_v);

        ans = solve(init_v, fim, rt, 1LL << n, n, trans); 
        if(ans == oo) {
            printf("*\n");
        }
        else {
            printf("%lli\n", ans);
        }

    }
    return 0;
}
