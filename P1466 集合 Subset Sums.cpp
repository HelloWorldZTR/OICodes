#include<iostream> 
/*
这是什么鬼？？？？？
快看题解... 
::
其实我们可以把两个集合看作取不取这个数，那么这道题就变成了0-1背包问题，
设f[i][j]为前i个数中让和为j的方案个数，可以发现方案数=不取i的方案数+取
i的方案数，前提是能够取i,即j > i,注意：如果选了一个数，那么方案数是不
变的，所以状态转移方程为f[i][j] = f[i-1][j] + f[i-1][j - i] (j > i).
然后发现方案数如果位置不同那么还是算同一个方案，那么问题就是求用n个数
凑num/2的方案数(num是和)，当然，如果num为奇数则无解.				PS::(其实就是凑sum一半的不同方案数)
*/ 
using namespace std;

int dp[40][2233];

int main() {
	int n, sum = 0;
	cin>>n;

	sum = (n*(n+1)) / 2;
	
	if(sum%2) {
		cout<<0<<endl;
		return 0;
	} 
	dp[1][0] = 1;
	dp[1][1] = 1;/*相当于一个出口？？*/
	for(int i=2; i<=n; i++) {
		for(int j=sum; j>=0; j--) {
			if(j>i) {
				dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
				/*不选 + 选*/
			}
			else {
				dp[i][j] = dp[i-1][j];
				/*不选*/
			}
		}
	}
	/*for(int i=1; i<=n; i++){ 
		for(int j=0; j<=sum; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
		} */ 
	cout<<dp[n][sum/2]<<endl;//凑sum一半的方案数 
	return 0;
}
