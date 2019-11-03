#include<iostream>
using namespace std;
const int maxn = 55;
const int maxyz = 2000010;
int f[maxyz];
int a[maxn];
int n, k;
int main() {
    cin>>k>>n;
    register int i;
    int maxnum;
    for(i=1; i<=n; i++) {
        cin>>a[i];
        maxnum = max(a[i], maxnum);
    }
    register int j;
    int limit = k * maxnum;
    for(j=1; j<=limit; j++) {
        f[j] = 233333;
    }
    for(i=0; i<=limit; i++) {
        for(j=1; j<=n; j++) {
            f[i+a[j]] = min(f[i+a[j]], f[i]+1);
        }
    }
    //for(j=1; j<=limit&&f[j]<=k; j++);
    j=1;
    while(j<=limit&&f[j]<=k)    j++;
    cout<<j-1<<endl;
    return 0;
}

