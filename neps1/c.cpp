#include<bits/stdc++.h>
#define ll long long
#define N 100123

using namespace std;

int n;
ll v[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v, v + n);
    for(int i = n - 1; i > 1; --i){
        if(v[i] < (v[i-1] + v[i-2])){
            cout << v[i-2] << ' ' << v[i-1] << ' ' << v[i] << '\n';
            return 0;
        } 
    }
    return 0;
}
