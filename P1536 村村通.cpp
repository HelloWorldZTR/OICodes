#include<iostream>
#include<cstring>

using namespace std;

const int maxn = 1010;

int father[maxn];

void init() {
    memset(father, -1, sizeof(father));
}

int  findRoot(int x) {
    if(father[x]!=-1) {
        return father[x] = findRoot(father[x]);
    }
    return x;
}

void union_(int x, int y) {
    int xRoot = findRoot(x);
    int yRoot = findRoot(y);
    if(xRoot!=yRoot) {
        father[xRoot] = yRoot;
    }
}

int main() {
    int n, m;
    int a, b;
    int ansCount;
    while(cin>>n,n) {
        init();
        cin>>m;
        /*Union two villages*/
        for(int i=0; i<m; i++) {
            cin>>a>>b;
            union_(a, b);
        }
        /*Count the villages that connected to no other villages*/
        ansCount = 0;
        for(int i=1; i<=n; i++) {
            if(father[i] == -1) {
                ansCount++;
            }
        }
        /*Print the answer*/
        cout<<ansCount-1<<endl;
    }
    return 0;
}
