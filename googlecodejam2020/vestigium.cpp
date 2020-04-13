#include<bits/stdc++.h>

using namespace std;

int T, n;

int main(){
    ios_base::sync_with_stdio(0);
    int trace, row, colum, n, x;
    set<int> numb[123][2];

    cin >> T;
    for(int t = 1; t <= T; ++t){
        cin >> n;
        trace = 0;
        for(int i = 0; i < n; ++i){
            numb[i][0].clear();
            numb[i][1].clear();
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> x;
                numb[i][0].insert(x);
                numb[j][1].insert(x);
                if(i == j) trace += x;
            }
        }
        row = colum = 0;
        for(int i = 0; i < n; ++i){
            if(int(numb[i][0].size()) != n) ++row;
            if(int(numb[i][1].size()) != n) ++colum;
        }
        cout << "Case #" << t << ": " << trace << ' ' << row << ' ' << colum << '\n';
    }

    return 0;
}
