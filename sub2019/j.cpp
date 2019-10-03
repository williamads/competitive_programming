#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

struct player{
    vi freq;
    int joker, canPass;
}p[15];

int n, k;

void show(int idx){
    int x;

    cout << "Player " << idx << ": ";
    for(int i = 1; i <= 13; ++i){
        x = p[idx].freq[i];
        while(x--) cout << i << ' ';
    }
    if(p[idx].joker) cout << "J ";
    cout << endl << endl;
}

void show(){
    cout << "------------------------\n";

    for(int i = 0; i < n; ++i){
        show(i);
    }

    cout << "------------------------\n";
}

int szHand(int idx){
    int ct = 0, tam = p[idx].freq.size();
    for(int i = 0; i < tam; ++i){
        ct += p[idx].freq[i];
    }
    return ct + p[idx].joker;
}

int getWin(){
    for(int idx = 0; idx < n; ++idx){
        if(p[idx].joker || (szHand(idx) != 4)) continue;

        vi f = p[idx].freq;
        for(int i = 1; i <= 13; ++i){
            if(f[i] == 4)
                return idx;
        }
    }
    return -1;
}

int getCard(int idx){
    if(p[idx].joker && p[idx].canPass) {
        p[idx].joker = p[idx].canPass = 0;
        return 0;
    }
   
    if(p[idx].joker) 
        p[idx].canPass = 1;

    int menor = 10, id_menor = 1000;
    for(int i = 1; i <= 13; ++i){
        if((p[idx].freq[i] < menor)&&(p[idx].freq[i])){
            menor = p[idx].freq[i];
            id_menor = i;
        }
    }

    p[idx].freq[id_menor]--;
    return id_menor;
}

void pushCard(int idx, int card){
    if(!card) {
        p[idx].joker = 1;
        p[idx].canPass = 0;
        return;
    }

    p[idx].freq[card]++;
}

int main(){
    char c;
    cin >> n >> k;
    k--; // 0-idx
    for(int i = 0; i < n; ++i){
        p[i].freq = vi(15, 0);
        p[i].joker = 0;
        p[i].canPass = 0;
        for(int j = 0; j < 4; ++j){
            cin >> c;
            if(c == 'A') p[i].freq[1]++;
            else if(c == 'D') p[i].freq[10]++;
            else if(c == 'Q') p[i].freq[11]++;
            else if(c == 'J') p[i].freq[12]++;
            else if(c == 'K') p[i].freq[13]++;
            else p[i].freq[(int) c - '0']++;
        }
    }

    p[k].joker = 1;
    p[k].canPass = 0;

    //show();

    int win = getWin(), i = k;
    while(win == -1){
        pushCard((i + 1) % n, getCard(i));
        //show();
        win = getWin();
        i = (i + 1) % n;
    }

    cout << (win + 1) << endl;
    return 0;
}
