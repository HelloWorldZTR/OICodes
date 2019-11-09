#include<iostream>
using namespace std;
const int maxn = 100000+100;
const int maxx = 100000+100;
int d[maxx], n, w, x[maxn], b[maxn];
int maxX = 0;
/*返回x去除二进制位最后一个1的值*/
int lowbit(int x) {
	return x&(-x);
}
/*在a(x) + v*/ 
void update(int x, int v) {
	while(x<=maxX) {
		d[x] += v;
		x += lowbit(x);
	}
}
/*返回a(1)+a(2)+...+a(x)*/ 
int query(int x) {
	register int res = 0;
	while(x) {
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>w;
	register int i;
	for(i=0; i<n; i++) {
		cin>>x[i]>>b[i];
		maxX = max(maxX, x[i]);
	}
	for(i=0; i<n; i++) {
		update(x[i], b[i]);
	}
	register int ans = 0;
	for(i=w; i<=maxX; i++) {
		ans = max(ans, query(i) - query(i-w));
	}
	cout<<ans<<endl;
} 
