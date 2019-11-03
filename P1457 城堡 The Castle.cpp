#include<iostream>
using namespace std;

const int MAXM = 50;
const int MAXN = 50;

struct room{
	int wall;
	int roomnum;
	bool vis;
}map[MAXM][MAXN];

int m, n;
int roomsize[MAXM*MAXN], totnum = 0;

void dfs(int x, int y) {
	/*check if the pos is available*/
	if(x>=0&&x<n && y>=0&&y<m&&!map[y][x].vis){
		map[y][x].vis = true;
		map[y][x].roomnum = totnum;
		roomsize[totnum]++;
	}
	else{
		return;
	}
	cout<<x<<"	"<<y<<endl;
	/*check conn*/
	int wall = map[y][x].wall;
	bool N = true, S = true, E = true, W = true;
	if(wall>=8){
		cout<<"S";
		S = false;
		wall -= 8;
	}
	if(wall>=4){
		cout<<"E";
		E = false;
		wall -= 4;
	}
	if(wall>=2){
		cout<<"N";
		N = false;
		wall -= 2;
	}
	if(wall>=1){
		cout<<"W";
		W = false;
		wall -= 1;
	}
	/*dfs rooms to NSEW and sign theirs roomnum*/
	if(N){
		dfs(x, y-1);
	}
	if(S){
		dfs(x, y+1);
	}
	if(E){
		dfs(x+1, y);
	}
	if(W){
		dfs(x-1, y);
	}
}

int main() {
	
	cin>>m>>n;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin>>map[i][j].wall;
		}
	}
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(!map[i][j].vis){
				totnum++;
				dfs(i, j);
			}
		}
	}
	cout<<totnum;
}
