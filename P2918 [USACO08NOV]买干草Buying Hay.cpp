#include<iostream>
/*��ȫ��������min��*/ 
using namespace std;

const int maxh = 60000;//���鿪���˻����� 

int n, h, f[maxh], ans = 1e9+1;

int main() {
	//f[0]��0��ι���� F**(����������)
	for(int i=1; i<maxh; i++)	f[i] = 1e9;
	cin>>n>>h;
	int p, c;
	for(int i=1; i<=n; i++) {
		cin>>p>>c;
		for(int j=p; j<=h+5000; j++) {
			f[j] = min(f[j], f[j-p]+c);
			if(j>=h){
				ans = min(ans, f[j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
