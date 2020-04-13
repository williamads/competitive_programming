#include<bits/stdc++.h>
#define ll long long
#define Tipo int
#define ii pair<Tipo, Tipo>
#define vi vector<Tipo>
#define vii vector<ii>
#define fs first
#define sc second
#define oo 1000000009
#define N 200123

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    n %= m;
    cout << min(n, abs(n - m)) << '\n';
    return 0;
}
