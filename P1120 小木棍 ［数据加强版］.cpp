#include<iostream>
using namespace std;

const int maxn = 66;

int s[maxn], n;

int main() {
    cin>>n;
    int temp;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        cin>>temp;
        if(temp>50) {
//            n--;
            continue;
        }
        s[cnt++] = temp;
    }
    cout<<cnt<<endl;
    for(int i=0; i<cnt; i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;
}
