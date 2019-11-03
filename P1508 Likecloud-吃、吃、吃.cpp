#include<iostream> 
using namespace std;

const int maxm = 210;
const int maxn = 210;

int m, n, f[maxm][maxn];

int max3(int a, int b, int c) {
	return max(max(a, b), c);
}

int main() {
	cin>>m>>n;
	int tmp;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			cin>>tmp;
			f[i][j] = max3(f[i-1][j-1], f[i-1][j], f[i-1][j+1]) + tmp;
			/*他吃东西有一个习惯——只吃自己前方或左前方或右前方的盘中的食物*/
		}
	}
	cout<<max3(f[m][n/2], f[m][n/2+1], f[m][n/2+2])<<endl;/*瞎*/
	return 0;
}
