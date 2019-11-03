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
	for(int i=1; i<=n; i++) {//���� 
		for(int j=1; j<=n; j++) {
			cin>>temp;
			if(temp=='1') {
				dis[i][j] = dist(m[i], m[j]);//��ͨ 
			}else{
				dis[i][j] = INF;//����ͨ 
			}
		}
	}
	for(int k=1; k<=n; k++) {//���·�㷨 
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
	for(int i=1; i<=n; i++) {//��iΪ��ʼ���· 
		for(int j=1; j<=n; j++) {
			if(dis[i][j]<INF){ 
				if(dis[i][j] > mdis[i]) {
					mdis[i] = dis[i][j];
					ans1 = max(ans1, mdis[i]);//���ֱ����ԭ�� 
				}
			} 
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(dis[i][j]==INF && i!=j) {// ȡ��������ͨ�Ĳ�ͬ�� 
				double tot = mdis[i] + dist(m[i], m[j]) + mdis[j];//���ֱ�����ϲ��� 
				ans2 = min(ans2, tot);// ��С�ĺϲ������ֱ�� 
			}
		}
	}
	//cout<<ans1<<" "<<ans2<<endl;
	ans = max(ans1, ans2);//���Ƿ���Ҫ�ϲ���ԭͼ����ֱ���Ⱥϲ���Ĵ� 
	//cout<<ans<<endl;
	printf("%.6f", ans);//���ǰ6λ 
	return 0;
}
