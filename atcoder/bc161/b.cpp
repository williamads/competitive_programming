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
    int n, m, cont = 0, a[123], total = 0;
    cin >> n >> m;
    for(int i =0; i < n; ++i){
        cin >> a[i];
        total += a[i];
    }
    for(int i = 0; i < n; ++i){
        if(4*m*a[i] >= total) cont++;
    }
    cout << ((cont >= m) ? "Yes\n" : "No\n");
    return 0;
}
