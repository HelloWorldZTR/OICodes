#include<iostream>
#include<cstring>
using namespace std;
char in[11][11];
char out[11][11];
char c[11][11];
char tmp[11][11];
void print(int n){
    for(int i=0;i<n;i++){
         for(int m=0;m<n;m++){
             cout<<tmp[i][m];
            }
            cout<<endl;
        }
}
void init(int n){
    for(int i=0;i<n;i++){
        for(int m=0;m<n;m++){
           tmp[i][m]=in[i][m];
        }
    }
    return;
}
void cpy(int n){
    for(int i=0;i<n;i++){
        for(int m=0;m<n;m++){
           tmp[i][m]=c[i][m];
        }
    }
    return;
}
bool cmp(int n){
    for(int i=0;i<n;i++){
            for(int m=0;m<n;m++){
                if(tmp[i][m]!=out[i][m])  return false;
            }
    }
    return true;
}
void turn90(int n){
    for(int i=n-1,x=0;i>0,x<n;i--,x++){
        for(int m=0;m<n;m++){
            c[m][i]=tmp[x][m];
        }
    }
    cpy(n);
    return;
}
void turn180(int n){
    turn90(n);
    turn90(n);
}
void turn270(int n){
    turn90(n);
    turn90(n);
    turn90(n);
}
void reflex(int n){
    for(int i=0;i<n;i++){
        for(int m=0;m<n;m++){
            c[i][n-m-1]=tmp[i][m];
        }
    }
    cpy(n);
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int m=0;m<n;m++){
            cin>>in[i][m];
        }
    }
    for(int i=0;i<n;i++){
        for(int m=0;m<n;m++){
            cin>>out[i][m];
        }
    }
    init(n);
    //reflex(n);
    //print(n);
    turn90(n);
    if(cmp(n))  {cout<<"1"<<endl;return 0;}
    init(n);
    turn180(n);
    if(cmp(n))  {cout<<"2"<<endl;return 0;}
    init(n);
    turn270(n);
    if(cmp(n))  {cout<<"3"<<endl;return 0;}
    init(n);
    reflex(n);
    if(cmp(n))  {cout<<"4"<<endl;return 0;}
    init(n);
    reflex(n);
    turn90(n);
    if(cmp(n))  {cout<<"5"<<endl;return 0;}
    init(n);
    reflex(n);
    turn180(n);
    if(cmp(n))  {cout<<"5"<<endl;return 0;}
    init(n);
    reflex(n);
    turn270(n);
    if(cmp(n))  {cout<<"5"<<endl;return 0;}
    init(n);
    if(cmp(n))  {cout<<"6"<<endl;return 0;}
    cout<<"7"<<endl;
    return 0;
}