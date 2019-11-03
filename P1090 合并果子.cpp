#include<bits/stdc++.h>
using namespace std;

struct data{
	long long a;
	friend bool operator <(data a, data b){
		return a.a>b.a;
	}
}tmp; 
int n;
long long helloworldztr;
priority_queue<data>q;

int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>tmp.a;
		q.push(tmp);
	}
	while(q.size()>1) {
		data a = q.top();q.pop();
		data b = q.top();q.pop();
		data c;
		c.a = a.a + b.a;
		helloworldztr += a.a+b.a;
		q.push(c);
	}
	cout<<helloworldztr<<endl;
	return 0;
}

