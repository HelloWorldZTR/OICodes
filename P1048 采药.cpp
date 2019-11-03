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
	for(int i=1; i<=m; i++) {/*第i种草药*/
		for(int j=t; j>0; j--) {/*背包容量j*/ 
			if(w[i]<=j) {/*能装下*/
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+v[i]);
			}
			else {/*装不下*/
				f[i][j] = f[i-1][j];
			}
		} 
	}
	cout<<f[m][t]<<endl;
	return 0;
}
