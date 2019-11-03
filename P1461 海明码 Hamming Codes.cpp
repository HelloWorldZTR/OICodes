#include<iostream>
#include<cstring>
using namespace std;

struct hamming {
	int num;
	int b[8];
} ans[64];

/*转换二进制*/
int conv(int s,int result[]) {
	int x = s;
	int cur = 0;
	while(x!=0) {
		result[cur++] = x % 2;
		x /= 2;
	}
	return cur;
}

int getHamming(int a[], int b[], int len) {
	int count = 0;
	for(int cur = 0; cur<len; cur++) {
		if(a[cur]^b[cur])
			count++;
	}
	//cout<<"Hamming::"<<count<<endl;
	return count;
} 

int main() {
	int n, b, d;
	cin>>n>>b>>d;
	int now = 0, count = 1;//从0开始所以+1 
	ans[now].num = 0;
	while(count<n) {
		
		bool flag = true;
		hamming tmp;
		for(int i=ans[now].num+1; flag; i++) {
			/*得到i的hamming距离*/
			memset(tmp.b, 0, sizeof(tmp.b));
			tmp.num = i;int s = conv(i, tmp.b);
			//for(int g=s-1;g>=0;g--)cout<<tmp.b[g]<<" ";
			///cout<<endl;
			bool ok = true;/*判断是否与前面都符合条件*/
			for(int j=0; j<=now; j++){
				if(getHamming(tmp.b ,ans[j].b , b) < d) {
					ok = false;
				}
			} 
			if(ok){
				ans[++now] = tmp;
				count++;
				flag = false;
				break;
			}
		}
	}
	int formc = 0; 
	for(int i=0;i<=now;i++){
		if(formc%10 == 0 && formc!=0)
			cout<<endl;//集齐十个送回车菌一只 
		cout<<ans[i].num<<" ";
		formc++;
	}
	return 0;
}
