#include<bits/stdc++.h>
using namespace std;

const int MAX_NODE = 110;
const int MAX_V    = 10000;

struct s{
	int x;
	int y;
	int z;
}con[MAX_V];

int father[MAX_NODE];

bool cmp(s a, s b) {
	return a.z<b.z;
}

int find_root(int x) {
	if(father[x]!=-1) {
		return father[x] = find_root(father[x]);
	}
	return x;
}

/*1::ok  0::fail*/
int union_(int a, int b) {
	int aroot = find_root(a);
	int broot = find_root(b);
	if(aroot!=broot) {
		father[aroot] = broot;
		return 1;
	}
	return 0;
}

int main() {
	int n, ans = 0, tmp2, tmp=0;
	memset(father, -1, sizeof(father));
	cin>>n;
	for(int i=0; i<n; i++){ 
		for(int j=0; j<n; j++){ 
			cin>>tmp2;
			if(j>i) {
				con[tmp].x = i;
				con[tmp].y = j;
				con[tmp].z = tmp2;
				tmp++;
			}
		} 
	} 
	sort(con, con+tmp, cmp);
	for(int i=0; i<tmp; i++) {
		if(union_(con[i].x, con[i].y)) {
			ans += con[i].z;
		}
	}
	cout<<ans<<endl;
	return 0;
}

