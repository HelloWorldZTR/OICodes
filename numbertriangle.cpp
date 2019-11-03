#include<bits/stdc++.h>
using namespace std;
/*
	!AC! 
	Date: 23/07/19 13:33
	Description: 
*/



int numbers[1010][1010];
int opt[1010][1010];

int main(){
	//freopen("numbertri.txt", "r", stdin);
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin>>numbers[i][j];
		}
	}	
	for(int i = 0; i < n; i++){
		opt[n-1][i] = numbers[n-1][i];
	}
	for(int i = n-2; i>=0; i--){
		for(int j = 0; j <= i; j++){
			int L = j;
			int R = j + 1;
			opt[i][j] = max(opt[i+1][L]+numbers[i][j], opt[i+1][R]+numbers[i][j]);
		}
	}
	cout<<opt[0][0]<<endl;
	return 0;
}
