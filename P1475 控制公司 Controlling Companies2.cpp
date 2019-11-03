#include<iostream>
#include<cstring>
using namespace std;
int co[101][101], n, l, tot[101], ct;
bool vis[101];

void solve(int i) {
	if(ct++>100)
		return;
	for(int j=1; j<=l; j++) {
		tot[j] += co[i][j];
		if(co[i][j]>50&&!vis[j]) {
			vis[j] = true;
			solve(j);
		}
	}
}

int main() {
	cin>>n;
	int temp, temp2, v;
	for(int i=0; i<n; i++) {
		cin>>temp>>temp2>>v;
		co[temp][temp2] += v;
		l = max(l, temp);
		l = max(l, temp2);
	}
	for(int i=1; i<=l; i++) {
		memset(tot, 0, sizeof(tot));
		memset(vis, 0, sizeof(vis));
		ct=0;
		solve(i);
		for(int j=1; j<=l; j++) {
			if(i==79||i==34)
			cout<<tot[j]<<"\t";
			//if(tot[j]>50&&i!=j)
			//cout<<i<<" "<<j<<endl;
		}
		cout<<endl;
	}
	return 0;
}

