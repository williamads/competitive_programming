#include<bits/stdc++.h>
#define ll long long
#define Tipo int
#define ii pair<Tipo, Tipo>
#define vi vector<Tipo>
#define vii vector<ii>
#define fs first
#define sc second
#define oo 1000000009
#define N 200123

using namespace std;

int f(ll x){
    int r;
    string s;
    while(x){
        s += (x % 10 + '0');
        x /= 10;
    }
    int atu, ant;
    for(int i = 1; i < s.size(); ++i){
        atu = s[i] - '0';
        ant = s[i-1] - '0';
        if(abs(atu - ant) > 1) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cout << "ans[N] = {";
    for(ll i = 1; i <= 3234566867; ++i) {
        if(f(i)) {
            if(i == 1) cout << i;
            else{
                cout << ", " << i;
            }
        }
    }
    cout << "};";
    return 0;
}
