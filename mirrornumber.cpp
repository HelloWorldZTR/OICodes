#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//const int NUM=100;
char c[1000];
int len=0;
bool isMirrored(char a[],int n){
    int l=0,r=n-1;
    while(l!=r){
        if(a[l]!=a[r])  return false;
        if(l+1<r)l++;
        r--;
    }
    return true;
}
void trans(int mod,int num){
    int n=0;//11
    int shang=num;//11
    int x=0;
    while(shang!=0){
        n=shang%mod;//1,1,0
        shang=shang/mod;//5,2
        if(n>9)     c[x]='A'+(n-10);
        else c[x]=n+'0';
        x++;
    }
    len=x;
    return;
}
void print(){
    for(int i=len-1;i>=0;i--){
        cout<<c[i];
    }
}
int main(){
    int b;
    cin>>b;
    for(int i=1;i<=300;i++){
        int tmp=i*i;
        trans(b,tmp);
        if(isMirrored(c,len)){
            trans(b,i);
            print();
            cout<<" ";
            trans(b,tmp);
            print();
            cout<<endl;
        }
    }
    //sprintf(a,"%d",b);
    //trans(2,11);
    ///for(int i=0;i<len;i++){
     //   cout<<c[i];
    //}
    //cout<<isMirrored(a,n)<<endl;
    return 0;
}