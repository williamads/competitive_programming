#include<bits/stdc++.h>
#define fs first
#define sc second
#define N 2100123
#define ll long long
#define int long long
#define ii pair<ll, ll>
#define segment pair<point, point>
#define pb push_back
#define oo 1000000123
#define p1 first
#define p2 second
#define vi vector<int>
#define pb push_back
#define vii vector<ii>

using namespace std;

unordered_map<int, unordered_map<int, ii> > dp;

struct point {
	int x, y;
	int left, idx, up;
    int type;
	point() { x = y = 0; }
	point(int _x, int _y) : x(_x), y(_y) {}
	point(int _x, int _y, int _idx, int _esq, int _up) : x(_x), y(_y), idx(_idx), left(_esq), up(_up) {}
	bool operator < (point other) const{
		if(x < other.x)
			return 1;
		else return y < other.y;
	}
	bool operator == (point other) const{
		return (x == other.x) && (y == other.y);
	}
};

int n, c;
vector<segment> segments;
vector<point> points;
vii adj;

// verifica se um ponto b esta abaixo da reta ac
// retorna negativo se esta abaixo e positivo cc

ll cross(point a, point b, point c){
    ll dx1 = a.x - b.x, dy1 = a.y - b.y;
    ll dx2 = c.x - b.x, dy2 = c.y - b.y;

    return dx1*dy2 - dx2*dy1;
}

bool comp(int a, int b){
    segment sa = segments[a], sb = segments[b];
    if(sa.p1.x > sb.p1.x){
        return cross(sb.p1, sa.p1, sb.p2) < 0;
    }
    else if(sb.p1.x > sa.p1.x) {
        return cross(sa.p1, sb.p1, sa.p2) > 0;
    }
    return false;
}

set<int, bool(*)(int,int)> lines (comp);

int segmento_acima(int id){
    set<int, bool(*)(int,int)>::iterator it;

    it = lines.find(id);
    it++;
    if(it == lines.end()){
        return -1;
    }
    else{
        return *it;
    }
}

void line_sweep(){
    int tam = points.size();
    int idx_acima, idx;
    segment seg_acima;

    for(int i = 0; i < tam; ++i){
        idx = points[i].idx;
        if((idx <= n) && points[i].left){ // encosta em seg
            lines.insert(idx);

            if(segments[idx].p1.y > segments[idx].p2.y){
                idx_acima = segmento_acima(idx);
                adj[idx] = {idx_acima, points[i].x};
            }
        }
        else if((idx <= n) && !points[i].left){ // sai do seg
            if(segments[idx].p2.y > segments[idx].p1.y){
                idx_acima = segmento_acima(idx);
                adj[idx] = {idx_acima, points[i].x};
            }

            lines.erase(idx);
        }
        else if(idx > n){ // ponto de consulta
            if(lines.size() == 0){
                adj[idx] = {-1, points[i].x};

            }
            else {
                idx_acima = *lines.begin();
                adj[idx] = {idx_acima, points[i].x};
            }
        }
    }
}

ii f(int i, int x_debaixo){
    if(i == -1) return {x_debaixo, -1};
    if(dp[i].count(x_debaixo)) return dp[i][x_debaixo];

    if(adj[i].fs == 0)
        return dp[i][x_debaixo] = {x_debaixo, segments[i].p1.y};

    return dp[i][x_debaixo] = f(adj[i].fs, adj[i].sc);
}

vector<point> original;
bool cmp(point a, point b){
    if(a.x != b.x){
        return a.x < b.x;
    }
    return a.type < b.type;
}
signed main(){
	ios_base::sync_with_stdio(0);
	
	point a, b;
	int xa, ya, xb, yb;
	while(cin >> n >> c){
		segments = vector<pair<point, point>>(n+1);
	    points.clear();
        adj = vii(N);

		
		for(int i = 1; i <= n; ++i){
			cin >> a.x >> a.y >> b.x >> b.y;
			
            if(a.x > b.x) swap(a, b);

			a.idx = b.idx = i;
			a.left = 1; b.left = 0;
            a.type = 1; b.type = 3;

			if(a.y < b.y) a.up = 0, b.up = 1;
			else if(a.y > b.y) a.up = 1, b.up = 0;
			else a.up = b.up = -1;

			segments[i] = segment(a, b);
			
			points.pb(a);
			points.pb(b);
		}

        original.clear();
        for(int i = n + 1; i <= n + c; ++i){
            cin >> a.x;
            a.y = 0;
            a.idx = i;
            a.type = 2;
            original.pb(a);
            points.pb(a);
        }

        sort(points.begin(), points.end(), cmp);

        lines.clear();
        line_sweep();


        ii ans;
        int idx;
        for(int i = 0; i < c; ++i){
            idx = original[i].idx;
            if(adj[idx].sc == -1) {
                cout << original[i].x << endl;
            }
            else{
                ans = f(adj[idx].fs, original[i].x);
                if(ans.sc == -1){
                    cout << ans.fs << endl;
                }
                else {
                    cout << ans.fs << ' ' << ans.sc << endl;
                }
            }
        }
        dp.clear();
	}
	return 0;
}

