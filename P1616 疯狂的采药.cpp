#include<iostream> 
using namespace std;
/*ÍêÈ«±³°ü*/
const int maxt = 233333;

int t, m, f[maxt];

int main() {
	cin>>t>>m;
	int w, v;
	for(int i=1; i<=m; i++){
		cin>>w>>v;
		for(int j=w; j<=t; j++){
			f[j] = max(f[j], f[j-w]+v);
		}
	}
	cout<<f[t]<<endl;
	return 0; 
}
