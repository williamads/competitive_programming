#include<bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii>
#define fs first
#define sc second.first
#define idx second.second

using namespace std;

int T, n;
iii act[1123];
char ans[1123];

bool cmp(iii a, iii b){
    if(a.fs != b.fs) return a.fs < b.fs;
    return a.fs < b.fs;
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> T;
    for(int t = 1; t <= T; ++t){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> act[i].fs >> act[i].sc;
            act[i].idx = i;
        }
        sort(act, act + n, cmp);
        int tp = 0, ts = 0, imp = 0;
        for(int i = 0; i < n; ++i){
            if(act[i].fs < tp && act[i].fs < ts){
                imp = 1;
                break;
            }       
            if(act[i].fs >= tp){
                tp = act[i].sc;
                ans[act[i].idx] = 'C';
            }
            else{
                ts = act[i].sc;
                ans[act[i].idx] = 'J';
            }
        }
        cout << "Case #" << t << ": ";
        if(imp) cout << "IMPOSSIBLE\n";
        else{
            for(int i = 0; i < n; ++i) cout << ans[i];
            cout << '\n';
        }
    }

    return 0;
}
