#include<iostream>
using namespace std;
const int maxn = 35;
int src[maxn][maxn];
bool cannot[maxn][maxn];//标记不能填的
int n;
/*填数*/
void search(int y, int x) {
    src[y][x] = 2;
    if(x+1<n&&src[y][x+1]==0) {
        search(y, x+1);
    }
    if(y+1<n&&src[y+1][x]==0) {
        search(y+1, x);
    }
    if(y-1>=0&&src[y-1][x]==0) {
        search(y-1, x);
    }
    if(x-1>=0&&src[y][x-1]==0) {
        search(y, x-1);
    }
}
/*预处理*/
void search2(int y, int x) {
    cannot[y][x] = true;
    if(x+1<n&&src[y][x+1]==0&&!(cannot[y][x+1])) {
        search2(y, x+1);
    }
    if(y+1<n&&src[y+1][x]==0&&!(cannot[y+1][x])) {
        search2(y+1, x);
    }
    if(y-1>=0&&src[y-1][x]==0&&!(cannot[y-1][x])) {
        search2(y-1, x);
    }
    if(x-1>=0&&src[y][x-1]==0&&!(cannot[y][x-1])) {
        search2(y, x-1);
    }
}
int main() {
    cin>>n;
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin>>src[i][j];
        }
    }
    /*把边上的先做预处理*/
    for(i=0; i<n; i++) {
        if(src[0][i]==0) 
            search2(0, i);
        if(src[i][0]==0)
            search2(i, 0);
        if(src[n-1][i]==0)
            search2(n-1, i);
        if(src[i][n-1]==0)
            search2(i, n-1);
    }
    bool isOK;
    int zeroCnt;
    for(i=0; i<n; i++) {
        isOK = false;
        zeroCnt = 0;
        for(j=0; j<n; j++) {
            if(isOK == true&&src[i][j]==1&&zeroCnt>0) {
                zeroCnt = 0;
                isOK = false;
            }
            if(isOK == false&&src[i][j]==1) {
                isOK = true;
            }
            else if(isOK == true&&src[i][j]==0&&!(cannot[i][j])) {
                zeroCnt++;
                search(i, j);
                //cout<<"serching: "<<i<<" "<<j<<endl;
            }
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
        cout<<src[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
