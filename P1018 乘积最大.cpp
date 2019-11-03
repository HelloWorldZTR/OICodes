#include<bits/stdc++.h>
/*
*	不会行了吧 
*/
using namespace std;

struct Data{
	char data[40];
	int len;
	
	/*成员函数*/ 
	Data(){
		memset(data, 0, sizeof(data));
		len = 0;
	}
	Data& operator =(const char c[]){
		//memset(data, 0, sizeof(data));
		int l = strlen(c);
		for(int i=0; i<l; i++) {
			data[i] = c[i];
		}
		len = l;
		return *this;
	}
	Data& operator =(const Data b){
		//memset(data, 0, sizeof(data));
		for(int i=0; i<max(len, b.len); i++) {
			data[i] = b.data[i];
		}
		len = max(len, b.len);
		return *this;
	}
	/*重载*运算符*/
	Data operator *(const Data &b_) {
		int a[40], b[40], c[40];
		Data ans;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int lena = len;
		int lenb = b_.len;
		int lenc = lena + lenb;
		for(int i=0; i<lena; i++) {
			a[lena-i] = data[i] - '0';
		}
		for(int i=0; i<lenb; i++) {
			b[lenb-i] = b_.data[i] - '0';
		}
		int x;
		if(lena>=lenb) {
			for(int i=1; i<=lena; i++) {
				x = 0;
				for(int j=1; j<=lenb; j++) {
					c[i+j-1] = a[i] * b[j] + x + c[i+j-1];
					x = c[i+j-1] / 10;
					c[i+j-1] = c[i+j-1] % 10;
				}
				c[i+lenb] = x;
			}
			while(c[lenc]==0 && lenc>1) 
				lenc--;
			for(int i=lenc; i>=1; i--) {
				ans.data[lenc-i] = c[i] + '0';
			}
			ans.len = lenc;
		}
		return ans;
	}
	friend bool operator >(const Data &a, const Data &b) {
		return false;
	}
	friend ostream& operator<<(ostream& out,const Data& da) {
   		out<<da.data;
   		return out;
	}
}; 

Data max(Data a, Data b) {
	return a>b?a:b;
}

int main() {
	Data a, b, c;
	a = "1111111111111";
	b = "22";
	c = a*b;
	cout<<a<<endl;
	cout<<"*"<<endl;
	cout<<b<<endl;
	cout<<endl;
	cout<<c<<endl;
	return 0;
}

