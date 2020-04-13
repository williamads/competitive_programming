#include<bits/stdc++.h>
#define ll long long
#define N 100123
#define ii pair<ll, ll>
#define Square pair<ii, ii>
#define fs first
#define sc second
#define X first
#define Y second

using namespace std;

Square sq[N];
int n;
ll K;

bool cmp(Square a, Square b){
    if(a.fs.Y != b.fs.Y) return a.fs.Y < b.fs.Y;
    return a.sc.Y < b.sc.Y;
}

ll area(Square a){
    return (abs(a.fs.X - a.sc.X) * abs(a.fs.Y - a.sc.Y));
}

int f(ll lim){
    ll acum = 0;
    for(int i = 0; i < n; ++i){
        if(sq[i].fs.Y < lim){
            acum += area(Square(sq[i].fs, ii(sq[i].sc.X, min(sq[i].sc.Y, lim))));
        } 
    } 
    //cout << acum << '\n';
    return (acum >= K);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> K;
    for(int i = 0; i < n; ++i){
        cin >> sq[i].fs.X >> sq[i].fs.Y >> sq[i].sc.X >> sq[i].sc.Y;
    }
    sort(sq, sq + n, cmp);
    //for(int i = 0; i < n; ++i){
    //    cout << sq[i].fs.X << ' ' << sq[i].fs.Y << ' ' << sq[i].sc.X << ' ' << sq[i].sc.Y << '\n';
    //}
    ll lo = -1000000123, mid, hi = 1000000123;
    while(lo < hi){
        mid = lo + (hi - lo) / 2LL;
        //cout << lo << ' ' << mid << ' ' << hi << '\n';
        if(f(mid)) hi = mid;
        else lo = mid + 1;
    }
    ll acum = 0, lim = lo;
    for(int i = 0; i < n; ++i){
        if(sq[i].fs.Y < lim){
            acum += area(Square(sq[i].fs, ii(sq[i].sc.X, min(sq[i].sc.Y, lim))));
        } 
    } 
    if(acum >= K)
        cout << lo << '\n';
    else
        cout << "PERDAO MEU REI\n";
    return 0;
}
