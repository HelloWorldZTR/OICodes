#include<iostream>
#include<cmath>
#include<cstring>
/*����dp�ɻ���*/
using namespace std;
const int maxx = 210;
long long f[maxx];

int main() {
	memset(f, 20, sizeof(f));
	f[0] = 0;
	int n, m;
	cin>>n>>m;
	int x, y;
	for(int i=0; i<m; i++) {//ȡǰi�� 
		cin>>x>>y;
		for(int j=n; j>=1; j--)  {//���� ��i������ ѡK�� ���ܴﵽ��Сֵ 
			for(int k=j; k>=0; k--) {
				f[j] = min(f[j], f[j-k]+x*(long long)pow(k,y));
			}
		}
	} 
	cout<<f[n]<<endl;
	return 0;
}
