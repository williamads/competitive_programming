// Treap (probabilistic BST)
// O(logn) operations (supports lazy propagation)

#include<bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define INF 1e9
#define N 200123

using namespace std;

mt19937_64 llrand(random_device{}());

struct node {
	char val;
	int cnt, rev;
	char mn, mx, mindiff; // value-based treap only!
	ll pri;
	node* l;
	node* r;

	node() {}
	node(int x) : val(x), cnt(1), rev(0), mn('c'), mx('a'), mindiff('c'), pri(llrand()), l(0), r(0) {}
};
	
struct treap {
	node* root;
	treap() : root(0) {}
    treap(char s[], int n) {
        root = build(s, n);
    }

	~treap() { clear(); }

	int cnt(node* t) { return t ? t->cnt : 0; }
	int mn (node* t) { return t ? t->mn	: INF; }
	int mx (node* t) { return t ? t->mx	: -INF; }
	int mindiff(node* t) { return t ? t->mindiff : INF; }

	void clear() { del(root); }
	void del(node* t) {
		if (!t) return;
		del(t->l); del(t->r);
		delete t;
		t = 0;
	}

	void push(node* t) {
		if (!t or !t->rev) return;
		swap(t->l, t->r);
		if (t->l) t->l->rev ^= 1;
		if (t->r) t->r->rev ^= 1;
		t->rev = 0;
	}

	void update(node*& t) {
		if (!t) return;
		t->cnt = cnt(t->l) + cnt(t->r) + 1;
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
	void insert(int pos, int val) {
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

	char get_val(int pos) { return get_val(root, pos); }
	char get_val(node* t, int pos) {
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

    //int order_of_key(int val) {
    //    return order(root, val);
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
	int querymin(int i, int j) {
		if (i == j) return -1;
		auto t2 = split(root, j+1);
		auto t1 = split(t2.st, i);

		int ans = mindiff(t1.nd);
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
		printf("%d ", t->val);
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

    node* build (char s[], int n) {
        // Construct a treap on values {a[0], a[1], ..., a[n - 1]}
        if (n == 0) return NULL;
        int mid = n / 2;
        node * t = new node (s[mid]);
        t->l = build (s, mid);
        t->r = build (s + mid + 1, n - mid - 1);
        update(t);

        heapify (t);
        return t;
    }
};

char s[N];
int n, q, L, R;

char op, x, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L >> R;
    cin >> s;
    L--; R--;

    treap tp(s, n);

    cin >> q;

    while(q--) {
        cin >> op;
        if(op == 'Q') {
           cin >> x;
           if(x == 'R') {
               cout << tp.get_val(R);
           }
           else {
               cout << tp.get_val(L);
           }
        }
        else if(op == 'S') {
            cin >> c >> x;
            if(c == 'L') {
                if(x == 'R') L++;
                else L--;
            }
            if(c == 'R') {
                if(x == 'R') R++;
                else R--;
            }
        }
        else {
            tp.reverse(L, R);
        }
    }

    return 0;
}
