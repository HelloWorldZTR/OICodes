//INFO::
//TLE 3
//AC  7
//NEED TO BE RE_WORK

#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1005;
int ma[maxn][maxn], n, m;
bool vis[maxn][maxn];
int search(int x, int y) {
//    cout<<"Now at ("<<x<<" , "<<y<<")\n";
    vis[x][y] = true;
    int res = 1;
    int& now = ma[x][y];
    if(x+1<n && ma[x+1][y] xor now && !vis[x+1][y]) {
        res += search(x+1, y);
    }
    if(y+1<n && ma[x][y+1] xor now && !vis[x][y+1]) {
        res += search(x, y+1);
    }
    if(x-1>=0 && ma[x-1][y] xor now && !vis[x-1][y]) {
        res += search(x-1, y);
    }
    if(y-1>=0 && ma[x][y-1] xor now && !vis[x][y-1]) {
        res += search(x, y-1);
    }    
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int i, j;
    char tmp;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin>>tmp;
            ma[i][j] = tmp - '0';
        }
    }
    int x1, y1;
    for(i=0; i<m; i++) {
        cin>>x1>>y1;
        memset(vis, false, sizeof vis);
        cout<<search(x1-1, y1-1)<<endl;//-1因为题目是从1开始的，而我是从0
    }
    return 0;
}
