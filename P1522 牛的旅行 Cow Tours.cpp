#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double INF = 1000000.0;

struct point{
	int x;
	int y;
} m[151];

double dis[151][151], mdis[151], ans1, ans2 = INF, ans;
int n;

double dist(point a, point b) {
	return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>m[i].x>>m[i].y;
	}
	char temp;
	for(int i=1; i<=n; i++) {//输入 
		for(int j=1; j<=n; j++) {
			cin>>temp;
			if(temp=='1') {
				dis[i][j] = dist(m[i], m[j]);//连通 
			}else{
				dis[i][j] = INF;//不联通 
			}
		}
	}
	for(int k=1; k<=n; k++) {//最短路算法 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i!=j && i!=k && j!=k) {
					if(dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {//求i为开始的最长路 
		for(int j=1; j<=n; j++) {
			if(dis[i][j]<INF){ 
				if(dis[i][j] > mdis[i]) {
					mdis[i] = dis[i][j];
					ans1 = max(ans1, mdis[i]);//最大直径（原） 
				}
			} 
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(dis[i][j]==INF && i!=j) {// 取两个不连通的不同点 
				double tot = mdis[i] + dist(m[i], m[j]) + mdis[j];//最大直径（合并后） 
				ans2 = min(ans2, tot);// 最小的合并后最大直径 
			}
		}
	}
	//cout<<ans1<<" "<<ans2<<endl;
	ans = max(ans1, ans2);//看是否需要合并（原图可能直径比合并后的大） 
	//cout<<ans<<endl;
	printf("%.6f", ans);//输出前6位 
	return 0;
}
