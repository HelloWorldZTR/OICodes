#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int check[125010], num[125010];
bool isPara(int num1, int m){
	for(int i = 0; i<2*m*m; i++){
		if(num[i]==num1)
			return check[num[i]];
	}
	return false;
}
bool canGoFurther(int n, int m, int a, int b){
	if( 2*(m*m) < a+(n-1)*b )
		return false;
	else 
		return true;
}
int main() {
	int n, m;
	freopen("ari.txt", "r", stdin);
	cin>>n>>m; 
	clock_t start, end;
	start = clock();
	//init
	int cur = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			check[i*i+j*j] = 1;
			num[cur] = i*i+j*j;
			cur++;
		}
	}
	//init
	int a = 0, b = 1, count = 0;
	while(true){
		a = 0;
		while(true){
			int tot = 0;
			while(tot < n && tot != -1){
				for(int i = 0; i<n; i++){
					int tmp = a + (i * b);
					if(isPara(tmp, m))
						tot++;
					else{
						tot = -1;
						break;
					}
				} 
			}
			if(tot != -1 && tot == n){
				cout<<a<<" "<<b<<endl;
				count++;
			}
			if(canGoFurther(n, m, a, b))
				a++;
			else 
				break;
		}
		if(canGoFurther(n, m, 0, b) && count<=10000)
			b++;
		else 
			break;
	}
	if(count == 0){
		cout<<"NONE"<<endl;
	}
	end = clock();
	cout<<"Time used :"<<(double)(end-start)/ (CLOCKS_PER_SEC)<<endl;
	return 0;
}
