#include<bits/stdc++.h>

using namespace std;

struct Node { Node *next[26]; bool isLeaf; };

Node *makeNode(){
    Node *node = new Node;
    for(int i = 0; i < 26; ++i){
        node->next[i] = NULL;
    }
    node->isLeaf = false;
    return node;
}

Node *head;

void insert(string &s){
    Node *ptr = head;
    int curr;
    for(char c : s){
        curr = c - 'a';
        if(ptr->next[curr] == NULL)
            ptr->next[curr] = makeNode();
        ptr->isLeaf = false;
        ptr = ptr->next[curr];
    }
    ptr->isLeaf = true;
}

int dfs(Node *u){
    if(u->isLeaf) {
        delete(u);
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < 26; ++i){
        if(u->next[i] != NULL){
            cnt += dfs(u->next[i]);
        }
    }
    delete(u);
    return cnt;
}

int main(){
    int n;
    string s;
    while((cin >> n) && n){
        head = makeNode();
        int k = n;
        cin.ignore();
        while(k--){
            cin >> s;
            insert(s);
        } 
        if(dfs(head) == n) cout << "Conjunto Bom\n";
        else cout << "Conjunto Ruim\n";
    }
    return 0;
}

