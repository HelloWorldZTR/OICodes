#include<iostream>
using namespace std;
int main(){
	string a;
	cin>>a;
	int num=0,index=1;
	for(int i=0;i<a.length()-1;i++){
		if(a[i]!='-'&&index<=9){
			num+=index*(a[i]-'0');
			index++;
		}
	}
	int check=num%11;
	int check1=a[a.length()-1]=='X'?10:(a[(a.length()-1)]-'0');
	if(check1==check)	cout<<"Right"<<endl;
	else {
		for(int i=0;i<a.length()-1;i++){
			cout<<a[i];
		}
		if(check==10)	cout<<"X"<<endl;
		else cout<<check<<endl;
	}
	return 0;
}
