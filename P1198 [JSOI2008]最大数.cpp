#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int maxn = 200000 << 2;

LL tr[maxn];

void add(int now, int l, int r, int u, LL v) {
	if(l==r) {
		if(l==u) tr[now] = v;
		return;
	}
	int mid = (l+r)>>1;
	int lchild = now<<1;
	int rchild = (now<<1)+1;
	if(u>mid) {
		add(rchild, mid+1, r, u, v);
	}
	else {
		add(lchild, l, mid, u, v);
	}
	tr[now] = max(tr[lchild], tr[rchild]);
}

LL query(int now, int l, int r, int start, int end) {
	if(l>=start && r<=end)	return tr[now];
	int mid = (l+r)>>1;
	int lchild = now<<1;
	int rchild = (now<<1) + 1;
	if(start>mid) {
		return query(rchild, mid+1, r, start, end);
	}
	else {
		if(end>mid) {
			return max(query(lchild, l, mid, start, end), query(rchild, mid+1, r, start, end));
		}
		else {
			return query(lchild, l, mid, start, end);
		}
	}
}

int m;
LL d;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	add(1, 1, 1e5, 1, 96);
//	add(1, 1, 1e5, 2, 93);
//	cin >> m >> d;
//	tr[1] = Node(1, maxn-1, 0);
//	cout << query(1, 1, 1e5, 2, 2) <<endl;
//	cout << query(1, 1, 1e5, 1, 2) <<endl;
	cin >> m >> d;
	char option; int n;register int len = 1;LL t = 0;
	for(int i=0; i<m; i++) {
		cin >> option >> n;
		switch(option) {
			case 'Q': {
				t = query(1, 1, m, len-n, len);
				cout << t << endl;
				break;
			}
			case 'A': {
				add(1, 1, m, len++, (n+t)%d);
				break;
			}
			default: {
				break;
			}
		}
	}
	return 0;
}
