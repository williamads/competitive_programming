#include<bits/stdc++.h>
#define N 1123

using namespace std;

int n, turn;
string s;
stack<char> p;

int main(){
    ios_base::sync_with_stdio(0);
    cin >> s;

    n = s.size();
    for(int i = 0; i < n; ++i){
        if((!p.empty()) && (p.top() == s[i])){
            p.pop();
            turn = 1 - turn;
        }
        else p.push(s[i]);
    }
    cout << ((turn == 0) ? "No\n" : "Yes\n");
    return 0;
}
