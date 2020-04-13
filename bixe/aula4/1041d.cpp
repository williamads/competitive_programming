#include<bits/stdc++.h>
#define ll long long
#define N 200123
#define ii pair<ll, ll>
#define fs first
#define sc second
#define oo 2000000123LL

using namespace std;

int n;
ll h, curr_x, curr_h, dist[N], af[N], l, r, ans;
ii par, last;

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> h;
    cin >> par.fs >> par.sc;

    af[0] = par.sc - par.fs;
    dist[0] = dist[n] = 0;
    dist[n] = oo;

    last = par;

    for(int i = 1; i < n; ++i){
        cin >> par.fs >> par.sc;
        af[i] = par.sc - par.fs;
        dist[i] = par.fs - last.sc;
        last = par;
    }

    /*
    for(int i = 0; i < n; ++i) cout << af[i] << ' ';
    cout << '\n';

    for(int i = 0; i < n; ++i) cout << dist[i] << ' ';
    cout << '\n';
    */

    int j = 0;
    for(int i = 0; i < n; ++i){
        while((j <= n) && (curr_h < h)){
            curr_x += af[j] + dist[j];
            curr_h += dist[j];

            if((j < n) && (curr_h < h))
                j++;
        }

        cout << "possivel " << (curr_x - dist[j] - af[j] + h - (curr_h - dist[j])) << '\n';
        if(curr_h >= h){
            ans = max(ans, curr_x - dist[j] - af[j]
                         + h - (curr_h - dist[j]));
        }
        
        cout << ans << '\n';
        curr_x = curr_x - af[i] - dist[i + 1];
        curr_h = curr_h - dist[i + 1];

        cout << i << ' ' << j << ' ' << curr_h << ' ' << curr_x << '\n';
    }

    cout << ans << '\n';
    return 0;
}
