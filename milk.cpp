#include<iostream>
#include<algorithm>
using namespace std;

struct milk{
	int start;
	int end;
}t[6000];

bool cmp(const milk &a,const milk &b){
	return a.start<b.start?true:false;
}
int main(){
	freopen("milk.txt","r",stdin) ;
	int np;
	cin>>np;
	for(int i=0;i<np;i++){
		cin>>t[i].start>>t[i].end;
	}
	sort(t,t+np,cmp);
	
	int max1=0,max2=0,start,end;
	start=t[0].start;
	end=t[0].end;
	max1=end-start;
	for(int i=0;i<np-1;i++){
		if(end<t[i+1].end && end>=t[i+1].start){//于下一个重合 
			end=t[i+1].end;
			if(end-start>max1){
				//end=t[i+1].end;
				max1=end-start;
			}
		}
		else if(t[i+1].start>end){//不重合 
			start=t[i+1].start;
			if(start-end>max2){
				max2=start-end;
			}
			end = t[i+1].end;
		}
	} 
	milk last=t[np-1];
	if(last.start>end){
		if(last.start-end>max2)//不重合 
			max2=last.start-end;
		else if(last.end>end && last.start<=end){//重合 
			end=last.end;
			if(end-start>max1)
				max1=end-start;
		}
	}
	
	cout<<max1<<" "<<max2<<endl;
	
	return 0; 
	
}
