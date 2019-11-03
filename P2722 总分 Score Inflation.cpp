#include<iostream>
using namespace std;
int f[10010], m, n, w, c;
int main() {
	cin>>m>>n;
	for(int i=1; i<=n; i++) {
		cin>>w>>c;
		for(int j=c; j<=m; j++) {
			f[j] = max(f[j], f[j-c]+w);
		}
	}
	cout<<f[m]<<endl;
	return 0;
}

