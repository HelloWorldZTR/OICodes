#include<iostream>
using namespace std;
int main(){
	int n;
	int count = 0;
	int a[11];
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	cin>>n;
	n+=30;
	for(int i=0;i<10;i++){
		if(a[i]<=n)	count++;
	}
	cout<<count<<endl;
	return 0;
}
