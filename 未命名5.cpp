#include<iostream>
using namespace std;
int main(){
	int n;
	int a[4],b[4];
	int c[4];
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<3;i++){
		if(n%a[i]==0)	c[i]=n/a[i]*b[i];
		else	c[i]=(n/a[i]+1)*b[i];
	}
	int min=99999;
	for(int i=0;i<3;i++){
		if(c[i]<min)	min=c[i];
	}
	cout<<min<<endl;
}
