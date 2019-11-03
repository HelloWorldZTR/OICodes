#include<iostream> 
using namespace std;

const int maxn = 35;
const int maxv = 20005;

int w[maxn], v, n, opt[maxn][maxv];

int main() {
	cin>>v>>n;
	for(int i=1; i<=n; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=v; j>0; j--) {
			if(w[i]<=j){
				opt[i][j] = max(opt[i-1][j], opt[i-1][j-w[i]]+w[i]);
			}
			else {
				opt[i][j] = opt[i-1][j];
			}
		}
	}
	cout<<v-opt[n][v]<<endl;
	return 0;
}
