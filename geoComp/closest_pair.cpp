#include<iostream>
#include<math.h>
#include<set>
#define ii pair<int, int>
#define fs first
#define sc second

using namespace std;

typedef double T;

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
    return hypot(a.x - b.x, a.y - b.y);
}

int n;
point pt[100]; 

bool comp(point a, point b){
    if(a.y != b.y)
        return a.y < b.y;
    if(a.x != b.x)
        return a.x < b.x;
    return a.idx < b.idx;
}

set<point, bool(*)(point, point)> line (comp);

ii closest_pair(){
    sort(pt, pt + n);

    set<point, bool(*)(point, point)>::iterator cima, baixo;
    ii ans(0, 1);
    int ini = 0;
    double h = dist(pt[0], pt[1]), curr_h;
    point curr, curr2;
    line.insert(pt[0]);
    line.insert(pt[1]);
    //h = 10000000;
    for(int i = 2; i < n; ++i){
        //line.insert(pt[i]);

        while(pt[i].x - pt[ini].x > h) {
            line.erase(pt[ini]);
            ini++;
        }
        
        curr = curr2 = pt[i];
        curr.y += h;
        cima = line.lower_bound(curr);

        curr2.y -= h;
        baixo = line.lower_bound(curr2);
        if(baixo != line.begin()) baixo--;

        for(set<point, bool(*)(point, point)>::iterator it = baixo; it != line.end(); ++it){
            curr_h = dist(pt[i], *it);
            if(curr_h < h){
                h = curr_h;
                ans.fs = pt[i].idx;
                ans.sc = (*it).idx;
            }
        }

        line.insert(pt[i]);
        //if(cima == line.end()) cout << "fim ";
        //cout << *cima << endl;
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> pt[i].x >> pt[i].y;
        pt[i].idx = i;
    }

    ii ans = closest_pair();
    cout << "dist " << dist(pt[ans.fs], pt[ans.sc]) << endl;
    cout << ans.fs << ' ' << ans.sc << endl;
    return 0;
}
