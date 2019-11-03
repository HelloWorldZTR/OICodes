#include<iostream>
using namespace std;
int main(){
	int maxDay,max=0;
	int i[8];
	for(int m=0;m<7;m++){
		int a,b;
		cin>>a>>b;
		i[m]=a+b;
	}
	for(int m=0;m<7;m++){
		if(i[m]>8){
			if(max<i[m]){
				max=i[m];
				maxDay=m+1;
			}
		}
	}
	if(max==0)	cout<<"0"<<endl;
	else cout<<maxDay<<endl;
	return 0;
}
