#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 1005;

int father[maxn];
vector<int > enemys[maxn];

void init() {
    memset(father, -1, sizeof(father));
}

int findRoot(int x) {
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
    cin>>n>>m;
    init();
    char relationship;int p, q;
    for(int i=0; i<m; i++) {
        cin>>relationship>>p>>q;
        if(relationship == 'E') {
            enemys[p].push_back(q);
            enemys[q].push_back(p);
            for(int j=0; j<enemys[p].size(); j++) {
                union_(q, enemys[p][j]);
            }
            for(int j=0; j<enemys[q].size(); j++) {
                union_(p, enemys[q][j]);
            }
        }
        else {
            union_(p, q);
        }
    }
    int ansCount = 0;
    for(int i=1; i<=n; i++) {
        if(father[i]==-1) {
            ansCount++;
        }
    }
    cout<<ansCount<<endl;
    return 0;
}
