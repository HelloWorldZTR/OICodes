/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: zhangxi58
PROG: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int dd[5];
bool judgex(int x)
{
	if((x%4==0)&&(x%100!=0)) return true;
	if(x%400==0) return true;
	return false;			
}
int main()
{
	int N,*p,x=0,z;
	cin>>N;
	for(int i=1900;i<=1900+N;i++)
	{
	if(judgex(i))*p=a;else *p=b;
	for(int j=0;j<=11;j++)
	{
		z=x+13;
		y=x%7;
		if(1<=y<=5)
		{
			a[y]+=1;
		}
		x+=p[j];
	}
	
}
	
	
}
