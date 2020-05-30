#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define MAXN 1000011
#define sz(x) ((int)(x).size())

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
            ret.pb(((hashs[i][r]+MODS[i]-hashs[i][l-1])*ipot[i][MAXN-1-l-1])%MODS[i]);
        }
        return ret;
    }
};

// N tam da maior string 
void build(int N) {  
    ipot.resize(sz(MODS), vector<ll>(N+1, 0));
    for(int k = 0; k < sz(MODS); k++) {
        ipot[k][0] = 1;;
        for(int i = 1; i <= N; i++) {
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

int main(){
    build(MAXN);

    string sa = "mariamaria";
    string sb = "mariamaria";
    HASH ha = HASH(sa), hb = HASH(sb);

    if(eq(ha, hb)) cout << "strings iguais\n";
    else cout << "strigs diferentes\n";
    
    vector<ll> ra = ha.computeHASH(1, 3), rb = hb.computeHASH(6, 8);

    if(ra == rb) cout << "substring iguais\n";
    else cout << "substring diferentes\n";

    return 0;
}
