#include<iostream> 
using namespace std;

const int maxn = 10000;

int n; 

struct Point{
	int x;
	int y;
};

struct Carpet{
	Point A;//左下角坐标
	Point B;//右上角坐标
	/*计算方法： 
	a, b, g, k
	A.x = a
	A.y = b
	B.x = a + g
	B.y = b + k
	设有点Point C 
	IF(C.x>=A.x&&C.x<=B.x  &&  C.y>=A.y&&C.y<=B.y) 
		C在此carpet中 
	*/ 
} carpets[maxn];

int main() {
	
	cin>>n;
	int a, b, g, k;
	for(int i=0; i<n; i++){
		cin>>a>>b>>g>>k;
		carpets[i].A.x = a;
		carpets[i].A.y = b;
		carpets[i].B.x = a + g;
		carpets[i].B.y = b + k;
	}
	Point C;
	cin>>C.x>>C.y;
	for(int i=n-1; i>=0; i--){
		if(C.x>=carpets[i].A.x&&C.x<=carpets[i].B.x  &&  C.y>=carpets[i].A.y&&C.y<=carpets[i].B.y) {
			cout<<i+1<<endl;//plus_one is for human_readable
			return 0; 
		}
	}
	cout<<-1<<endl;
	return 0;
}
