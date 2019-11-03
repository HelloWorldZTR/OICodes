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

void dijk(int s) {/*���ӣ���*/ 
	for(int i=1; i<=maxn; i++) {//��ÿһ��������ɳ� 
		int min_ = 1e6;
		int nearest = -1;
		for(int j=1; j<=maxn; j++) {//�Ҿ��� i ����ǰ�㣩 ����Ĳ��ڼ����еĵ���� 
			if(selected[j]!=1 && con[i][j]<min_) {
				min_ = con[i][j];
				nearest = j;
			}
		}
		selected[nearest]  = 1;
		if(nearest!=-1) {		//�ٰ� ����ĵ� ��Ϊ�м�㣬 �����ɳ� 
			for(int j=1; j<=maxn; j++) {
				if(con[nearest][j] < 10000) { //������ͨ�����ɳ� 
					if(dis[j]>dis[nearest]+con[nearest][j]) {//�ɳ� 
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
	/*����*/
	memset(con, 0x3f3f3f3f, sizeof(con));
	for(int i=0; i<n; i++) {
		cin>>from>>to;
		cin>>temp;
		
		index1 = getIndex(from);
		index2 = getIndex(to);
		//if(con[index1][index2]>temp)/*ע�⣺������ֻ���¸�С�ģ����رߣ�*/ 
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
	
	/*����dis*/
	s = getIndex('Z');
	for(int i=1; i<=maxn; i++) {//��dis[i] Ϊ i��ԭ��ľ��� 
		if(i==s) {
			dis[i] = 0;//�Լ����Լ��϶�Ϊ0 
		}else{
			dis[i] = con[s][i];
		}
	}
	selected[s] = 1;
	dijk(s);
	
	/*�����ֻ�����д��ĸ��
	
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

