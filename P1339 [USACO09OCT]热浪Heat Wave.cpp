#include<bits/stdc++.h>
using namespace std;
/*dijsktraÂãÌâ*/
const int maxn = 2501;
const int INF  = 1e6;
struct Edge{
	int from;
	int to;
	int dis;
};

struct Node{
	int v;
	int u;
	friend bool operator<(const Node a, const Node b) {
		return a.v>b.v;//Ð¡¸ú¶Ñ 
	}
};
vector<Edge> edges;
vector<int> head[maxn];
int dis[maxn];

void add(int from, int to, int dis) {
	Edge temp = {from, to, dis};
	edges.push_back(temp);
	head[from].push_back(edges.size()-1);
}

priority_queue<Node> pq;
void dijsktra(int s) {
	memset(dis, INF, sizeof(dis));
	dis[s] = 0;
	pq.push((Node){
		0,
		s
	});
	while(!pq.empty()) {
		Node temp = pq.top();
		pq.pop();
		int u = temp.u;
		int v = temp.v;
		if(v!=dis[u])
			continue;
		//done[u] = true;
		for(int i=0; i<head[u].size(); i++) {
			Edge& now = edges[head[u][i]] ;
			if(dis[now.to]>dis[now.from]+now.dis) {
				dis[now.to]=dis[now.from]+now.dis;
				pq.push((Node){
					dis[now.to],
					now.to
				});
			}
		}
	}
	
}
int main() {
	edges.clear();
	//head.clear();
	int t, c, ts, te;
	cin>>t>>c>>ts>>te;
	int rs, re, ci;
	for(int i=0; i<c; i++) {
		cin>>rs>>re>>ci;
		add(rs, re, ci);
		add(re, rs, ci);
	}
	dijsktra(ts);
	cout<<dis[te]<<endl;
	return 0;
}

