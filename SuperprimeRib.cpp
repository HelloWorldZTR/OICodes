#include<bits/stdc++.h>
#include<cstdio>
#include<stdlib.h>
/*
	Name: P1218 [USACO1.5]特殊的质数肋骨 Superprime Rib
	Copyright: NONE
	Author: HelloWorldZTR
	Date: 26/07/19 09:06
	Description: AC
*/
using namespace std;

bool isPrime(int num) {
	if(num == 1)
		return false;
	int limit = (int)sqrt((double)num);
	for(int i = 2;i<=limit; i++){
		if(num%i == 0 )
			return false;
	}
	return true;
}

char c[10];
void solve(int len, int totlen) {
	if(len == 0){			//递归出口 (被坑了个爆0):P 
		int result;
		sscanf(c, "%d", &result);
		cout<<result<<endl;	//输出结果 
	}
	else
		for(int i = 1; i<=9; ) {//调整语句要依位数改变 
			c[totlen - len] = i + '0';
			int tmp;			//添加一个素数... 
			sscanf(c, "%d", &tmp);
			if(isPrime(tmp)){	//保证每添加一位还是素数 
				solve(len - 1, totlen);
				c[totlen - len + 1] = 0;	
								//下一位的存储空间用完要
								//清零，不然sscanf会多读一位 
			}
			if(len == totlen)
				i++;			//如果是第一位，2（偶数）也行 
			else 
				i+=2; 			//如果在尾部一定不是偶数，只用枚举奇数 
		} 
}

int main() {
	int n;
	cin>>n;
	solve(n, n);
	return 0;
}
