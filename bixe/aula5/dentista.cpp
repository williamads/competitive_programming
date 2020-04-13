#include<bits/stdc++.h>

using namespace std;

int n, a, b;
stack<int> st;

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n;
    cin >> a >> b;

    st.push(b);
    n--;

    while(n--){
        cin >> a >> b;
        if(a < st.top() && b >= st.top()) continue;

        if(b < st.top()) st.pop();

        st.push(b);
    }

    cout << (int)(st.size()) << '\n';
    return 0;
}
