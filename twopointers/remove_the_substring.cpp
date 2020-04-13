#include<bits/stdc++.h>
#define N 200123

using namespace std;

string sa, sb;
int ta, tb, ans, lim[N];

int main(){
    ios_base::sync_with_stdio(0);

    cin >> sa >> sb;
    ta = sa.size();
    tb = sb.size();

    int pos = ta - 1;
    for(int i = tb - 1; i >= 0; --i){
        while(sb[i] != sa[pos]) pos--;
        lim[i] = pos--;
    }

    /*
    for(int i = 0; i < tb; ++i){
        cout << lim[i] << ' ';
    }
    cout << '\n';
    */

    pos = 0;
    int r_lim;
    for(int i = 0; i < ta; ++i){
        r_lim = ta - 1;
        if(pos < tb) r_lim = lim[pos] - 1;
        ans = max(ans, r_lim - i + 1);
        //cout << i << ' ' << r_lim << '\n';
        if(pos < tb && sb[pos] == sa[i]) ++pos;
    }

    cout << ans << '\n';
    return 0;
}
