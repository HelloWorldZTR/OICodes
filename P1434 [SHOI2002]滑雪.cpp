#include<iostream>
using namespace std;

const int maxR = 101;
const int maxC = 101;

int rows, cols;
//x为列col，y为行row
//所有数组都按照y，x读取
int map[maxR][maxC], f[maxR][maxC];

void dfs(int x, int y, int step) {
    /*Update current step*/
    //cout<<f[y][x]<<endl;
    if(f[y][x]<step)
        f[y][x] = step;
    else if(step!=1)
        return; 
    /*Search for next step that is avaliable*/
    step++;
    if(//Right
        x+1<cols
        &&
        map[y][x+1] > map[y][x]
    )
        dfs(x+1, y, step);
    if(//Down
        y+1<rows
        &&
        map[y+1][x] > map[y][x]
    )
        dfs(x, y+1, step);
    if(//Left
        x-1>=0
        &&
        map[y][x-1] > map[y][x]
    )
        dfs(x-1, y, step);
    if(//Up
        y-1>=0
        &&
        map[y-1][x] > map[y][x]
    )
        dfs(x, y-1, step);
}

int main () {
    cin>>rows>>cols;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cin>>map[i][j];
            f[i][j] = 1;
        }
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            dfs(j, i, 1);//x为列col，y为行row
        }
    }
    int ans = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}