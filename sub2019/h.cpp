#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll v, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> v >> n;
    
    v = v * n;
    cout << (v * 10 + 100 - 1) / 100;
    for(int i = 20; i < 100; i += 10){
        cout << ' ' << (v * i + 100 - 1) / 100;
    }
    cout << endl;
    return 0;
}
