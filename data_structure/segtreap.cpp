// Treap (probabilistic BST)
// O(logn) operations (supports lazy propagation)

#include<bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define INF 1e9
#define N 100123

using namespace std;

mt19937_64 llrand(random_device{}());

struct node {
	ll val, lazy, sum;
	int cnt, rev;
	ll mn, mx, mindiff; // value-based treap only!
	ll pri;
	node* l;
	node* r;

	node() {}
	node(ll x) : val(x), cnt(1), rev(0), mn(x), mx(x), mindiff(INF), pri(llrand()), l(0), r(0), lazy(0), sum(x) {}
};
	
struct treap {
	node* root;
	treap() : root(0) {}
    treap(ll a[], int n) {
        root = build(a, n);
    }

	~treap() { clear(); }

	int cnt(node* t) { return t ? t->cnt : 0; }
	ll mn (node* t) { return t ? t->mn	: INF; }
	ll mx (node* t) { return t ? t->mx	: -INF; }
	ll mindiff(node* t) { return t ? t->mindiff : INF; }
	ll lazy(node* t) { return t ? t->lazy : 0; }
	ll sum(node* t) { return t ? t->sum : 0; }

	void clear() { del(root); }
	void del(node* t) {
		if (!t) return;
		del(t->l); del(t->r);
		delete t;
		t = 0;
	}

	void push(node* t) {
        if(!t) return;
        if(t->lazy) {
            t->val += t->lazy;
            t->sum += cnt(t) * t->lazy;
            if (t->l) t->l->lazy += t->lazy;
            if (t->r) t->r->lazy += t->lazy;
            t->lazy = 0;
        }
		if (!t->rev) return;
		swap(t->l, t->r);
		if (t->l) t->l->rev ^= 1;
		if (t->r) t->r->rev ^= 1;
		t->rev = 0;
	}

	void update(node*& t) {
		if (!t) return;
		t->cnt = cnt(t->l) + cnt(t->r) + 1;

		t->mn = min(t->val, min(mn(t->l), mn(t->r)));
		t->mx = max(t->val, max(mx(t->l), mx(t->r)));
		t->mindiff = min(abs(mn(t->r) - t->val), min(abs(t->val - mx(t->l)), min(mindiff(t->l), mindiff(t->r))));
        push(t->l); push(t->r);
        t->sum = t->val + sum(t->l) + sum(t->r);
	}

	node* merge(node* l, node* r) {
		push(l); push(r);
		node* t;
		if (!l or !r) t = l ? l : r;
		else if (l->pri > r->pri) l->r = merge(l->r, r), t = l;
		else r->l = merge(l, r->l), t = r;
		update(t);
		return t;
	}

	pair<node*, node*> split(node* t, int pos) {
		if (!t) return {0, 0};
		push(t);

		if (cnt(t->l) < pos) {
			auto x = split(t->r, pos-cnt(t->l)-1);
			t->r = x.st;
			update(t);
			return { t, x.nd };
		}

		auto x = split(t->l, pos);
		t->l = x.nd;
		update(t);
		return { x.st, t };
	}

	// Position-based treap
	// used when the values are just additional data
	// the positions are known when it's built, after that you
	// query to get the values at specific positions
	void insert(int pos, ll val) {
		push(root);
		node* x = new node(val);
		auto t = split(root, pos);
		root = merge(merge(t.st, x), t.nd);
	}

	void erase(int pos) {
		auto t1 = split(root, pos);
		auto t2 = split(t1.nd, 1);
		delete t2.st;
		root = merge(t1.st, t2.nd);
	}

	ll get_val(int pos) { return get_val(root, pos); }
	ll get_val(node* t, int pos) {
		push(t);
		if (cnt(t->l) == pos) return t->val;
		if (cnt(t->l) < pos) return get_val(t->r, pos-cnt(t->l)-1);
		return get_val(t->l, pos);
	}
	// -------------------

