#include<iostream> 
using namespace std;

const int MAXV_KIND = 25;
const int MAXF_KIND = 15;

int vkind,
    req[MAXV_KIND],
    fkind,
    f[MAXF_KIND][MAXV_KIND];
    
int minlen,
    minpath[MAXF_KIND],
    path[MAXF_KIND],
	nowf[MAXV_KIND];
void print() {for(int i=0;i<vkind;i++)cout<<nowf[i]<<" ";cout<<endl;}
void solve(int cnt, int type) {
	if(cnt>minlen)
		return;
	/*º”…œtype÷÷*/
	int i;
	bool flag = true;
	for(i=0; i<vkind; i++) {
		//nowf[i] += f[type][i];
		if(nowf[i]<req[i]) {
			flag = false;
		}
	}
	if(flag){
		if(cnt<minlen) {
			minlen = cnt;
			for(int tmp=0; tmp<minlen; tmp++) {
				minpath[tmp] = path[tmp];
			}
			return;
		}
	}
	/*___________*/
	for(i=type; i<fkind; i++) {
		for(int tmp=0; tmp<vkind; tmp++) {
			nowf[tmp] += f[i][tmp];
		}
		path[cnt] = i;
		solve(cnt+1, i+1);
		for(int tmp=0; tmp<vkind; tmp++) {
			nowf[tmp] -= f[i][tmp];
		}
	}
}

int main() {
	//freopen("hols.txt", "r", stdin);
	
	cin>>vkind;
	for(int i=0; i<vkind; i++) {
		cin>>req[i];
	}
	cin>>fkind;
	for(int i=0; i<fkind; i++) {
		for(int j=0; j<vkind; j++) {
			cin>>f[i][j];
		}
	}
	minlen = fkind + 1;
	solve(0, 0);
	cout<<minlen<<" ";
	for(int i=0; i<minlen; i++) {
		cout<<minpath[i]+1<<" ";/*plus onr for human-readable*/
	}
	cout<<endl;
	return 0;
}
