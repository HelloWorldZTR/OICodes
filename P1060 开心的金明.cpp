#include<iostream>
/*
	Name: P1060 开心的金明
	Copyright: none 
	Author: HelloWorldZTR
	Date: 02/08/19 14:42
	Description: AC
*/

using namespace std;

const int MAXM = 25, MAXN = 30000;

int w[MAXM], v[MAXM], opt[MAXM+1][MAXN+1], m, n;
	/*v是价钱， w是 价钱*重要度 */
int main() {
	
	cin>>n>>m;
	
	int imp;
	for(int i=1; i<=m; i++) {
		cin>>v[i]>>imp;
		w[i] = v[i] * imp;
	}
	
	for(int i=1; i<=m; i++) {
		for(int j=n; j>0; j--) {
			if(v[i] <= j) {
				opt[i][j] = max(opt[i-1][j], opt[i-1][j-v[i]]+w[i]);
			}
			else {
				opt[i][j] = opt[i-1][j];
			}
		}
	} 
	cout<<opt[m][n]<<endl;
	return 0;
}
