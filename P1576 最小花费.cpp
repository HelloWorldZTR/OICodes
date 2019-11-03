#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
/*谁也别想让我做int 和 double的转换
*我快烦死了 
*dijkstra最长路 
*/
const int MAXN = 2001;

double g[MAXN][MAXN], dis[MAXN];
int n, m, s, end, done[MAXN];


void debug(){
	for(int i=1; i<=n; i++) {
		cout<<dis[i]<<" ";
	}
	cout<<endl;
}
void dijkstra(int s) {
	for(int i=1; i<=n; i++) {
		dis[i] = g[s][i];
	}
	dis[s] = 1;
	done[s] = 1;
	double minn = 0;
	int v = -1;
	for(int i=1; i<=n-1; i++) {
//		debug();
//	for(int i=1; i<=n; i++) 
//		cout<<done[i]<<" ";
//	cout<<endl;
		minn = 0.0;
		for(int j=1; j<=n; j++) {
			if(done[j]==0&&minn<dis[j]) {
				minn = dis[j];
				v = j;
			}
		}
//		cout<<"V "<<v<<endl;
		done[v] = 1;
		if(v==end)
			break;
		for(int j=1; j<=n; j++) {
			if(done[j]!=1){ 
				if(dis[v]*g[v][j]>dis[j]) {
					dis[j]=dis[v]*g[v][j];
				}
			} 
		}
		
	}
}



int main() {
	cin>>n>>m;
	int x, y;
	double z;
	for(int i=0; i<m; i++) {
		cin>>x>>y>>z;
		g[x][y] = g[y][x] =  (100- (double) z )/ 100.0;
	}
	cin>>s>>end;
	dijkstra(s);
//	debug();
	double minCost = dis[end];
	double ans = 100.0 / minCost;
	//cout<<minCost<<endl; 
	printf("%.8f", ans);
	return 0;
}

