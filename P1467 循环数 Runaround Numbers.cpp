#include<bits/stdc++.h>
using namespace std;

long m;

int next[11];
bool vis[11];

bool judge(long m) {
	
	memset(next, 0, sizeof(next));
	memset(vis , 0, sizeof(vis));
	
	char c[10];//�ѵ�ǰ�������ַ��� 
	int len = 0;
	sprintf(c, "%ld", m);
	len = strlen(c);
	
	for(int i=0; i<len; i++) {//һЩ��ǰ�ж� 
		next[i] = i + 1;      //����next 
		if(vis[c[i]-'0'] || c[i]=='0'){
			return false;
		}
		else{
			vis[c[i]-'0'] = true;
		}
	} 
	next[len-1] = 0;		//next 
	
	
	memset(vis, 0, sizeof(vis));
	
	int backup = 0, backup2;//��¼�������index 
	int cur = next[0];
	for(int i=0; i<len; i++){
		vis[c[backup]-'0'] = true;//�ж��Ƿ���� 
		
		/*���ݼ�¼�����һ������ģ��*/
		for(int j=0; j<c[backup]-'0'; j++){
			//cout<<c[cur]<<" ";
			backup2 = cur;
			cur = next[cur];
		}
		backup = backup2;
		/*-------------------------*/
		
		//cout<<endl;
		//cout<<"backup::"<<backup<<endl;
		bool isTrue = true;//�ж��Ƿ���� ������������ 
		for(int j=0; j<len; j++){
			if(!vis[c[j]-'0']){
				isTrue = false;
			}
		} 
		if(isTrue){ //�ж��Ƿ���� ������������ 
			if(c[backup] == c[0]) {//�ж��Ƿ�ص���ͷ
				return true;
			}
			break;
		} 
	}
	return false;
	
}

int main() {
	cin>>m;
	while(true) {
		m++;//λ�÷Ŵ���~������ 
		if(judge(m)){
			cout<<m<<endl;
			break;
		}
	}
	return 0;
}
