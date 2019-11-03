#include<iostream>
/*
	Name: P1002 过河卒
	Copyright: none 
	Author: HelloWorldZTR
	Date: 02/08/19 17:48
	Description: AC
	这么简单的题还提交了三次，原因如下：
	1.int 爆了 改用long long （L14） 
	2. 判断的时候少了=0的情况（L23~L30） 
*/
using namespace std;

long long f[22][33];
int g[22][33];

int main() {
	
	int n, m, x, y;
	cin>>n>>m>>x>>y;
	/*建立障碍点信息 ： 1=不能走 0=能走*/ 
	g[x][y] = 1;
	if(x+1<=n && y+2<=m)	g[x+1][y+2] = 1;
	if(x+2<=n && y+1<=m)	g[x+2][y+1] = 1;
	if(x+1<=n && y-2>=0)	g[x+1][y-2] = 1;
	if(x+2<=n && y-1>=0)	g[x+2][y-1] = 1;
	if(x-1>=0 && y+2<=m)	g[x-1][y+2] = 1;
	if(x-2>=0 && y+1<=m)	g[x-2][y+1] = 1;
	if(x-1>=0 && y-2>=0)	g[x-1][y-2] = 1;
	if(x-2>=0 && y-1>=0)	g[x-2][y-1] = 1;
	
	f[0][0] = 1;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			if(i!=0||j!=0){ /*防止i=0,j=0时被清了*/ 
				if((!g[i][j] )) {   /*可以走时，数量=上面+左面*/ 
					if(i==0 && j>0)
						f[i][j] = f[i][j-1];//在边上就靠着边走 
					else if(j==0 && i>0)
						f[i][j] = f[i-1][j];//在边上就靠着边走
					else 
						f[i][j] = f[i-1][j] + f[i][j-1];/*数量=上面+左面*/
				}
				else {/*不能走时， 清零*/ 
					f[i][j] = 0;
				}
			} 
		} 
	}
	
	cout<<f[n][m]<<endl;
	return 0;
}
