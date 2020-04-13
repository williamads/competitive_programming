#include<bits/stdc++.h>
#define ll long long
#define N 200123
#define oo 2000000123LL

using namespace std;

int n;
ll h, xstart[N], xend[N], af, ans;

int main(){
    ios_base::sync_with_stdio(0);
    
    cin >> n >> h;
    for(int i = 0; i < n; ++i){
        cin >> xstart[i] >> xend[i];
    }

    xstart[n] = xend[n] = oo;
    n++;

    int l = 0;
    for(int r = 0; r < n; ++r){
        while(xstart[r] - xstart[l] - af >= h){
            af -= (xend[l] - xstart[l]);
            l++;
        }
        af += xend[r] - xstart[r];
        ans = max(ans, af);
    } 

    cout << ans + h << '\n';
    return 0;
}
