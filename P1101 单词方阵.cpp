#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 110;
char scr[maxn][maxn], ans[maxn][maxn],
     tmp[10], cmp[] = "yizhong@@@@@@@@@";
int n;

void check(int y, int x) {
    bool flag = true;
    int i, j;
    if(x+6>n) {
        flag = false;
    }
    if(flag)
        for(i=x; i<=x+6; i++) {
           if(scr[y][i]!=cmp[i-x]) {
                 flag = false;
                 break;
             }
         }
    if(flag) {
        for(i=x; i<=x+6; i++) {
            ans[y][i] = scr[y][i];
        }
    }
    flag = true;
    if(x-6<0)   flag = false;
    if(flag)
        for(i=x; i>=x-6; i--) {
            if(scr[y][i]!=cmp[(x-i)]) {
                flag = false;
                break;
            }
        }
    if(flag) {
        for(i=x; i>=x-6; i--) {
            ans[y][i] = scr[y][i];
        }
    }
    flag = true;
    if(y-6<0)   flag = false;
    if(flag) 
        for(i=y; i>=y-6; i--) {
            if(scr[i][x]!=cmp[y-i]) {
                flag = false;
                break;
            }
        }
    if(flag)
        for(i=y; i>=y-6; i--) {
            ans[i][x] = scr[i][x];
        }
    flag = true;
    if(y+6>n)   flag = false;
    if(flag) 
        for(i=y; i<=y+6; i++) {
            if(scr[i][x]!=cmp[i-y]) {
                flag = false;
                break;
            }
        }
    if(flag)
        for(i=y; i<=y+6; i++) {
            ans[i][x] = scr[i][x];
        }
    flag = true;
    if(x+6>n || y+6>n)  flag = false;
    if(flag) 
        for(i=0; i<=6; i++) {
            if(scr[y+i][x+i] != cmp[i]) {
                flag = false;
                break;
            }
        }
    if(flag) 
        for(i=0; i<=6; i++) {
           ans[y+i][x+i] = scr[y+i][x+i]; 
        }
    flag = true;
    if(x+6>n || y-6<0)  flag = false;
    if(flag)
        for(i=0; i<=6; i++) {
            if(scr[y-i][x+i]!=cmp[i]) {
                flag = false;
                break;
            }
        }
    if(flag) 
        for(i=0; i<=6; i++) {
            ans[y-i][x+i] = scr[y-i][x+i];
        }
    flag = true;
    if(x-6<0 || y-6<0)  flag = false;
    if(flag)
        for(i=0; i<=6; i++) {
            if(scr[y-i][x-i]!=cmp[i]) {
                flag = false;
                break;
            }
        }
    if(flag)
        for(i=0; i<=6; i++) {
            ans[y-i][x-i] = scr[y-i][x-i];
        }
    flag = true;
    if(x-6<0 || y+6>n)  flag = false;
    if(flag)
        for(i=0; i<=6; i++) {
            if(scr[y+i][x-i]!=cmp[i]) {
                flag = false;
                break;
            }
        }
    if(flag)
        for(i=0; i<=6; i++) {
            ans[y+i][x-i] = scr[y+i][x-i];
        }
}


int main() {
    cin>>n;
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin>>scr[i][j];
        }
    }
    memset(ans, '*', sizeof(ans));
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(scr[i][j]=='y') {
                check(i, j);
            }
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}
