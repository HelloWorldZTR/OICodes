#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 110;
int a[maxn], n;
string ans;

string toString(int a) {
    char temp[110];
    sprintf(temp, "%d", a);
    string res(temp);
    return res;
}

void getAns() {
    int i;
    for(i=n; i>=0; i--) {
        /*Print 系数 1或0不打印， 最后一位时=1要打印+*/
        if(a[i]==0) continue;
        //if(a[i]!=1 || i==0) {
            if(i==n && a[i]!=1) {
                if(a[i]==-1)
                    ans += "-";
                else
                    ans += toString(a[i]);
            }
            else {
                if(a[i]>1) {//+
                    ans += ("+" + toString(a[i]));
                }
                else if(a[i]<-1) {//-
                    ans += toString(a[i]);
                }
                else if(i!=n && a[i]==1){//==1 
                    ans += "+";
                    if(i==0) {
                        ans += "1";
                    }
                }
                else if(i!=n && a[i]==-1) {
                    ans += "-";
                    if(i==0) {
                        ans += "1";
                    }
                }
            }
       // }
        /*Print X*/
        if(a[i]!=0) {
            if(i>1)
                ans += ("x^" + toString(i));
            else if(i==1) 
                ans += "x";
            else 
                ;
        }
    }
}


int main() {
    cin>>n;
    int i;
    for(i=n; i>=0; i--) {
        cin>>a[i];
    }
    getAns();
    //cout<<toString(12344356);
    cout<<ans<<endl;
    return 0;
}
