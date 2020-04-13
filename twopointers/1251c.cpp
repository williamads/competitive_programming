#include<bits/stdc++.h>

using namespace std;

int T;
string s;
string par, impar, ans;

int main(){
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        par = impar = ans = "";

        cin >> s;

        int n = s.size();
        for(int i = 0; i < n; ++i){
            if((s[i] - '0') & 1){
                impar += s[i];
            }
            else par += s[i];
        }

        int i = 0, j = 0, tp = par.size(), ti = impar.size();
        while((i < tp) && (j < ti)){
            ans += ((par[i] < impar[j]) ? par[i++] : impar[j++]);
        }

        while(i < tp) ans += par[i++];
        while(j < ti) ans += impar[j++];

        cout << ans << '\n';
    }
    return 0;
}
