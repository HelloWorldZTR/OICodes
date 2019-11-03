#include<iostream>

using namespace std;

int normal[13]={31,28,31,30,31,30,31,31,30,31,30,31}; 
int yun[13]={31,29,31,30,31,30,31,31,30,31,30,31}; 
int ans[8]={0,0,0,0,0,0,0,0};

bool isYun(int year){
	if(year%400==0 || (year%100!=0 && year%4 ==0))	return true;
	else return false;
} 

int main(){
	
	int n;
	
	cin>>n;
	
	for(int i=1900;i<1900+n;i++){
		int tmp=13;
		for(int j=0;j<12;j++){
			ans[tmp%7]++;
			if(isYun(i))	tmp+=yun[j];
			else tmp+=normal[j];
		}
	}

	for(int i=0;i<8;i++)	cout<<ans[i]<<endl;
	
	return 0; 
}
