#include<bits/stdc++.h>

using namespace std;

int n, k;
string s;

int f(char x){
    int j = 0, tam = s.size(), qtd = 0, ans = 0;
    for(int i = 0; i < tam; ++i){
        while((j < tam) && ((s[j] == x) || (qtd < k))){
            if(s[j] != x) qtd++;
            j++;
        }

        if(s[i] != x){
            qtd--;
        }

        ans = max(ans, j - i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    cin >> s;
    int ans = max(f('a'), f('b'));
    cout << ans << '\n';

    return 0;
}

