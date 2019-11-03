#include<iostream>
using namespace std;
int toInterge(char c){
	if((int)c>='A'&&(int)c<='Z')	return c-'A'+1;
	else return 0;
}
int main(){
	string a,b;
	cin>>a>>b;
	int x=1;
	int y=1;
	for(int i=0;i<a.length();i++){
		x*=toInterge(a[i]);
	}
	for(int i=0;i<b.length();i++){
		y*=toInterge(b[i]);
	}
	if(x%47==y%47)	cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
}
