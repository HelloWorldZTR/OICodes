#include<iostream>
using namespace std;
int main(){
	double now=0,dis;
	int count = 0;
	cin>>dis;
	for(double step=2;now<dis;step*=0.98){
		now+=step;
		count++;
	}
	cout<<count<<endl;
	return 0;
}
