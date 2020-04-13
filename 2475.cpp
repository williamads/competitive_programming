#include<bits/stdc++.h>
#define oo 1000000123

using namespace std;

int n, a, x;
int acum[1000];

int C(int i, int j){
    return (acum[j] - acum[i - 1]) * (j - i + 1);
}

int f(int k, int i){
    if(i == 0) return 0;
    if(k == 0) return oo;
    int ans = oo;
    for(int j = i; j >= 1; --j) 
        ans = min(ans, f(k - 1, j - 1) + C(j, i));
    return ans;
}

int main(){
    cin >> n >> a;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        acum[i] = x + acum[i - 1];
    }
    cout << f(a, n) << '\n';
    return 0; 
}
