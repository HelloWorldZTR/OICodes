#include<iostream> 
using namespace std;
/*最小01背包求剩余*/
const int MAXK = 10001;
int v, n, c, f[20010], ans = 233333;

int main() {
	cin>>v>>n>>c;
	for(int i=1; i<=v+MAXK; i++)
		f[i] = 1e9;//求最小，设最大 
	int k, m;
	for(int i=1; i<=n; i++){
		cin>>k>>m;
		for(int j=v+MAXK; j>=k; j--){
			f[j] = min(f[j], f[j-k]+m);
		}
	}
	for(int i=v;i<=v+MAXK;i++)//这个循环可以放在上面循环里 
		ans = min(ans, f[i]);//在所有符合条件的范围内找最小 
	ans = c - ans; 
	if(ans < 0)
		cout<<"Impossible";
	else
		cout<<ans;
	cout<<endl;
	return 0;
}
