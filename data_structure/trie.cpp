#include<bits/stdc++.h>

using namespace std;

struct Node{ Node *next[26]; bool isLeaf; };

Node *makeNode(){
    Node *node = new Node;
    for(int i = 0; i < 26; ++i){
        node->next[i] = NULL;
    }
    node->isLeaf = false;
    return node;
}

Node *root;

void insert(string &s){
    Node *ptr = root;
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

void display(Node *u, string s){
    if(u->isLeaf){
        cout << s << '\n';
    }

    for(int i = 0; i < 26; ++i){
        if(u->next[i] != NULL){
            s += i + 'a';
            display(u->next[i], s);
            s.pop_back();
        }
    }
}

int main(){
    root = makeNode();
    int n;
    char str[20];
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        insert(s);
    }
    display(root, "");
    return 0;
}
