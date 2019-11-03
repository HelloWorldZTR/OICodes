#include<iostream>
using namespace std;
int main(){
	int a[13];
	int save=0;
	int now=0;
	for(int i=0;i<12;i++){
		cin>>a[i];
	}
	for(int i=0;i<12;i++){
		now+=300;
		if(now-a[i]>=100){
			int l=(now-a[i])/100;
			now-=100*l;
			save+=100*l;
		}else if(now-a[i]<0){
			cout<<"-"<<i+1<<endl;
			return 0;
		}
		now-=a[i];
	}
	cout<<now+1.2*save<<endl;
	return 0;
}
