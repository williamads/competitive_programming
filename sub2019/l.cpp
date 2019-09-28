#include<bits/stdc++.h>
#define ll long long 

using namespace std;

ll n, x;

int main(){
    cin >> n;
    x = (1LL << __builtin_popcountll(n));
    if(x < 0LL) while(1);
    cout << x << endl;
    return 0;
}
