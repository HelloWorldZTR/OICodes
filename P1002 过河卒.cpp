#include<iostream>
/*
	Name: P1002 ������
	Copyright: none 
	Author: HelloWorldZTR
	Date: 02/08/19 17:48
	Description: AC
	��ô�򵥵��⻹�ύ�����Σ�ԭ�����£�
	1.int ���� ����long long ��L14�� 
	2. �жϵ�ʱ������=0�������L23~L30�� 
*/
using namespace std;

long long f[22][33];
int g[22][33];

int main() {
	
	int n, m, x, y;
	cin>>n>>m>>x>>y;
	/*�����ϰ�����Ϣ �� 1=������ 0=����*/ 
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
			if(i!=0||j!=0){ /*��ֹi=0,j=0ʱ������*/ 
				if((!g[i][j] )) {   /*������ʱ������=����+����*/ 
					if(i==0 && j>0)
						f[i][j] = f[i][j-1];//�ڱ��ϾͿ��ű��� 
					else if(j==0 && i>0)
						f[i][j] = f[i-1][j];//�ڱ��ϾͿ��ű���
					else 
						f[i][j] = f[i-1][j] + f[i][j-1];/*����=����+����*/
				}
				else {/*������ʱ�� ����*/ 
					f[i][j] = 0;
				}
			} 
		} 
	}
	
	cout<<f[n][m]<<endl;
	return 0;
}
