#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    ll a, b, menor, fat[15];
    cin >> a >> b;
    menor = min(a, b);
    fat[0] = 1;
    for(ll i = 1; i <= 12; ++i){
        fat[i] = fat[i - 1] * i;
    }

    cout << fat[menor] << endl;
    return 0;
}
