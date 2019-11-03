#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXM = 100001;

struct v{
	int x, y, z;
	friend bool operator <(v a, v b){
		return a.z < b.z;
	}
};

int n, m, ans = -1, father[MAXN], totcount;
v g[MAXM];

int find_root(int x) {
	if(father[x]!=-1) {
		return father[x] = find_root(father[x]);
	}
	return x;
}

int union_(v a) {
	int x_root = find_root(a.x);
	int y_root = find_root(a.y);
	if(x_root!=y_root) {
		father[x_root] = y_root;
		return 1;
	}
	return 0;
}

int main() {
	memset(father, -1, sizeof(father));
	cin>>n>>m;
	if(m < n - 1) {//至少有n-1条边才能联通 
		cout<<-1<<endl;
		return 0;
	}
	else{
		for(int i=0; i<m; i++) {
			cin>>g[i].x>>g[i].y>>g[i].z;
		}
		sort(g, g+m);//重载了小于号 
		for(int i=0; i<m; i++) {
			if(union_(g[i])) {//判断 
				ans = max(ans, g[i].z);//答案 
				totcount++;
			}
			if(totcount>n-1) {//提前跳出 
				break;
			}
		}
		if(totcount<n-1) {//同理，不能联通 
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
	return 0;
}



