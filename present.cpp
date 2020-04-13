#include<bits/stdc++.h>
#define ll long long
#define N 100123
#define oo 1000100123LL

using namespace std;

ll tirar[N], v[N];
int n, w, d;

int check(ll mid){
    ll ta = 0, c, dias_need = 0;
    for(int i = 0; i < n; ++i){
        c = mid - v[i];
        if(c - ta > 0){
            dias_need += c - ta;
            if(i + w - 1 < n)
                tirar[i + w - 1] = c - ta;
            ta += c - ta;
        }
        ta -= tirar[i];
        tirar[i] = 0;
    }
    return (dias_need > d);
}

int main(){
    ios_base::sync_with_stdio(0);
    
    cin >> n >> d >> w;

    ll menor = oo;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        menor = min(menor, v[i]);
    }
    
    ll lo = menor, hi = menor + d + 5LL, mid;
    while(lo < hi){
        mid = lo + (hi - lo) / 2LL;
        if(check(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo-1 << endl;
    return 0;
}
