#include<bits/stdc++.h>
using namespace std;

long m;

int next[11];
bool vis[11];

bool judge(long m) {
	
	memset(next, 0, sizeof(next));
	memset(vis , 0, sizeof(vis));
	
	char c[10];//把当前数整成字符串 
	int len = 0;
	sprintf(c, "%ld", m);
	len = strlen(c);
	
	for(int i=0; i<len; i++) {//一些提前判断 
		next[i] = i + 1;      //设置next 
		if(vis[c[i]-'0'] || c[i]=='0'){
			return false;
		}
		else{
			vis[c[i]-'0'] = true;
		}
	} 
	next[len-1] = 0;		//next 
	
	
	memset(vis, 0, sizeof(vis));
	
	int backup = 0, backup2;//记录最后数的index 
	int cur = next[0];
	for(int i=0; i<len; i++){
		vis[c[backup]-'0'] = true;//判断是否完成 
		
		/*根据记录的最后一个进行模拟*/
		for(int j=0; j<c[backup]-'0'; j++){
			//cout<<c[cur]<<" ";
			backup2 = cur;
			cur = next[cur];
		}
		backup = backup2;
		/*-------------------------*/
		
		//cout<<endl;
		//cout<<"backup::"<<backup<<endl;
		bool isTrue = true;//判断是否完成 遍历所有数字 
		for(int j=0; j<len; j++){
			if(!vis[c[j]-'0']){
				isTrue = false;
			}
		} 
		if(isTrue){ //判断是否完成 遍历所有数字 
			if(c[backup] == c[0]) {//判断是否回到开头
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
		m++;//位置放错了~呜呜呜 
		if(judge(m)){
			cout<<m<<endl;
			break;
		}
	}
	return 0;
}
