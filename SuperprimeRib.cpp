#include<bits/stdc++.h>
#include<cstdio>
#include<stdlib.h>
/*
	Name: P1218 [USACO1.5]����������߹� Superprime Rib
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
	if(len == 0){			//�ݹ���� (�����˸���0):P 
		int result;
		sscanf(c, "%d", &result);
		cout<<result<<endl;	//������ 
	}
	else
		for(int i = 1; i<=9; ) {//�������Ҫ��λ���ı� 
			c[totlen - len] = i + '0';
			int tmp;			//���һ������... 
			sscanf(c, "%d", &tmp);
			if(isPrime(tmp)){	//��֤ÿ���һλ�������� 
				solve(len - 1, totlen);
				c[totlen - len + 1] = 0;	
								//��һλ�Ĵ洢�ռ�����Ҫ
								//���㣬��Ȼsscanf����һλ 
			}
			if(len == totlen)
				i++;			//����ǵ�һλ��2��ż����Ҳ�� 
			else 
				i+=2; 			//�����β��һ������ż����ֻ��ö������ 
		} 
}

int main() {
	int n;
	cin>>n;
	solve(n, n);
	return 0;
}
