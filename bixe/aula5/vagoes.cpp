#include<bits/stdc++.h>
#define N 1123

using namespace std;

int n, pos;
int v[N], vsort[N];
stack<int> p;

int main(){
    ios_base::sync_with_stdio(0);
    while((cin >> n) && n){
        while(!p.empty()) p.pop();

        for(int i = 0; i < n; ++i){
            cin >> v[i];
            vsort[i] = v[i];
        }

        sort(vsort, vsort + n);

        pos = 0;
        for(int i = 0; i < n; ++i){
            p.push(v[i]);
            
            while((!p.empty()) && (p.top() == vsort[pos])){
                pos++;
                p.pop();
            }

        }

        cout << (pos != n ? "no\n" : "yes\n");
    }
    return 0;
}
