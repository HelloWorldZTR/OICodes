#include<bits/stdc++.h>
using namespace std;

struct cp{
	//int id;
	int own[100];
	int per[100];
	int cnt;
} c[101];

int n, id, ct;

//set<pair<int, int> > ans;

int tot[101]; 

void doSolve(int n)  {//�ۼ� n��˾��������˾�Ĺɷ� �� tot[]�� ��ֻҪtot��i��>50,n���ƿ���i 
	//init();
	if(ct++>3)
		return;
	if(c[n].cnt>0) {
		for(int i=0; i<c[n].cnt; i++) {//ѭ���ù�˾�µ����й�Ʊ 
		//	if(c[n].per[i]>50) {//��ֹѭ������(д���˰�ι����������) 
				//vis[n][i] = 1;
			tot[c[n].own[i]] += c[n].per[i];//�ۼ� 
				//cout<<n<<"    "<<i<<endl;
		//	}
			if(c[n].per[i]>50) {//�Ѿ�����ס�Ĺ�˾ҲҪ�ۼ� 
				//ans.insert(make_pair(n, c[n].own[i]));
				doSolve(c[n].own[i]);
			}
		}
	}
}

int main() {
	cin>>n;
	/*����*/
	int lll = 0;
	for(int i=0; i<n; i++) {
		cin>>id;
		cin>>c[id].own[c[id].cnt]>>c[id].per[c[id].cnt];
		lll = max(id, lll);
		lll = max(c[id].own[c[id].cnt], lll);
		c[id].cnt++;
	}
	if(lll==0)
		lll = 100;
	cout<<lll<<endl; 
	for(int i=1; i<=lll; i++) {
		memset(tot, 0, sizeof(tot));
		ct=0;
		doSolve(i);
		for(int j=1; j<=lll; j++) {//�ۼ� n��˾��������˾�Ĺɷ� �� tot[]�� ��ֻҪtot��j��>50,i���ƿ���j
			if(tot[j]>50) {
				//ans.insert(make_pair(i, j));
				cout<<i<<" "<<j<<endl;
			}
			//cout<<tot[j]<<" ";
		}
		//cout<<endl;
	}
	/*��� 
	set<pair<int, int> >::iterator it;
	for(it=ans.begin(); it!=ans.end(); it++) {
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}*/
	return 0;
}

