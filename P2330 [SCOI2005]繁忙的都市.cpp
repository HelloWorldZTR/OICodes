#include<bits/stdc++.h>
using namespace std;

const int MAXN = 310;

int  g[MAXN][MAXN], minlen[MAXN], mst[MAXN], ans = -1, helloworldztr;
int  n, m;


int main() {
	cin>>n>>m;
	int x, y, z;
	for(int i=1; i<=m; i++) {
		cin>>x>>y>>z;
		g[x][y] = z;
		g[y][x] = z;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j)
				g[i][j] = 0;
			else if(g[i][j] == 0)
				g[i][j] = 1e9;
		}
	}
	for(int i=1; i<=n; i++) {
		minlen[i] = g[i][1];
		mst[i] = 1;
	}
	mst[1] = -1;
	for(int i=1; i<n; i++) {
		int minn = 1e9, v = -1;
		for(int j=1; j<=n; j++) {
			if(mst[j]!=-1 && minlen[j]<minn) {
				v = j;
				minn = minlen[j];
			}
		}
		if(v!=-1) {
			mst[v] = -1;
			//ans += minlen[v];
			ans = max(ans, minn);
			helloworldztr++; 
			for(int j=1; j<=n; j++) {
				if(mst[j]!=-1 && g[j][v]<minlen[j]) {
					minlen[j] = g[j][v];
					mst[j] = v;
				}
			}
		}
	}
	cout<<helloworldztr<<" "<<ans<<endl;
	return 0;
}

