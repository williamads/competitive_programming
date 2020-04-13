#include<bits/stdc++.h>
#define oo 1000000123

using namespace std;

string sa, sb;
int ta, tb, dp[210][210];

int f(int i, int j, int last){
    if(j == tb) return ta - i;
    if(i == ta) return oo;

    if(~dp[i][j]) return dp[i][j];

    int ans = 0, curr, entrou = 0;
    for(int k = i; k < ta; ++k){
        if(sa[k] == sb[j]){
            curr = f(k + 1, j + 1, k);
            if(curr == oo) continue;
            entrou = 1;
            ans = max(ans, curr);
            if(j == 0)
                ans = max(k, ans);
            else
                ans = max(k - last - 1, ans);
        }
    }
    
    return dp[i][j] = (entrou ? ans : oo);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> sa >> sb;
    ta = sa.size(), tb = sb.size();
   
    memset(dp, -1, sizeof(dp));

    cout << f(0, 0, 0) << '\n';
    return 0;
}
