#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define N 100123
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define pb push_back
#define fs first
#define sc second
#define oo 1000000123
#define sz(x) ((int)((x).size()))
#define iii pair<int, ii>
#define eps 1e-9

using namespace std;

const double pi = acos(-1);
int n;
double v[N], x, y;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        double r = atan2(y, x);
        if(r < -eps) r = 2.0 * pi + r;
        v[i] = r;
    }
    sort(v, v + n);
    for(int i = 0; i < n; ++i){
        cout << (v[i] / pi * 180.0) << ' '; // em grau
    }
    cout << endl;
    return 0;
}
