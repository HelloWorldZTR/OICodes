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
int main(){
    int  n,s,count=0;
    cin>>n>>s;
    //char a[20];
    int flag=0;
    while(count<n){
        s++;
        flag=0;
        //sprintf(a,"%d",s);
        for(int i=2;i<=10;i++){
            trans(i,s);//将s转换为i进制，存储在c数组（char）
            if(isMirrored(c,len)){
                 flag++;
                 if(flag>=2)    break;
            }
        }
        if(flag>=2){
            cout<<s<<endl;
            count++;
        }
    }
    return 0;
}