#include<iostream>
using namespace std;

const int MAXN = 1005;

int count1, count2, count3, 
    num[MAXN],
	unsorted,
	step;
int one2, one3;
int two1, two3;
int three1, three2;

int main() {
	int n;
	cin>>n;
	int i;
	for(i=0; i<n; i++) {
		cin>>num[i];
		if(num[i]==1)
			count1++;
		else if(num[i]==2)
			count2++;
		else
			count3++;
	}
	for(i=0; i<count1; i++) {
		if(num[i]!=1)
			unsorted++;
		if(num[i]==2)
			one2++;
		else if(num[i]==3)
			one3++; 
	}
	for(i=count1; i<count1+count2; i++) {
		if(num[i]!=2)
			unsorted++;
		if(num[i]==1)
			two1++;
		else if(num[i]==3)
			two3++;
	}
	for(i=count1+count2; i<n; i++) {//开始位置看错了，应该是上一个的结束位置 ERR::	for(i=count2; i<n; i++) { 
		if(num[i]!=3)
			unsorted++;
		if(num[i]==1)
			three1++;
		else if(num[i]==2)
			three2++;
	}
	/* 
	cout<<unsorted<<endl;
	
	case 
	
	cout<<one2<<" "<<one3 <<endl;
	cout<<two1<<" "<<two3 <<endl;
	cout<<three1<<" "<<three2 <<endl;
	*/
	int case1 = min(one2, two1);
	int case2 = min(one3, three1);
	int case3 = min(two3, three2);
	int case4 = (unsorted - 2 * case1 - 2 * case2 - 2 * case3) / 3;
	/*cout<<"case1: "<<case1<<endl;
	cout<<"case2: "<<case2<<endl;
	cout<<"case3: "<<case3<<endl;
	cout<<"case4: "<<case4<<endl;*/
	step = case1 + case2 + case3 + case4 * 2;
	cout<<step<<endl;
	return 0;
}
