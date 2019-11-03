#include<iostream>
using namespace std;

const int maxn = 10010;

int v, n;
long long f[maxn];//long long

int main() {
	cin>>v>>n;
	int tmp;
	f[0] = 1;
	for(int i=1; i<=v; i++) {
		cin>>tmp;
		for(int j=tmp; j<=n; j++) {
			f[j] += f[j-tmp];
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
