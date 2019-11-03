#include<iostream>
#include<algorithm>
using namespace std;
int stall[250];
int breaks[55];

int main(){
	int m,s,c;
	cin>>m>>s>>c;
	
	int i;
	for(i = 0; i < c; i++)
		cin>>stall[i];
		
	sort(stall,stall+c);
	
	int len=0;
	for(int n = 1;n < c; n++){
		if(stall[n-1]+1 != stall[n])	breaks[len++] = stall[n] - stall[n-1]-1;//判断有没有断开的空当 
	} 
	
	if(len == 0){//没有的话，直接输出 尾-头 
		int start	= stall[0];
		int end 	= stall[c-1];
		cout<<end - start + 1 <<endl;
		return 0;
	}
	else sort(breaks, breaks+len); 
	
	int ans=s;
	for(int n=0;(n<m-1 && n<len);n++)
		ans = ans - breaks[len-n-1];//由大到小的前m个空当（不足时取len个） 
	if(stall[0]>1)		ans = ans-(stall[0]-1);		//头不算 
	if(stall[c-1]<s)	ans = ans-(s-stall[c-1]);	//尾不算 
	
	cout<<ans<<endl;
	
	return 0;
} 
