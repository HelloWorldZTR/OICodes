#include<iostream>
using namespace std;
const int MAXM = 105;
const int MAXT = 1005;
int v[MAXM], w[MAXM],
    f[MAXM][MAXT];

int main(){
	int t, m;
	/*Input*/
	cin>>t>>m;
	for(int i=1; i<=m; i++) {
		cin>>w[i]>>v[i];
	}
	/*Find Answer*/
	for(int i=1; i<=m; i++) {/*��i�ֲ�ҩ*/
		for(int j=t; j>0; j--) {/*��������j*/ 
			if(w[i]<=j) {/*��װ��*/
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+v[i]);
			}
			else {/*װ����*/
				f[i][j] = f[i-1][j];
			}
		} 
	}
	cout<<f[m][t]<<endl;
	return 0;
}
