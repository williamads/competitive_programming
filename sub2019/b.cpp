#include<bits/stdc++.h>

using namespace std;

int n, m, idx, v[10012];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        if(v[i] > m){
            m = v[i];
            idx = i;
        }
    }

    if(idx == 0) cout << "S\n";
    else cout << "N\n";
    return 0;
}
