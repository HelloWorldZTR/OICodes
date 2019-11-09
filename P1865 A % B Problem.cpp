#include<iostream> 
#include<cstring>

using namespace std;

const int maxn = 1000000;
const int maxprime = 1e6;

bool isPrime[maxn];
int d[maxn];
int prime[maxprime], n, m, t;

int lowbit(int x) {
	return x&(-x);
}

void update(int x, int v) {
	while(x<=m) {
		d[x]+=v;
		x+=lowbit(x);
	}
}

int query(int x) {
	register int sum = 0;
	while(x) {
		sum+=d[x];
		x-=lowbit(x);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for(int i=2; i<=m; i++) {
		if(isPrime[i]) {
			prime[++prime[0]] = i;
			update(i, 1);
		}
		for(int j=1; j<=prime[0] && i*prime[j]<=m; j++) {
			//if(isPrime[i*prime[j]])	update(i*prime[j], -1);
			isPrime[i*prime[j]] = false;
			if(i%prime[j]==0)	break;
		}
	}
	int l, r;
	for(int i=0; i<n; i++) {
		cin>>l>>r;
		if(l<1||l>m) {
			cout<<"Crossing the line"<<endl;
			continue;
		}	
		if(r<1||r>m) {
			cout<<"Crossing the line"<<endl;
			continue;
		}	
		cout<<query(r)-query(l-1)<<endl;
	}
	return 0;
}
