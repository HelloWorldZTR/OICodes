#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int father[maxn];

struct Edge{
    int from;
    int to;
    int dis;
    int type;
    /*1:I级道路， 2：II级道路， -1：当前方案准备打印的*/
};
Edge edges[maxn];

bool cmp(Edge a, Edge b) {
    return a.dis<b.dis;
}

void init() {
    memset(father, -1, sizeof(father));
}

int findRoot(int x) {
    if(father[x]!=-1) {
        return father[x] = findRoot(father[x]);
    }
    return x;
}

/*0:Fail 1:Success*/
int union_(int x, int y) {
    int xRoot = findRoot(x);
    int yRoot = findRoot(y);
    if(xRoot==yRoot) {
        return 0;
    }
    father[xRoot] = yRoot;
    return 1;
}

set<pair<int, int> > ans;
/*第t对， 第p级*/
int main() {
    int n, k, m;
    cin>>n>>k>>m;
    int a, b, I, II;
    int cnt = 0;
    for(int i=0; i<m-1; i++) {
        cin>>a>>b>>I>>II;
        edges[cnt] = ((Edge){a, b, I, 1});
        edges[cnt+1] = ((Edge){a, b, II, 2});
        cnt+=2;
    }
    sort(edges, edges+cnt, cmp);
    init();
    int cntOfI = 0, maxAns = 0;
    for(int i=0; i<cnt; i++) {
        /*循环找出前k个I级道路*/
        if(cntOfI>=k) {
            break;
        }
        Edge& now = edges[i];
        if(now.type==1) {
            if(union_(now.from, now.to) == 1) {
                cntOfI++;
                maxAns = max(maxAns, now.dis);
                /*答案：因为分开放了，cnt是m的两倍，所以
                 *求原来的对数应+1/2
                 * */
                ans.insert(make_pair((i+1)/2+1, now.type));
            }
        }
    }
    int tot = cntOfI;
    for(int i=0; i<cnt; i++) {
        /*循环找出剩下k~(n-1)个道路*/
        if(tot>=n-1) {
            break;
        }
        Edge& now = edges[i];
        if(union_(now.from, now.to)==1) {
            tot++;
            maxAns = max(maxAns, now.dis);
//            ans.insert(make_pair(i+1, now.type));
           /*答案：因为分开放了，cnt是m的两倍，所以
            *求原来的对数应+1/2
            * */
            ans.insert(make_pair((i+1)/2+1, now.type));
        }
    }
    cout<<maxAns<<endl;
    for(set<pair<int, int> >::iterator it = ans.begin(); it!=ans.end(); it++) {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    return 0;
}
