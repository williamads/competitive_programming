#include<bits/stdc++.h>
#define ll long long
#define N 10123
#define vi vector<ll>
#define pb emplace_back

using namespace std;

ll p[N];
vi root;
int grau;

void mult(ll ti){
    grau++;
    p[grau] = 1;
    if(grau == 1){
        p[0] = ti;
        return;
    }
    for(int i = grau - 1; i > 0; --i){
        p[i] = p[i-1] + p[i] * ti;
    }
    p[0] = p[0] * ti;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    for(int i = 1; i < (int)(s.size()); ++i)
        if(s[i] != s[i - 1])
            root.pb(-((2*(i+1)) - 1));
    for(ll x : root)
        mult(x);
    if((int)(root.size()) == 0) {
        if(s[0] == 'H') cout << 0 << '\n' << 1 << '\n';
        else cout << 0 << '\n' << -1 << '\n';
        return 0;
    }
    ll f;
    if((s[0] == 'H' && p[0] < 0)||(s[0] == 'A' && p[0] > 0)) f = -1;
    else f = 1;
    cout << grau << '\n' << (f*p[grau]);
    for(int i = grau - 1; i >= 0; --i)
        cout << ' ' << (f*p[i]);
    cout << '\n';
    return 0;
}
