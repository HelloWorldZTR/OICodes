#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
const int INF  = 1e6+1000;
const int MOD  = 100003;
vector<int> edges[maxn];
int dis[maxn], times[maxn], vis[maxn];
queue<int> Q;

void dijkspfa(int s) {
    memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    times[s] = 1;
    vis[s] = 1;
    Q.push(s);
    while(!Q.empty()) {
        int& now = Q.front();Q.pop();
       /*这一句不能写，根dij不一样*/
       // if(vis[now]==1) {
       //     continue;
       // }
       // vis[now] = 1;
       //
       // 循环：当前边（now, edges[now][i]）now 试图松弛 dis[edges[...]]
        for(int i=0; i<edges[now].size(); i++) {
            if(dis[edges[now][i]]==dis[now]+1) {
                times[edges[now][i]] += times[now];
                /*前辈经验：每步取模*/
                times[edges[now][i]] = times[edges[now][i]] % MOD;
            }
            if(dis[edges[now][i]]>dis[now]+1) {
                dis[edges[now][i]] = dis[now] + 1;
                times[edges[now][i]] = times[now];
                /*spfa式入队方法*/
                if(!vis[edges[now][i]]) {
                    Q.push(edges[now][i]);
                    vis[edges[now][i]] = 1;
                }
            }
        }
    }
}

void addEdge(int from, int to) {
    /*无向无权图*/
    edges[from].push_back(to);
    edges[to].push_back(from);
}

int main() {
    int n, m;
    cin>>n>>m;
    int a, b;
    for(int i=0; i<m; i++) {
        cin>>a>>b;
        addEdge(a, b);
    }
    dijkspfa(1);
    for(int i=1; i<=n; i++) {
        cout<<times[i]<<endl;//智商下线：回车输出格式爆零
    }
    //cout<<endl;
    return 0;
}
