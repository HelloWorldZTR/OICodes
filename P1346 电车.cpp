#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int INF  = 101;//这个命名鬼畜了，但因为只有0，1所以101就是无穷大 

struct Edge{
	int from;
	int to;
	int dis;
};
struct Node{
	int u;
	int v;
	friend bool operator <(const Node a, const Node b) {
		return a.v>b.v;
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
void dijkstra(int s) {
	memset(dis, INF, sizeof(dis));
	dis[s] = 0;
	pq.push((Node){
		s,
		0
	});
	while(!pq.empty()) {
		Node temp = pq.top();
		pq.pop();
		int u = temp.u;
		if(temp.v!=dis[u])
			continue;
		for(int i=0; i<head[u].size(); i++) {
			Edge& a = edges[head[u][i]];
			if(dis[a.to]>dis[a.from]+a.dis) {
				dis[a.to] = dis[a.from]+a.dis;
				pq.push((Node){
					a.to,
					dis[a.to]
				});
			} 
		}
	}
}

int main() {
	edges.clear(); 
	int n, a, b;
	cin>>n>>a>>b;
	for(int i=1; i<=n; i++) {
		head[i].clear();
	}
	int ki, _1st, temp;
	for(int i=1; i<=n; i++) {
		cin>>ki;
		/*if(ki!=0) { //什么沙雕写法 
			cin>>_1st;
			add(i, _1st, 0);
			for(int j=1; j<ki; j++) {
				cin>>temp;
				add(i, temp, 1);
			}
		} */
		for(int j=1; j<=ki; j++)  {
			cin>>temp;
			if(j==1) {
				add(i, temp, 0);
			}
			else {
				add(i, temp, 1);
			}
		}
	}
	dijkstra(a);
	if(dis[b]>=INF) {
		cout<<-1;
	}
	else {
		cout<<dis[b];
	}
	cout<<endl;
	return 0;
}

