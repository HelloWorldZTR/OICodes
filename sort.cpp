#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<algorithm>
#include<time.h>
using namespace std;
long a[1000000];
int main(){
	int n;
	ifstream inFile;
	inFile.open("testdata.in");
	clock_t begin,end;
        begin=clock();
	inFile>>n;
	for (int i=0 ; i<n;i++){
		inFile>>a[i];
	}
	/* for(int m=n-1;m>0;m--){
		for(int i=0;i<m;i++){
			if(a[i]>a[i+1]){
				cout<<"swap "<<a[i]<<"	"<<a[i+1]<<endl;
				long tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
			}
		}
	}*/
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	end=clock();
	cout<<"\n################################"<<endl;
	printf("用时：：%lf 秒\n",(double)(end-begin)/CLOCKS_PER_SEC);
	cout<<"################################"<<endl;
	cout<<endl;
	return 0;
}