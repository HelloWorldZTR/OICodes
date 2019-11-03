#include<bits/stdc++.h>
using namespace std;

const int maxn = 2005;
const int maxm = 2010000;
const int SUCCESS = 1;
const int FAIL = 0;

struct Point{
    int x;
    int y;
};
Point farm[maxn];

struct Edge{
    int from;
    int to;
    int dis;
};
Edge edges[maxm];

bool cmp(Edge a, Edge b) {
    return a.dis<b.dis;
}

int father[maxn];

void init() {
    memset(father, -1, sizeof(father));
}

int findRoot(int x) {
    if(father[x]!=-1) {
        return father[x] = findRoot(father[x]);
    }
    return x;
}

/*Return SUCCESS(aka.1) or FAIL(aka.0)*/
int union_(int x, int y, int dis, int c) {
    int xRoot = findRoot(x);
    int yRoot = findRoot(y);
    if(xRoot == yRoot) {
        return FAIL;
    }
    if(dis<c) {
        return FAIL;
    }
    father[xRoot] = yRoot;
    return SUCCESS;
}

int getDis(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main() {
    int n, c;
    cin>>n>>c;
    for(int i=0; i<n; i++) {
        cin>>farm[i].x>>farm[i].y;
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            edges[cnt++] = (Edge){i, j, getDis(farm[i], farm[j])};
        }
    }
    init();
    sort(edges, edges+cnt, cmp);
    int tot = 0, ans = 0;
    for(int i=0; i<cnt; i++) {
        if(tot>=n-1) {
            break;
        }
        if(union_(edges[i].from, edges[i].to, edges[i].dis, c)==SUCCESS ) {
            tot++;
            ans += edges[i].dis;
        }
    }
    if(tot!=n-1)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
