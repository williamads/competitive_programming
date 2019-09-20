#include <bits/stdc++.h>
#define left(x) (x << 1)
#define right(x) ((x << 1) | 1)
#define mid(a, b) ((a + b) >> 1)
#define comp(a, b) max(a, b)
#define oo 1e9
#define N 1000123

#define int long long

using namespace std;

int tree[N], a[N];
int n, m;

int build(int u, int l, int r) {
    if(l == r) return tree[u] = a[l];
    build(left(u), l, mid(l, r));
    build(right(u), mid(l, r) + 1, r);
    return tree[u] = comp(tree[left(u)], tree[right(u)]);
}

void update(int u, int i, int j, int idx, int value) {
    if(j < idx || i > idx) return;
    if(i == j) {
        tree[u] = value;
        return;
    }
    update(left(u), i, mid(i, j), idx, value);
    update(right(u), mid(i, j) + 1, j, idx, value);
    tree[u] = comp(tree[left(u)], tree[right(u)]);
}

void update(int idx, int value) {
    update(1, 1, n, idx, value);
}

int query(int u, int i, int j, int l, int r) {
    if(j < l || i > r) return -oo;
    if(l <= i && j <= r) return tree[u];
    int lans = query(left(u), i, mid(i, j), l, r);
    int rans = query(right(u), mid(i, j) + 1, j, l, r);
    return comp(lans, rans);
}

int query(int l, int r) {
    return query(1, 1, n, l, r);
}

vector <int> primes = {2};
bitset<5000123> comp;

void sieve() {
    for (int i = 3; i < 5000123; i += 2) {
        if (not comp[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < 5000123; j += i) {
                comp[j] = 1;
            }
        }
    }
    for(int i = primes.back() + 2; i < 5000123; i += 2) {
        if(not comp[i]) primes.push_back(i);
    }
}

int get_prime(int n) {
    int ans = 1;
    for(int p : primes) {
        while(n % p == 0) {
            n /= p;
            ans = p;
        }
        if(p > n) return ans;
    }
    return ans;
}


int op, l, r, k;

signed main() {
    ios_base::sync_with_stdio(0);
    sieve();
    cin >> n >> m;
    for(int i=1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    k = n;
    int prime, new_n = n;

    while(m--) {
        cin >> op;
        if(op == 1) {
            k = new_n >> 1;
            for(int i=1; i <= k; ++i) {
                a[i] += a[new_n + 1 - i];
                prime = get_prime(a[i]);
                update(i, prime);
            }
            new_n = (int)ceil((new_n + .0)/2.0);
        }
        else {
            cin >> l >> r;
            if(l > new_n) {
                cout << 0 << endl;
                continue;
            }   
            r = min(new_n, r);
            cout << query(l , r) << endl;
        }
    }
    
	return 0;
}
