// aho-corasik
// questao: https://codeforces.com/contest/963/problem/D
#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vvi vector<vi>
#define ALPHA 26
#define pb emplace_back
 
using namespace std;
 
vvi occurr;
 
struct Node {
    int leaf;
    int link;
    int next[ALPHA];
    set<int> out;
    
    Node() {
        for(int i=0; i < ALPHA; ++i) {
            next[i] = 0;
        }
        leaf = link = 0;
    }
};
 
vector<Node> trie(1);
 
void insert(string &s, int id) {
    int node = 0;
    for(char ch : s) {
        if(!trie[node].next[ch - 'a']) {
            trie[node].next[ch - 'a'] = trie.size();
            trie.pb();
        }
        node = trie[node].next[ch - 'a'];
 
        // inicialization here
    }
    trie[node].leaf = 1;
    trie[node].out.insert(id);
}
 
void build() {
    queue<int> q;
 
    for(int i=0; i < ALPHA; ++i) {
        if(trie[0].next[i]) {
            q.push(trie[0].next[i]);
        }
    }
 
    while(!q.empty()) {
        int u = q.front(); q.pop();
 
        for(int ch=0; ch < ALPHA; ++ch) {
            int v = trie[u].next[ch];
            if(v) {
                q.push(v);
                int &link = trie[v].link;
                link = trie[u].link;
                
                while(link && trie[link].next[ch] == 0) {
                    link = trie[link].link;
                }
 
                if(trie[link].next[ch]) {
                    link = trie[link].next[ch];
                }
 
                if(trie[link].leaf) {
                    trie[v].leaf |= 2;
                    trie[v].out.insert(all(trie[link].out));
                }
            }
            else {
                trie[u].next[ch] = trie[trie[u].link].next[ch];
            }
        }
    }
}
 
int n;
string text;
vector<int> matches;
 
void find_matches(int u, int idx) {
    if(idx == text.size()) return;
 
    int v = trie[u].next[text[idx] - 'a'];
 
    if(trie[v].leaf) {
        for(int i : trie[v].out) {
            occurr[i].pb(idx);
        }
    }
 
    find_matches(v, idx + 1);
}
 
void print(string &txt) {
    for(int i=0; i < txt.size(); ++i) {
        cout << setw(2) << i << ' ';
    }
    cout << endl;
    for(char &c : txt) {
        cout << setw(2) << c << ' ';
    }
    cout << endl;
}
 
int x, v[100123];
string s[100123];
 
int main() {
    cin >> text;
    cin >> n;
 
    occurr = vvi(n, vi());
    for(int i=0; i < n; ++i) {
        cin >> v[i] >> s[i];
        insert(s[i], i);
    }
    build();
    find_matches(0, 0);
 
    for(int i=0; i < n; ++i) {
        if(occurr[i].size() < v[i]) {
            cout << "-1" << endl;
        }
        else {
            int ans = text.size();
            if(v[i] == 1) {
                cout << s[i].size() << endl;
                continue;
            }
            
 
            for(int j = v[i] - 1; j < occurr[i].size(); ++j) {
                ans = min(ans, occurr[i][j] - occurr[i][j - v[i] + 1] + (int)s[i].size());
                //cout << ' ' << (occurr[i][j] - occurr[i][j - v[i] + 1] + (int)s[i].size());
            }
            //cout << endl;
            cout << ans << endl;
        }
    }
 
    return 0;
}
