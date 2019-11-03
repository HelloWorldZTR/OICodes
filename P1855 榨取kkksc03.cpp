#include<iostream>
using namespace std;

const int maxt = 210;
const int maxm = 210;
int n, m, t, f[maxm][maxt], mi, ti, ans;

int main() {
	cin>>n>>m>>t;
	//f[0][0][0] = 1;
	for(int i=1; i<=n; i++){
		cin>>mi>>ti;
		for(int j=m; j>=mi; j--){
			for(int k=t; k>=ti; k--){
				f[j][k] = max(f[j-mi][k-ti]+1, f[j][k]);
				ans = max(ans, f[j][k]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
