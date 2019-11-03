#include<iostream>
using namespace std;

int ans[8]={0};

bool isLeap(int year) {
	if(year%400==0|| ( year % 100!= 0 && year % 4 == 0))
		return true;
	else return false;
}

int main(){
	int n;
	cin>>n;
	int now=13;
	for(int i=1900;i<=1900+n-1;i++){
		//now=13;
		for(int j=1;j<=12;j++){
			ans[now%7]++;
			if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)	now+=31;
			if(j==4||j==6||j==9||j==11)	now+=30;
			if(j==2){
				if(isLeap(i))	now+=29;
				else now+=28;
			}
		}
	}
	cout<<ans[6]<<" ";
	for(int i=0;i<6;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
