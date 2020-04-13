#include<bits/stdc++.h>

using namespace std;

int n, kg, ans, menor = 100000, curr;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    while(n--){
        cin >> kg >> curr;
        menor = min(menor, curr);
        ans += kg * menor;
    }
    cout << ans << '\n';
    return 0;
}
