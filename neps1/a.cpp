#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll v[200123];

int main(){
    ios_base::sync_with_stdio(0);
    nt n;
    cin > n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];       
    }
    cout << max(v[0]*v[1]*v[n-1], v[n-3]*v[n-2]*v[n-1]) << '\n';
    return 0;
}
