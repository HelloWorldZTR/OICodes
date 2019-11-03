#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 510;
char a[maxn], b[maxn];
int a2[maxn], b2[maxn], c2[maxn];
int main() {
	cin>>a;
	cin>>b;
	int strlena = strlen(a);
	int strlenb = strlen(b);
	int i;
	for(i=0; i<strlena; i++) {
		a2[i] = a[strlena - i - 1]-'0';
	}
	for(i=0; i<strlenb; i++) {
		b2[i] = b[strlenb - i - 1]-'0';
	}
	//for(i=0; i<strlena; i++)
	/*
	for(i=0; i<strlena; i++) {
		cout<<a2[i];
	}cout<<endl;
	for(i=0; i<strlenb; i++) {
		cout<<b2[i];
	}cout<<endl;*/
	int tot = max(strlena, strlenb);
	int y = 0;
	for(i=0; i<tot; i++) {
		c2[i] = a2[i] + b2[i] + y;
		y = c2[i] / 10;
		c2[i] %= 10;
	}
	if(y!=0)
		cout<<y;
	for(i=tot-1; i>=0; i--) {
		cout<<c2[i];
	}cout<<endl;
	return 0;
}
