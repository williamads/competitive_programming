#include<bits/stdc++.h>

using namespace std;

int T, n, x;
string s;

int main(){
    ios_base::sync_with_stdio(0);

    cin >> T;
    for(int t = 1; t <= T; ++t){
        cin >> s;
        n = s.size();
        int curr = 0;
        cout << "Case #"<< t << ": ";
        for(char c : s){
            x = c - '0'; 
            if(x > curr){
                int l = x - curr;
                while(l--) cout << "(";
            }
            if(x < curr){
                int l = curr - x;
                while(l--) cout << ")";
            }
            cout << x;
            curr = x;
        }
        while(curr--) cout << ")";
        cout << '\n';
    }

    return 0;
}
