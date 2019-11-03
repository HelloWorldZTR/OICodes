#include<iostream>

using namespace std;

int mountains[1010];

int main(){
	int n;
	cin>>n;
	int heightest = 0;
	for(int i = 0; i < n; i++){
		cin>>mountains[i];
		if(mountains[i] > heightest)
			heightest = mountains[i];
	}
	int min		= 999999999;
	int high	= 0;
	int sum		= 0;
	for(int low = 0; low < heightest; low++){
		sum  = 0;		
		high = low + 17;
		for(int i = 0; i < n; i++){
			if(mountains[i]>high){
				sum += ( mountains[i] - high )*( mountains[i] - high ); 
			}
			if(mountains[i]<low){
				sum += (low - mountains[i])*(low - mountains[i]);
			}
		}
		if(sum<min)
			min	= sum;
	} 
	if(min == 999999999)
		cout<<0<<endl;
	else
		cout<<min<<endl;
	
	return 0;
}
