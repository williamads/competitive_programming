// Word Combinations - https://cses.fi/problemset/task/1731/
// Idea:
//     dp[i] => How many ways you can build prefix i
//     considering all set of K strings
// 
//     dp[i] = sum of dp[i - j] for all j such that j 
//     is a suffix of prefix i and sufix j is in set 
//     of K strings
// 
//     j, nearest prefix which there is in the set,
//     is known as out link of the curr node in aho
//     automaton,

#include<bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define MOD 1000000007
#define ALPHA 26
#define pb emplace_back

using namespace std;

struct Node {
    int leaf;
    int out;
    int link;
    int depth;
    int next[ALPHA];
    Node() {
        for(int i=0; i < ALPHA; ++i) {
            next[i] = 0;
        }
        leaf = link = 0;
        depth = 0;
        out = 0;
    }
};

vector<Node> trie(1);

void insert(string &s) {
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
    trie[node].out = node;
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
                trie[v].depth = trie[u].depth + 1;
                int &link = trie[v].link;
                link = trie[u].link;
                
                while(link && trie[link].next[ch] == 0) {
                    link = trie[link].link;
                }

                if(trie[link].next[ch]) {
                    link = trie[link].next[ch];
                }

                if(!trie[v].out) {
                    trie[v].out = trie[link].out;
                }

                if(trie[link].leaf) {
                    trie[v].leaf |= 2;
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
        matches.pb(idx);
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


string s, t;
ll dp[5123];
int k;

int main() {
    cin >> s;
    cin >> k;

    for(int i=0; i < k; ++i) {
        cin >> t;
        insert(t);
    }

    build();

    dp[0] = 1;
    int u =0;
    for(int i=1; i <= s.size(); ++i) {
        u = trie[u].next[s[i - 1] - 'a'];
        int v = trie[u].out;

        while(v) {
            dp[i] = (dp[i] + dp[i - trie[v].depth - 1]) % MOD;
            v = trie[trie[v].link].out;
        }
    }

    cout << dp[s.size()] <<endl;
    return 0;
}
