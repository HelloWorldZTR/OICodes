#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 350 + 2;
const int maxcard = 40 + 2;

int map[maxn], f[maxcard][maxcard][maxcard][maxcard], laststep[maxcard][maxcard][maxcard][maxcard];
int n, m, c1, c2, c3, c4;
/*需要一个记录上一步位置的数组laststep*/
int max4(int a, int b, int c, int d) {
    if(a==b && b==c && c==d && d==-1) {
        return 0;
    }
    int m = max(max(max(a, b), c), d);
    if(m==a)
        return 1;
    else if(m==b)
        return 2;
    else if(m==c)
        return 3;
    else 
        return 4;
}

int main() {
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>map[i];
    }
    int temp;
    for(int i=1; i<=m; i++) {//统计手上牌的个数
        cin>>temp;
        switch (temp)
        {
        case 1:
            c1++;
            break;
        case 2:
            c2++;
            break;
        case 3:
            c3++;
            break;
        case 4:
            c4++;
            break;
        default:
            break;
        }
    }
    memset(f, map[1], sizeof(f));//无论在什么情况下，都可以取到第一个
    for(int ic1 = 0; ic1<=c1; ic1++) 
        for(int ic2=0; ic2<=c2; ic2++) 
            for(int ic3=0; ic3<=c3; ic3++) 
                for(int ic4=0; ic4<=c4; ic4++) {
                    laststep[ic1][ic2][ic3][ic4] = 1;
                    f[ic1][ic2][ic3][ic4] = map[1];
                } 
    for(int ic1 = 0; ic1<=c1; ic1++) {
        for(int ic2=0; ic2<=c2; ic2++) {
            for(int ic3=0; ic3<=c3; ic3++) {
                for(int ic4=0; ic4<=c4; ic4++) {
                    /*
                    cout<<" ic1: "<<ic1<<" ic2: "<<ic2<<" ic3:"<<ic3<<" ic4:"<<ic4<<endl;
                    cout<<laststep[ic1][ic2][ic3][ic4]<<endl;
                    */
                    int ansa = -1;
                    int ansb = -1;
                    int ansc = -1;
                    int ansd = -1;
                    if(ic1>0) {//有的牌没有，不能计算，会出界
                        ansa = f[ic1-1][ic2][ic3][ic4] + map[laststep[ic1-1][ic2][ic3][ic4]+1];
                    }
                    if(ic2>0) {
                        ansb = f[ic1][ic2-1][ic3][ic4] + map[laststep[ic1][ic2-1][ic3][ic4]+2];
                    }
                    if(ic3>0) {
                        ansc = f[ic1][ic2][ic3-1][ic4] + map[laststep[ic1][ic2][ic3-1][ic4]+3];
                    }
                    if(ic4>0) {
                        ansd = f[ic1][ic2][ic3][ic4-1] + map[laststep[ic1][ic2][ic3][ic4-1]+4];
                    }
                    int m = max4(//求最佳出牌方案
                        ansa,
                        ansb,
                        ansc,
                        ansd
                    );
                    switch (m)
                    {
                    case 1:
                        f[ic1][ic2][ic3][ic4] = ansa;
                        laststep[ic1][ic2][ic3][ic4] = laststep[ic1-1][ic2][ic3][ic4]+1;
                        break;
                    case 2:
                        f[ic1][ic2][ic3][ic4] = ansb;
                        laststep[ic1][ic2][ic3][ic4] = laststep[ic1][ic2-1][ic3][ic4]+2;
                        break;
                    case 3:
                        f[ic1][ic2][ic3][ic4] = ansc;
                        laststep[ic1][ic2][ic3][ic4] = laststep[ic1][ic2][ic3-1][ic4]+3;
                        break;
                    case 4:
                        f[ic1][ic2][ic3][ic4] = ansd;
                        laststep[ic1][ic2][ic3][ic4] = laststep[ic1][ic2][ic3][ic4-1]+4;
                        break;
                    default:
                        break;
                    }
                    /*
                    cout<<"M::"<<m<<"**"<<endl,
                    cout<<"ans::"<<f[ic1][ic2][ic3][ic4]<<endl,
                    cout<<"laststep"<<laststep[ic1][ic2][ic3][ic4]<<endl<<"__________________________"<<endl;
                    */
                }
            }
        }
    }
    cout<<f[c1][c2][c3][c4]<<endl;
    return 0;
}