#include<iostream>
using namespace std;

int a[2100] ,b[2100];
char ans[2100];
int len=0;
int conv(const char c){
	if(c<='9'&&c>='0')	return c-'0';
	if(c<='Z'&&c>='A')	return c-'A'+10;
	return 1110;
}
void calc(int mod,int len1,int len2){
	int jinwei=0;
	for(int i=0;i<max(len1,len2);i++,len++){
		int tmp=a[i]+b[i]+jinwei;
		if(tmp>=mod){
			if(tmp-mod>9)	ans[i]='A'+tmp-mod-10;
			else	ans[i]=tmp-mod+'0';
			jinwei=1;
		}
		else{
			if(tmp>9)	ans[i]='A'+tmp-10;
			else	ans[i]=tmp+'0';
			jinwei=0;
		}
	}
	if(jinwei!=0)	ans[len]=jinwei+'0';
	else len--;
	return;
}
int main(){
	int k;
	string s1,s2;
	cin>>k;
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++)	a[s1.length)-1-i]=conv(s1[i]);
	for(int i=0;i<s2.length();i++)	b[s2.length()-1-i]=conv(s2[i]);	
	calc(k,s1.length(),s2.length());
	for(int i=len;i>=0;i--)	cout<<ans[i];
	cout<<endl;
	return 0;
}
