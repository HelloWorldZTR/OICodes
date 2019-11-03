#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 2*26+1; 

int con[60][60], dis[60], selected[60], n, s;

int getIndex(char c) {
	int index;
	if(c>='a' && c<='z') {
		index = c-'a'+26+1;
	}
	else{
		index = c-'A'+1;
	}
	return index;
}

void dijk(int s) {/*板子（）*/ 
	for(int i=1; i<=maxn; i++) {//对每一个点进行松弛 
		int min_ = 1e6;
		int nearest = -1;
		for(int j=1; j<=maxn; j++) {//找距离 i （当前点） 最近的不在集合中的点加入 
			if(selected[j]!=1 && con[i][j]<min_) {
				min_ = con[i][j];
				nearest = j;
			}
		}
		selected[nearest]  = 1;
		if(nearest!=-1) {		//再把 最近的点 作为中间点， 进行松弛 
			for(int j=1; j<=maxn; j++) {
				if(con[nearest][j] < 10000) { //必须连通才能松弛 
					if(dis[j]>dis[nearest]+con[nearest][j]) {//松弛 
						dis[j] = dis[nearest]+con[nearest][j];
					}
				} 
			}
		}
	}
}
void floyd() {
	for(int k=1; k<=maxn; k++) {
		for(int i=1; i<=maxn; i++) {
			for(int j=1; j<=maxn; j++) {
				if(i!=j && i!=k && j!=k) {
					if(con[i][j]>con[i][k]+con[k][j]) {
						con[i][j] = con[i][k]+con[k][j];
					}
				}
			}
		}
	} 
}

int main() {
	char from, to;
	int index1, index2, temp;
	
	cin>>n;
	/*输入*/
	memset(con, 0x3f3f3f3f, sizeof(con));
	for(int i=0; i<n; i++) {
		cin>>from>>to;
		cin>>temp;
		
		index1 = getIndex(from);
		index2 = getIndex(to);
		//if(con[index1][index2]>temp)/*注意：：这里只更新更小的（有重边）*/ 
		con[index1][index2] = min(con[index1][index2], temp);
		con[index2][index1] = min(con[index2][index1], temp);
			
	}
	/*debug
	for(int i=1; i<=26*2; i++) {
		for(int j=1; j<=26*2; j++) {
			cout<<con[i] [j]<<" ";
		}
		cout<<endl;
	}
	
	/*计算dis*/
	s = getIndex('Z');
	for(int i=1; i<=maxn; i++) {//设dis[i] 为 i到原点的距离 
		if(i==s) {
			dis[i] = 0;//自己连自己肯定为0 
		}else{
			dis[i] = con[s][i];
		}
	}
	selected[s] = 1;
	dijk(s);
	
	/*输出（只输出大写字母）
	
	for(char i='A'; i<'Z'; i++) {
		int idx = getIndex(i);
		cout<<i<<" "<<dis[idx]<<endl;
		
	}
	*/ 
	floyd();
	int ans = 1e6;
	char c;
	for(char i='A'; i<'Z'; i++) {
		int idx = getIndex(i);
		//cout<<i<<" "<<con[idx][s]<<endl;
		if(con[idx][s]<ans) {
			ans = con[idx][s];
			c = i;
		}
	}
	cout<<c<<" "<<ans<<endl;
	return 0;
}

