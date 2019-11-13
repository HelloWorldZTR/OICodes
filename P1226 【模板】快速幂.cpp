#include<iostream>
using namespace std;
typedef long long ll;
ll getAns(ll b, ll p, ll k) {
	ll temp = 1;
	while(p>0) {
		if(p&1==1) {
			temp = temp * b % k;
		}
		b = b * b % k;
		p = p>>1;
	}
	return temp;
}
int main() {
	ll b, p, k;
	cin>>b>>p>>k;
	ll s = getAns(b, p, k);
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<s<<endl;
	return 0;
}
