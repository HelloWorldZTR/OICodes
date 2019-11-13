#include<iostream>
#include<cstring> 

using namespace std;

const int maxn = 210;
const int INF  = 1077952576;
int n, nums[maxn], a, b, ans[maxn];
/**
*	init the array
*/
void init() {
	memset(ans, INF, sizeof ans);
	return;
}
/**
* search from *now*
*/
void search(int now, int times) {
	int &p = ans[now];
	if(p > times) {
		p = times;
	} else {
		return;
	}
	if(now + nums[now] <= n) {
		search(now+nums[now], times+1);
	}
	if(now - nums[now] >= 1 && now - nums[now] != a) {
		search(now-nums[now], times+1);
	}
	return;
}
int main() {
	cin>>n>>a>>b;
	int i;
	for(i=1; i<=n; i++) {
		cin>>nums[i];
	}
	init();
	search(a, 0);
	//for(i=1; i<=n; i++) {
	//	cout<<ans[i]<< " ";
	//}cout<<endl;
	if(ans[b]==INF) {
		cout<<-1<<endl;
	}else {
		cout<<ans[b]<<endl;
	}
	return 0;
}
