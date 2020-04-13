#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fs first
#define sc second
#define N 100123
 
using namespace std;
 
typedef long long T;
 
const ll oo = 1e18;
 
struct point{
    T x, y;
    int idx;
    point() { x = y = 0; }
    point(T _x, T _y) : x(_x), y(_y) {}
    point operator+(point p) {
        return {x + p.x, y + p.y};
    }
    point operator-(point p){
        return {x - p.x, y - p.y};
    }
    point operator*(T d){
        return {x * d, y * d};
    }
    point operator/(T d){
        return {x / d, y / d};
    }
};
 
bool operator==(point a, point b){
    return (a.x == b.x) && (a.y == b.y);
}
bool operator!=(point a, point b){
    return !(a == b);
}
bool operator<(point a, point b){
    if(a.x != b.x) { // prioridade 1 para x
        return a.x < b.x;
    }
    else{ // prioridade 2 para y (desempate)
        return a.y < b.y;
    }
}
ostream& operator<<(ostream& os, point p){
    return os << "(" << p.x << "," << p.y << ")";
}
 
T dist(point a, point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
 
int n;
point pt[N]; 
 
bool comp(point a, point b){
    if(a.y != b.y)
        return a.y < b.y;
    if(a.x != b.x)
        return a.x < b.x;
    return a.idx < b.idx;
}
 
ii closest_pair(){
    ii ans(-1, -1);
    int ini = 0; 
    T curr_h, h = oo;
    
    set<point, bool(*)(point, point)> line (comp);
    sort(pt, pt + n);
 
    for(int i = 0; i < n; ++i){
        while((ini < i) && dist(pt[ini], pt[i]) > h){
            line.erase(pt[ini++]);
        }
        
        auto it = line.lower_bound(point(pt[i].x - h, pt[i].y - h));
        for(; (it != line.end()) && ((*it).y <= pt[i].y + h); it++){
            curr_h = dist(pt[i], *it);

            if(curr_h < h){
                h = curr_h;
                ans.fs = pt[i].idx;
                ans.sc = (*it).idx;
            }
        }
 
        line.insert(pt[i]);
    }
    return ans;
}
 
ll acum[N], x;
 
int main(){
    ios_base::sync_with_stdio(0);
    scanf("%d", &n);
    scanf("%lld", &acum[0]);
    pt[0] = point(0, acum[0]);
    pt[0].idx = 0;
    for(int i = 1; i < n; ++i){
        scanf("%lld", &x);
        acum[i] = acum[i - 1] + x;
        pt[i] = point(i, acum[i]);
        pt[i].idx = i;
    }
 
    ii ans = closest_pair();
    printf("%lld\n", dist(pt[ans.fs], pt[ans.sc]));
    return 0;
}
