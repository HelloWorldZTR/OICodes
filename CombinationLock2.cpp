#include<iostream>
using namespace std;

int n;
int a[6][4],b[6][4];
int Prev[110],Next[110];

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
	for(int i=1;i<=n;i++){
		Prev[i]=i-1;
		Next[i]=i+1;
	}
	Prev[1]=n;
	Next[n]=1;
	for(int i=0;i<3;i++){
		//a[0][i] = 
		a[1][i] = Prev[a[0][i]];
		a[2][i] = Prev[Prev[a[0][i]]];
		a[3][i] = Next[a[0][i]];
		a[4][i] = Next[Next[a[0][i]]];
		//b[0][i] = 
		b[1][i] = Prev[b[0][i]];
		b[2][i] = Prev[Prev[b[0][i]]];
		b[3][i] = Next[b[0][i]];
		b[4][i] = Next[Next[b[0][i]]]; 		
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
//					cout<<a[i][m]<<" == "<<b[j][m]<<endl;
				}	
			}
		}
	}
//	cout<<count[0]*count[1]*count[2]<<endl;
	cout<<sum-count[0]*count[1]*count[2]<<endl;
	return 0;
	
}
