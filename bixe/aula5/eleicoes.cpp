#include<bits/stdc++.h>

using namespace std;

int n, great, ans, x;
unordered_map<int, int> f;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(n--){
        cin >> x;
        f[x]++;
        if(f[x] > great){
            great = f[x];
            ans = x;
        }
    }
    cout << ans << '\n';
    return 0;
}
