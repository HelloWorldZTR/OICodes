#include<bits/stdc++.h>
/*
	Name: P1215 [USACO1.4]Ä¸Ç×µÄÅ£ÄÌ Mother's Milk
	Copyright: NONE
	Author: HelloWorldZTR
	Date: 25/07/19 08:31
	Description: AC
*/

using namespace std;
struct milk{
	int a;
	int b;
	int c;
};
milk mk;
bool visited[22][22][22]; 
int ac, bc, cc;
set<int> ans; 
void pour(int &from, int &to, int limitOfTo){
	if(from+to>limitOfTo){
		from -= limitOfTo - to;
		to = limitOfTo;
	}else{
		to += from;
		from = 0;
	}
}
void solve(milk mk){
	milk tmp = mk;
	milk tmp1= mk;
	if(tmp.a!=0){			//a²»¿Õ 
		if(tmp.b<bc){		//b²»Âú
			//pour a into b
			tmp1 = mk;
			pour(tmp1.a, tmp1.b, bc);
			if(!visited[tmp1.a][tmp1.b][tmp1.c]){
				visited[tmp1.a][tmp1.b][tmp1.c] = true;
				solve(tmp1);
			}
		} 
		if(tmp.c<cc){
			//pour a into c
			tmp1 = mk;
			pour(tmp1.a, tmp1.c, cc);
			if(!visited[tmp1.a][tmp1.b][tmp1.c]){
				visited[tmp1.a][tmp1.b][tmp1.c] = true;
				solve(tmp1);
			}
		}	 
	}
	if(tmp.b!=0){
		if(tmp.a<ac){
			//pour b into a
			tmp1 = mk;
			pour(tmp1.b, tmp1.a, ac);
			if(!visited[tmp1.a][tmp1.b][tmp1.c]){
				visited[tmp1.a][tmp1.b][tmp1.c] = true;
				solve(tmp1);
			}
		}
		if(tmp.c<cc){
			//pour b into c
			tmp1 = mk;
			pour(tmp1.b, tmp1.c, cc);
			if(!visited[tmp1.a][tmp1.b][tmp1.c]){
				visited[tmp1.a][tmp1.b][tmp1.c] = true;
				solve(tmp1);
			}
		}
	}
	if(tmp.c!=0){
		if(tmp.a<ac){
			//pour c into a
			tmp1 = mk;
			pour(tmp1.c, tmp1.a, ac);
			if(!visited[tmp1.a][tmp1.b][tmp1.c]){
				visited[tmp1.a][tmp1.b][tmp1.c] = true;
				solve(tmp1);
			}
		}
		if(tmp.b<bc){
			//pour c into b
			tmp1 = mk;
			pour(tmp1.c, tmp1.b, bc);
			if(!visited[tmp1.a][tmp1.b][tmp1.c]){
				visited[tmp1.a][tmp1.b][tmp1.c] = true;
				solve(tmp1);
			}			
		}
	}
		//......serch how to pour
	if(mk.a==0)	{ 
		ans.insert(mk.c);	//Find the answers
	} 
	return;
}
void printAnswer(){
	set<int>::iterator it;
	for(it=ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
int main(){
	cin>>ac>>bc>>cc;
	mk.a = mk.b = 0;mk.c = cc;
	memset(visited, false, sizeof(bool)*22*22*22);

	solve(mk);
	printAnswer();
	return 0;
}
