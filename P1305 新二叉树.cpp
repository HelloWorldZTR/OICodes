#include<iostream>
using namespace std;
struct node{
    bool hasfather;
    char val;
    char lc;
    char rc;
    node() {hasfather = false;val='*';}
}nodes['a'+30];
void print(char c) {
    if(nodes[(int)c].val=='*')
        return;
    else {
        cout<<nodes[(int)c].val;
        print(nodes[(int)c].lc);
        print(nodes[(int)c].rc);
    }
}
int n;
int main() {
    cin>>n;
    int i;char tmp, tmp1, tmp2;
    for(i=0; i<n; i++) {
        cin>>tmp>>tmp1>>tmp2;
        nodes[(int)tmp].val = tmp;
        nodes[(int)tmp].lc  = tmp1;
        nodes[(int)tmp].rc  = tmp2;
        nodes[(int)tmp1].hasfather = true;
        nodes[(int)tmp2].hasfather = true;
    }
    for(tmp='a'; tmp<='z'; tmp++) {
        if(nodes[(int)tmp].val!='*' && !(nodes[(int)tmp].hasfather)) {
            print(tmp);
        }
    }
    return 0;
}