	// Value-based treap
	// used when the values needs to be ordered
	//int order(node* t, int val) {
	//	if (!t) return 0;
	//	push(t);
	//	if (t->val < val) return cnt(t->l) + 1 + order(t->r, val);
	//	return order(t->l, val);
	//}

	//bool has(node* t, int val) {
	//	if (!t) return 0;
	//	push(t);
	//	if (t->val == val) return 1;
	//	return has((t->val > val ? t->l : t->r), val);
	//}

	//void insert(int val) {
	//	if (has(root, val)) return; // avoid repeated values
	//	push(root);
	//	node* x = new node(val);
	//	auto t = split(root, order(root, val));
	//	root = merge(merge(t.st, x), t.nd);
	//}

	//void erase(int val) {
	//	if (!has(root, val)) return;

	//	auto t1 = split(root, order(root, val));
	//	auto t2 = split(t1.nd, 1);
	//	delete t2.st;
	//	root = merge(t1.st, t2.nd);
	//}

	// Get the sum of interval [i,j]
	ll querysum(int i, int j) {
		auto t1 = split(root, j+1);
		auto t2 = split(t1.st, i);

		ll ans = sum(t2.nd);
		root = merge(merge(t2.st, t2.nd), t1.nd);
		return ans;
	}
    // Add value to all elements of an interval [i, j]
	void updatelazy(int i, int j, ll value) {
		auto t1 = split(root, j+1);
		auto t2 = split(t1.st, i);
        t2.nd->lazy += value;
		root = merge(merge(t2.st, t2.nd), t1.nd);
	}
	// Get the maximum difference between values
	int querymax(int i, int j) {
		if (i == j) return -1;
		auto t1 = split(root, j+1);
		auto t2 = split(t1.st, i);

		int ans = mx(t2.nd) - mn(t2.nd);
		root = merge(merge(t2.st, t2.nd), t1.nd);
		return ans;
	}

	// Get the minimum difference between values
	ll querymin(int i, int j) {
		if (i == j) return -1;
		auto t2 = split(root, j+1);
		auto t1 = split(t2.st, i);

		ll ans = mindiff(t1.nd);
		root = merge(merge(t1.st, t1.nd), t2.nd);
		return ans;
	}
	// ------------------

	void reverse(int l, int r) {
		auto t2 = split(root, r+1);
		auto t1 = split(t2.st, l);
		t1.nd->rev = 1;
		root = merge(merge(t1.st, t1.nd), t2.nd);
	}

	void print() { print(root); printf("\n"); }
	void print(node* t) {
		if (!t) return;
		push(t);
		print(t->l);
		printf("%lli ", t->val);
		print(t->r);
	}
    void heapify (node * t) {
        if (!t) return;
        node * max = t;
        if (t->l != NULL && t->l->pri > max->pri)
            max = t->l;
        if (t->r != NULL && t->r->pri > max->pri)
            max = t->r;
        if (max != t) {
            swap (t->pri, max->pri);
            heapify (max);
        }
    }

    node* build (ll a[], int n) {
        // Construct a treap on values {a[0], a[1], ..., a[n - 1]}
        if (n == 0) return NULL;
        int mid = n / 2;
        node * t = new node (a[mid]);
        t->l = build (a, mid);
        t->r = build (a + mid + 1, n - mid - 1);
        update(t);

        heapify (t);
        return t;
    }
    void create(ll a[], int n) {
        root = build(a, n);
    }
};

int t, op, l, r;
int n, q;
treap tp;
ll value, v[N];
int main() {
    scanf("%i", &t);
    while(t--) {
        scanf("%i %i", &n, &q);
        tp.create(v, n);

        while(q--) {
            scanf("%i", &op);
            if(op) {
                scanf("%i %i", &l, &r);
                printf("%lli\n", tp.querysum(l - 1, r - 1));
            }
            else {
                scanf("%i %i %lli", &l, &r, &value);
                tp.updatelazy(l - 1, r - 1, value);
            }
        }

    }
    return 0;
}
