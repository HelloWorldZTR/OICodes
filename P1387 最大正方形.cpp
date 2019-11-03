#include<iostream> 
using namespace std;

const int maxn = 110;
const int maxm = 110;

int m, n, f[maxn][maxm], ans;

int min3(int a, int b, int c){
	return min(min(a, b), c);
}

int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>f[i][j];
			if(f[i][j]){
				f[i][j] = min3(f[i][j-1], f[i-1][j-1], f[i-1][j]) + 1;
				/*示例：： 
				0 0   1 1   1 1   1 1
				1 1   1 1   1 2   0 0
				0 0   1 1   1 2   0 0
				1 1   1 1   0 0   1 1
				^ ^当前的最大边长 
				|原数值 
				*/
				ans = max(ans, f[i][j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
