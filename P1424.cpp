#include<iostream>
using namespace std;
int main(){
	int today,n,mile=0;
	cin>>today>>n;
	for(int i=0;i<n;i++){
		if(today!=6&&today!=7)	mile+=250;
		++today;
		if(today==8)	today=1;
	}
	cout<<mile<<endl;
}
