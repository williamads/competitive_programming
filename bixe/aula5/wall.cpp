#include<bits/stdc++.h>
#define ll long long
#define N 200123

using namespace std;

int n;
int x;
stack<int> st;

int main(){
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        x &= 1;
        if((!st.empty()) && (st.top() == x))
            st.pop();
        else
            st.push(x);
    }
    cout << (st.size() <= 1 ? "YES\n" : "NO\n"); 
    return 0;
}
