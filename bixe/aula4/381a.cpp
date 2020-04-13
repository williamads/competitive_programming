#include<bits/stdc++.h>

using namespace std;

int n, a, b, v[1123];

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> v[i];

    int i = 0, j = n - 1, turn = 0;
    while(i <= j){
        if(turn == 0){
            if(v[i] > v[j]){
                a += v[i];
                i++;
            }
            else a += v[j--];
        }
        else b += ((v[i] > v[j]) ? v[i++] : v[j--]);

        turn = 1 - turn;
    }

    cout << a << ' ' << b << '\n';
    return 0;
}
