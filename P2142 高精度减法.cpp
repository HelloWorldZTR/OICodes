#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 10100;
char a[maxn], b[maxn];
int a2[maxn], b2[maxn], c2[maxn];
int cmp() {
    int i;
    if(strlen(a)>strlen(b)) {
        return 2;
    }
    else if(strlen(b)>strlen(a)) {
        return 1;
    }
    else {
        for(i=0; i<strlen(a); i++) {
            if(a[i]-'0'<b[i]-'0') {
                return 1;
            }
            if(a[i]-'0'>b[i]-'0') {
                return 2;
            }
        }
        return 0;
    }
    return 0;
}
void swapab() {
    int i;
    for(i=0; i<strlen(a); i++) {
        c2[i] = a2[i];
    }
    memset(a2, 0, sizeof a2);
    for(i=0; i<strlen(b); i++) {
        a2[i] = b2[i];
    }
    memset(b2, 0, sizeof b2);
    for(i=0; i<strlen(a); i++) {
        b2[i] = c2[i];
    }
    memset(c2, 0, sizeof c2);
}
int main() {
    cin>>a;
    cin>>b;
    int strlena = strlen(a);
    int strlenb = strlen(b);
    int i;
    for(i=0; i<strlena; i++) {
        a2[i] = a[strlena - i - 1] - '0';
    }
    for(i=0; i<strlenb; i++) {
        b2[i] = b[strlenb - i - 1] - '0';
    }
    bool isFushu = false;
    switch(cmp()) {
        case 1:
            isFushu = true;
            swapab();
            swap(strlena, strlenb);
            break;
        case 0:
            cout<<0<<endl;
            return 0;
        case 2:
            isFushu = false;
            break;
    }
    if(isFushu)
        cout<<'-';
    /*
    for(i=0; i<strlena; i++) {
        cout<<a2[i];
    }cout<<endl;
    for(i=0; i<strlenb; i++) {
        cout<<b2[i];
    }cout<<endl;
    */
    int tot = max(strlena, strlenb);
    int jiewei = 0;
    for(i=0; i<tot; i++) {
        c2[i] = a2[i] - b2[i] - jiewei;
        //cout<<"c2["<<i<<"] is "<<c2[i]<<endl;
        if(c2[i]<0) {
            jiewei = 1;
            c2[i] = 10 + c2[i];
        //    cout<<"And now it's "<<c2[i]<<endl;
        }
        else {
            jiewei = 0;
        }
    }
    bool notOK = true;
    for(i=tot-1; i>=0; i--) {
        if(notOK) {
            if(c2[i]!=0) {
                notOK = false;
            }
            else continue;
        }
        cout<<c2[i];
    }
    cout<<endl;
    return 0;
}
