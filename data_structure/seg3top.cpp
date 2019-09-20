#define _ ios_base::sync_with_stdio(0);
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)
#define mid(a, b) ((a + b) >> 1)
#define comp(a, b) (a + b)
#define MAX 1000123
#define OUT 0
#define ull unsigned long long
#define vi vector<ull>
#define N 1000007
 
using namespace std;
 
ull tree[N], lazy[N], deactivate[N];
int n, q;
 
void push(int u, int l, int r) {
    if(deactivate[u]) {
        tree[u] = 0;
        deactivate[u] = 0;
        if(l != r) {
            lazy[left(u)] = 0;
            lazy[right(u)] = 0;
            deactivate[left(u)] |= 1;
            deactivate[right(u)] |= 1;
        }
    }
    if(lazy[u] == OUT) return;
	tree[u] += lazy[u] * (r - l + 1);
	if(l != r) {
		lazy[left(u)] += lazy[u];
		lazy[right(u)] += lazy[u];
	}
	lazy[u] = OUT;
}
 
void update(int u, int i, int j, int l, int r, ull value, int act) {
	push(u, i, j);
	if(i > r || j < l) return;
	if(l <= i && j <= r) {
        if(act == 1) {
            deactivate[u] = 1;
            lazy[u] = 0;
        }
        else {
            lazy[u] += value;
        }
        push(u, i, j);
        return;
	}	
	update(left(u), i, mid(i, j), l, r, value, act);
	update(right(u), mid(i, j) + 1, j, l, r, value, act);
	tree[u] = comp(tree[left(u)], tree[right(u)]);
}
 
void update(int l, int r, ull value, int act) {
	update(1, 1, n, l, r, value, act);
}
 
ull query(int u, int i, int j, int l, int r) {
	push(u, i, j);
	if(i > r || j < l) return OUT;
	if(l <= i && j <= r) return tree[u];
	
	ull lans = query(left(u), i, mid(i, j), l, r);
	ull rans = query(right(u), mid(i, j) + 1, j, l, r);
	
	return comp(lans, rans);
}
 
ull query(int l, int r) {
	return query(1, 1, n, l, r);
}
 
int op, r, l, x;
ull ans;
 
int main() {_
    cin >> n >> q;
    while(q--) {
        cin >> op >> l >> r;
        if(op == 1) {
            cin >> x;
            update(l, r, x, 0);
        }
        else if(op == 2) {
            ans += query(l, r);
            update(l, r, 0LL, 1);
            cout << ans << endl;
        }
        else if(op == 3) {
            cerr << query(l, r) << endl;
        }
    }
    return 0;
}
