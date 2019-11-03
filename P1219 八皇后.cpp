#include<iostream> 
using namespace std;

const int maxn = 15;

int n, m[maxn][maxn], ans[maxn], anscount = 0, collock[maxn], lockl1[maxn+maxn], lockl2[maxn+maxn]; 

/*check m[x][y]*/
bool check(int x, int y) {
    if(collock[y]==1 || lockl1[x+y]==1 || lockl2[x-y+n]==1)//用这个标记已经有皇后的列&对角线 
        return false;//上天保佑不超时（滑稽)08/08/19 11:06
	return true;
}

void solve(int line) {
	if(line > n) {
		//print answer
		if(anscount<3){//只输出前三解 
			for(int i=1; i<line; i++)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
		anscount++;
	}else{
		for(int i=1; i<=n; i++) {
			if(check(line, i)) {//can place
				//place&&lock
					m[line][i] = 1;
                	collock[i] = 1;
                	lockl1[line+i] = 1;
                	lockl2[line-i+n] = 1;
				//write ans
					ans[line] = i;
				//solve again
					solve(line+1);
				//undo place&&lock;
					m[line][i] = 0;
                	collock[i] = 0;
                	lockl1[line+i] = 0;
                	lockl2[line-i+n] = 0;
			}
		}
	}
}

int main() {
	cin>>n;
	solve(1);
	cout<<anscount<<endl; 
	return 0;
}
