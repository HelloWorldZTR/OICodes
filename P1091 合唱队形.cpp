#include<iostream> 
using namespace std;

int n, arr[233], dp[233];

int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	int count = 0;
	for(int i=1; i<n; i++) {
		int counta = 0, countb = 0;
		for(int j=0; j<i; j++) {
			/*在前半段搜索最长递增*/
			dp[j] = 1;
			for(int m=0; m<j; m++){
				/*在前面找到已存在的最长递增，+当前的数后再更新*/
				if(arr[m]<arr[j] && dp[m]+1>dp[j]){
					dp[j] = dp[m]+1;
				} 
			}
			if(dp[j]>counta)	counta = dp[j];
		}
		for(int j=n-1; j>=i; j--) {
			/*在后半段搜索最长递减*/
			dp[j] = 1;
			for(int m=n-1; m>j; m--){
				/*在前面找到已存在的最长递减，+当前的数后再更新*/
				if(arr[m]<arr[j] && dp[m]+1>dp[j]){
					dp[j] = dp[m]+1;
				} 
			}
			if(dp[j]>countb)	countb = dp[j];
		}
		/*更新最大的队列长度*/
		count = max(count, counta+countb);
		cout<<"count" <<count<<endl;
	}
	/*最少出队人数*/
	int ans = n - count; 
	cout<<ans<<endl;
	return 0;
}
