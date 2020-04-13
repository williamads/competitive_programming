#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back

using namespace std;

int ta, tb, lim[200123];
vi pos[30];
string sa, sb;
char great;

int main(){
    ios_base::sync_with_stdio(0);
    int c;
    cin >> sa >> sb;
    
    ta = sa.size();
    tb = sb.size();

    for(int i = 0; i < ta; ++i){
        pos[sa[i] - 'a'].pb(i);
    }
  
    /*
    for(int i = 0; i < tb; ++i){
        c = sb[i] - 'a';
        cout << sb[i] << ": ";
        for(int x : pos[c]) cout << x << ' ';
        cout << '\n';
    }

    for(int i : pos[sb[35] - 'a']){
        printf("%d ", i);
    }
    puts("");
    puts("aqui");
    */
    lim[tb - 1] = pos[sb[tb - 1] - 'a'].back();
    for(int i = tb - 2; i >= 0; --i){
        c = sb[i] - 'a';
        //printf("%i\n", (int)pos[c].size());

        auto it = (lower_bound(pos[c].begin(), pos[c].end(), lim[i + 1]));
        it--;
        lim[i] = *it;
    }

    /*
    for(int i = 0; i < tb; ++i){
        cout << lim[i] << '\n';
    }
    */

    c = sb[tb - 1] - 'a';
    int lim_ult = *lower_bound(pos[c].begin(), pos[c].end(), lim[tb - 2]);
    lim_ult = ta - lim_ult - 1;
    c = sb[0] - 'a';
    int lim_pri = lim[0];
    cout << lim_pri << ' ' << lim_ult << '\n';
    int ans = max(lim_pri, lim_ult), x, last = -1;
    for(int i = 0; i < tb - 1; ++i){
        c = sb[i] - 'a';
        if(sb[i] == sb[i + 1]) continue;
        x = *lower_bound(pos[c].begin(), pos[c].end(), last);
        last = x;
        ans = max(ans, lim[i + 1] - x - 1);
        //cout << lim[i + 1] - x - 1 << '\n';
    }

    cout << ans << '\n';
    return 0;
}
