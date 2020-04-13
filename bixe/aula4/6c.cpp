#include<bits/stdc++.h>
#define N 100123

using namespace std;

int n, v[N];

int main(){
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    int alice = 0, bob = 0;
    for(int i = 0, j = n - 1; i < j; ){
        if(v[i] < v[j]){
            v[j] -= v[i];
            v[i] = 0;
            i++;
            alice++;
            if(i == j) bob++;
        }
        else if(v[j] < v[i]){
            v[i] -= v[j];
            v[j] = 0;
            j--;
            bob++;
            if(i == j) alice++;
        }
        else {
            v[i] = v[j] = 0;
            i++; alice++;
            j--; bob++;
            if(i == j) alice++;
        }
    }
    if(n == 1) alice++;
    cout << alice << ' ' << bob << '\n';
    return 0;
}
