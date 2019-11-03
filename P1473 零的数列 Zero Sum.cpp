#include<iostream>
#include<cstdio>
using namespace std;
long num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},//0用来占位 
	n;
char sq[10];

bool check() {
	int num1, num2;
	for(int i=0; i<10; i++) {/*记得先还原序列！！！！！！！！！*/
		num[i] = i;
	}
	for(int i=0; i<n-1; i++) {/*对空格预判， 把空格之后的值放在空格前
								*1 2+3	就会变成 12|2|+|3 
								*num1取值的时候会取第一个12， 2不做处理，然后+num2 即+3
								*num1就=15 
								*/
		if(sq[i]==' '&&sq[i+1]==' ') {
			//cout<<"dead" <<endl;
			return false;/*出现空格双连（及以上）是不可能组成的 */
		}
		if(sq[i]==' ') {
			num[i+1] = num[i+1]*10 + num[i+2];
			//num[i+2] = num[i+1];
		}
	}
	num1 = num[1];
	for(int i=0; i<n-1; i++) {
		num2 = num[i+2];
		if(sq[i]=='+') {
			//cout<<num1<<"+"<<num2<<endl;
			num1 = num1+num2;
		}
		else if(sq[i]=='-') {
			//cout<<num1<<"-"<<num2<<endl;
			num1 = num1 - num2;
		}
		else {
			continue;
		}
		//cout<<num1<<" ";
	}
	//cout<<endl;
	//cin>>num2;
	return num1==0;
}

void solve(int i) {
	if(i==1) {
		if(check()) {
			/*print answer*/
			int j;
			for(j=0; j<n-1; j++) {
				cout<<j+1;
				cout<<sq[j];
			}
			cout<<j+1<<endl;
		}
	}
	else {
		sq[n-i] = ' ';
		solve(i-1);
		sq[n-i] = '+';
		solve(i-1);
		sq[n-i] = '-';
		solve(i-1);
	}
}

int main() {
	cin>>n;
	solve(n);
	return 0;
}

