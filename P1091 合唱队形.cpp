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
			/*��ǰ������������*/
			dp[j] = 1;
			for(int m=0; m<j; m++){
				/*��ǰ���ҵ��Ѵ��ڵ��������+��ǰ�������ٸ���*/
				if(arr[m]<arr[j] && dp[m]+1>dp[j]){
					dp[j] = dp[m]+1;
				} 
			}
			if(dp[j]>counta)	counta = dp[j];
		}
		for(int j=n-1; j>=i; j--) {
			/*�ں���������ݼ�*/
			dp[j] = 1;
			for(int m=n-1; m>j; m--){
				/*��ǰ���ҵ��Ѵ��ڵ���ݼ���+��ǰ�������ٸ���*/
				if(arr[m]<arr[j] && dp[m]+1>dp[j]){
					dp[j] = dp[m]+1;
				} 
			}
			if(dp[j]>countb)	countb = dp[j];
		}
		/*�������Ķ��г���*/
		count = max(count, counta+countb);
		cout<<"count" <<count<<endl;
	}
	/*���ٳ�������*/
	int ans = n - count; 
	cout<<ans<<endl;
	return 0;
}
