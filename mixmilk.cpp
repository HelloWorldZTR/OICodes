#include<iostream> 
#include<algorithm>
using namespace std;
struct milk{
	int p;
	int a;
}m[5005];
bool cmp(const milk &a, const milk &b){
	return a.p<b.p?true:false;
}
int main(){
	int a,b;
	cin>>a>>b;
	for(int i=0;i<b;i++) 
		cin>>m[i].p>>m[i].a;
		
	sort(m,m+b,cmp);
	
	int nowmilk=0,nowmoney=0;
	while(nowmilk<a){
		for(int i=0;i<b;i++){
			if(m[i].a+nowmilk>=a){
				int req=a-nowmilk;
				nowmilk+=req;
				nowmoney+=m[i].p*req;
				break;
			}
			else{
				nowmilk+=m[i].a;
				nowmoney+=m[i].a*m[i].p;
			}
		}
	}
	cout<<nowmoney<<endl;
	return 0;
}
