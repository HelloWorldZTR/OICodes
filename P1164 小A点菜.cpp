#include<iostream>
using namespace std;

int n, m, w[110], f[110][10010];

int main() {
	cin>>n>>m;
	f[0][0] = 1;
	for(int i=1; i<=n; i++) {
		cin>>w[i];
		f[i][w[i]] = 1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=m; j>0; j--) {
			if(j>w[i]) {
				f[i][j] = f[i-1][j] + f[i-1][j-w[i]];//ѡor��ѡ 
			} else if(j==w[i]){
				f[i][j] = f[i-1][j] + 1;//��һ����ѡ�Ļ���ѡ����Ͱ�Ǯ�����ˣ����Է�����+1 
			} else {
				f[i][j] = f[i-1][j];//û��ѡ�Ͳ�ѡ�� 
			}
		}
	}
	cout<<f[n][m]<<endl;
	return 0; 
}
