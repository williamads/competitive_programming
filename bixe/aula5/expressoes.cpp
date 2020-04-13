#include<bits/stdc++.h>

using namespace std;

string s;
stack<char> p;
int t;
map<char, char> mcc;

int main(){
    ios_base::sync_with_stdio(0);

    mcc[')'] = '(';
    mcc[']'] = '[';
    mcc['}'] = '{';

    cin >> t;
    while(t--){
        while(!p.empty()) p.pop();

        cin >> s;

        int ans = 1;
        for(char c : s){
            if((c == '(') || (c == '[') || (c == '{')){
                p.push(c);
            }
            else if ((!p.empty()) && (p.top() == mcc[c])){
                p.pop();
            } 
            else if (((!p.empty()) && (p.top() != mcc[c])) || p.empty()){
                ans = 0;
                break;
            }
        }

        if(!p.empty()) ans = 0;
        cout << (ans ? "S\n" : "N\n");
    }
    return 0;
}
