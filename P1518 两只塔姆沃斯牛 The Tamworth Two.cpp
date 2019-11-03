#include<iostream>
using namespace std;
const int N = 0;
const int E = 1;
const int S = 2;
const int W = 3;

const int X = 0;
const int Y = 1;

struct point{
	int x;
	int y;
	int heading;
};
struct zt{
	point fj;
	point c;
} map[11111];

bool zhangai[12][12], vis[11][11][4][11][11][4];
int to[4][2];


int main() {
	to[N][X] =  0; to[N][Y] = -1;
	to[S][X] =  0; to[S][Y] =  1;
	to[E][X] =  1; to[E][Y] =  0;
	to[W][X] = -1; to[W][Y] =  0;
	char temp;
	for(int y=0; y<=11; y++) {
		for(int x=0; x<=11; x++) {
			if(x==0||y==0||x==11||y==11) {
				zhangai[x][y] = true;
				continue;
			}
			cin>>temp;
			if(temp=='*') {
				zhangai[x][y] = true;
			}else if(temp=='C') {
				map[0].c.x = x;
				map[0].c.y = y;
				map[0].c.heading = N;
			}else if(temp=='F') {
				map[0].fj.x = x;
				map[0].fj.y = y;
				map[0].fj.heading = N;
			}
		}
	}
	vis[map[0].fj.x][map[0].fj.y][map[0].fj.heading][map[0].c.x][map[0].c.y][map[0].c.heading] = true;
	/*for(int i=0; i<=11; i++){
		for(int j=0; j<=11; j++) {
			cout<<zhangai[j][i]<<" ";
		}
		cout<<endl;
	}
	cin>>temp;*/
	int i=0;
	while(++i) {
		int next_fj_x = map[i-1].fj.x + to[map[i-1].fj.heading][X];
		int next_fj_y = map[i-1].fj.y + to[map[i-1].fj.heading][Y];
		if(!zhangai[next_fj_x][next_fj_y]) {
			map[i].fj.x = next_fj_x;
			map[i].fj.y = next_fj_y;
			map[i].fj.heading = map[i-1].fj.heading;
		}
		else {
			map[i].fj.x = map[i-1].fj.x;
			map[i].fj.y = map[i-1].fj.y;
			map[i].fj.heading = map[i-1].fj.heading;
			if(map[i].fj.heading!=3) {
				map[i].fj.heading+=1;
			}
			else {
				map[i].fj.heading = N;
			}
		}
		int next_c_x = map[i-1].c.x + to[map[i-1].c.heading][X];
		int next_c_y = map[i-1].c.y + to[map[i-1].c.heading][Y];
		if(!zhangai[next_c_x][next_c_y]) {
			map[i].c.x = next_c_x;
			map[i].c.y = next_c_y;
			map[i].c.heading = map[i-1].c.heading;
		}else {
			map[i].c.x = map[i-1].c.x;
			map[i].c.y = map[i-1].c.y;
			map[i].c.heading = map[i-1].c.heading;
			if(map[i].c.heading!=3) {
				map[i].c.heading+=1;
			}
			else {
				map[i].c.heading = N;
			}
		}
		if(!vis[map[i].fj.x][map[i].fj.y][map[i].fj.heading][map[i].c.x][map[i].c.y][map[i].c.heading])
			vis[map[i].fj.x][map[i].fj.y][map[i].fj.heading][map[i].c.x][map[i].c.y][map[i].c.heading] = true;
		else {
			cout<<0<<endl;
			return 0;
		}
		if(map[i].fj.x==map[i].c.x && map[i].fj.y==map[i].c.y) {
			cout<<i<<endl;
			break;
		}
		/*cout<<next_fj_x<<" "<<next_fj_y<<mapendl;
		cout<<next_c_x<<" "<<next_c_y<<endl;
		if(i==49){
			cin>>temp;
		}
		if(map[i]==0||next_c_x==0) {
			cout<<zhangai[next_c_x][next_c_y]<<endl;
			cin>>temp;
		}*/
	}
	return 0;
}

