#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define N 1523
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define pb emplace_back
#define fs first
#define sc second
#define sz(x) ((int)((x).size()))
#define oo 1000000123
#define mod 1000000007LL

using namespace std;

ll BASE = 31;// primo maior que o tam do alfabt.
vector<ll> MODS = {1000000007, 1000000009};
vector< vector<ll> > ipot;

struct HASH { // 1-indexado mas deve passar a string 0-idex
    vector< vector<ll> > hashs; // hashs[2][sz(s) + 1]
    HASH(){}
    HASH(string str) {
        hashs.resize(sz(MODS), vector<ll>(sz(str)+1, 0));
        for(int k = 0; k < sz(MODS); k++) {
            for(int i = 0; i < sz(str); i++) {
                hashs[k][i+1] = (hashs[k][i] + (str[i]-'a') * ipot[k][i])%MODS[k];
            }
        }
    }
    // só para comparar substring
    // 1-indexado, codar só se for usar
    vector<ll> computeHASH(int l, int r) {
        vector<ll> ret;
        for(int i = 0; i < sz(MODS); i++) {
            ret.pb(((hashs[i][r]+MODS[i]-hashs[i][l-1])*ipot[i][N-1-l-1])%MODS[i]);
        }
        return ret;
    }
};

// N tam da maior string 
void build(int n) {  
    ipot.resize(sz(MODS), vector<ll>(N+1, 0));
    for(int k = 0; k < sz(MODS); k++) {
        ipot[k][0] = 1;
        for(int i = 1; i <= n; i++) {
            ipot[k][i] = (ipot[k][i-1]*BASE)%MODS[k];
        }
    }
}

// só para comparar substring
// codar só se for usar 
bool operator == (vector<ll> &a, vector<ll> &b) {
    for(int i = 0; i < sz(a); i++)
        if(a[i] != b[i])
            return 0;
    return 1;
}

int eq(HASH &ha, HASH &hb){
    return (ha.hashs[0].back() == hb.hashs[0].back() 
            && ha.hashs[1].back() == hb.hashs[1].back());
}

int K, n;
ll ac[N];
string s, gd;
HASH h;

int main(){
    ios_base::sync_with_stdio(0);
    build(N);
    cin >> s >> gd >> K;
    n = sz(s); 
    h = HASH(s);

    s = "#" + s;
    for(int i = 1; i <= n; ++i){
        ac[i] = ac[i-1] + 1 - (int)(gd[s[i]-'a'] - '0');
    }
    
    ll ans = 0;
    vll r;
    for(int l = 1; l <= n; ++l){
        set<pll>st;
        for(int i = 1; i + l - 1 <= n; ++i){
            if(ac[i+l-1] - ac[i-1] <= K){
                r = h.computeHASH(i, i + l - 1);
                st.insert(pll(r[0], r[1]));
            }
        }
        ans += sz(st);
    }

    cout << ans << '\n';
    return 0;
}
