#include<iostream>
using namespace std;
int main(){
	int n;
	double s,k;
	n=1;s=0.0;
	cin>>k;
	while(s<=k){
		s+=1.0/n;
		n++;
		//cout<<n<<"	"<<s<<endl;
	}
	cout<<n-1<<endl;
	return 0;
}
