#include<iostream>
using namespace std;

int n;
int a[6][4],b[6][4];

int main()
{
	cin>>n;
	cin>>a[0][0]>>a[0][1]>>a[0][2];
	cin>>b[0][0]>>b[0][1]>>b[0][2];
	if(n<=5){
		cout<<n*n*n<<endl;//BUG£º£º 
					      // n<=5Ê±Ó¦Îªn^3 
		return 0;
	}	
	for(int i=0;i<3;i++){
		if(a[0][i]-1<=0)	a[1][i]=n-1;
		else	a[1][i]=a[0][i]-1;
		if(a[0][i]-2<=0)	a[2][i]=a[0][i]-3+n;
		else	a[2][i]=a[0][i]-2;
		if(a[0][i]+1>n)	a[3][i]=1;
		else	a[3][i]=a[0][i]+1;
		if(a[0][i]+2>n)	a[4][i]=a[0][i]+2-n;
		else	a[4][i]=a[0][i]+2;
		
		if(b[0][i]-1<=0)	b[1][i]=n-1;
		else	b[1][i]=b[0][i]-1;
		if(b[0][i]-2<=0)	b[2][i]=b[0][i]-3+n;
		else	b[2][i]=b[0][i]-2;
		if(b[0][i]+1>n)	b[3][i]=1;
		else	b[3][i]=b[0][i]+1;
		if(b[0][i]+2>n)	b[4][i]=b[0][i]+2-n;
		else	b[4][i]=b[0][i]+2;
		
	}
//	cout<<a[0][1]<<" "<<b[0][i]<<endl<<a[1][i]<<" "<<b[1][i]<<endl<<a[2][i]<<" "<<b[2][i]<<endl<<a[3][i]<<" "<<b[3][i]<<endl<<a[4][i]<<" "<<b[4][i]<<endl;
//	for(int i=0;i<5;i++){
//		cout<<a[i][0]<<a[i][1]<<a[i][2]<<endl;
//		cout<<b[i][0]<<b[i][1]<<b[i][2]<<endl;
//		cout<<"___________________________"<<endl;
//	}
	int sum=5*5*5*2;
	int count[4]={0};
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			for(int m=0;m<3;m++){
				if(a[i][m]==b[j][m]){
					count[m]++;
					//cout<<a[i][m]<<" == "<<b[j][m]<<endl;
				}	
			}
		}
	}
	cout<<sum-count[0]*count[1]*count[2]<<endl;
	return 0;
	
}
