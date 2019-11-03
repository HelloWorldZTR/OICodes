#include<bits/stdc++.h> 
#include<cstdio>
#include<stdlib.h>
#include<cstring>
/*
	Name: P1217 [USACO1.5]�������� Prime Palindromes
	Copyright: NONE
	Author: HelloWorldZTR
	Date: 25/07/19 14:18
	Description: AC
*/
using namespace std;

char tmp[20];
int a, b;

bool isPrime(int num){
	if(num == 1)
		return false;
	int limit = (int)sqrt((double)num);
	for(int i = 2 ; i<=limit ; i++){
		if(num % i == 0)
			return false;
	}
	return true;
}

void solve(int len, int origin){
	int limit = origin%2==0?origin/2:( origin/2+1 );
	//cout<<limit<<" ";
	if(len<limit){		//��� 
		int result;
		sscanf(tmp, "%d", &result);
		if(result>b)	//�Ѿ�������Χ���˳� 
			return;
		if(isPrime(result) && result>=a)
			cout<<result<<endl;//��ӡ��� 
		return;
	}
	int i;
	if(len == origin)	//����ǵ�һλ��i����Ϊ0 
		i = 1;
	else 				//�м����Ϊ0 
		i = 0; 
	for( ; i<=9; i++){
		tmp[len] = tmp[origin - len] = i + '0';
		solve(len-1, origin);
	}
}

int main(){
	char c[11];
	cin>>a>>c;
	int limit = strlen(c);
	sscanf(c, "%d", &b);
	//cout<<b<<endl;
	for(int len = 0; len<limit; len++)
		solve(len, len);
	return 0;
}
