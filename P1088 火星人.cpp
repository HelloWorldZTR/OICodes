#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 10010;
int now[maxn], num[maxn];
bool vis[maxn], OK, readyToKill;
int n, m;long long cnt;
bool check() {
//    bool flag = true;
    for(int i=1; i<=n; i++) {
        if(num[i]!=now[i])
            return false;
    }
    return true;
}
void printAns() {
    for(int i=1; i<n; i++) {
        cout<<now[i]<<" ";
    }
    cout<<now[n]<<endl;
}
void getP(int cur) {
    if(readyToKill) return;
    if(cur>n) {
        if(!OK) {
            if(check()) {
                OK = true;
/*                if(m==1) {
                    cnt--;
                }
                else if(m==0) {
                    printAns();
                    readyToKill = true;
                    return;
                }*/
            }
        }
        else {
            if(++cnt == m) {
                printAns();
                readyToKill = true;
            }
        }
    }
    else {
        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                vis[i] = true;
                now[cur] = i;
                getP(cur + 1);
                vis[i] = false;
            }
        }
    }
}
int main() {
    memset(vis, 0, sizeof vis);
    cin>>n>>m;
    int i;
    for(i=1; i<=n; i++) {
        cin>>num[i];
        now[i] = 0;
    }
    getP(1);
    return 0;
}
