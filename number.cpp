/*
    This Program has Been Accepted
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int NUMM=15;
string dic[4700];                       // The Defalut Value Is
int dic_[4700][NUMM];          //All 0,Or There will be
int num[NUMM];                      //some undefine
char numc[NUMM];                //——ZTR
void format(){
    for(int i=0;i<4617;i++){
        for(int n=0;n<dic[i].length();n++){
            if(dic[i][n]>='A'&&dic[i][n]<='C')  dic_[i][n]=2;
            else if(dic[i][n]>='D'&&dic[i][n]<='F')  dic_[i][n]=3;
            else if(dic[i][n]>='G'&&dic[i][n]<='I')  dic_[i][n]=4;
            else if(dic[i][n]>='J'&&dic[i][n]<='L')  dic_[i][n]=5;
            else if(dic[i][n]>='M'&&dic[i][n]<='O')  dic_[i][n]=6;
            else if(dic[i][n]>='P'&&dic[i][n]<='S')  dic_[i][n]=7;
            else if(dic[i][n]>='T'&&dic[i][n]<='V')  dic_[i][n]=8;
            else      dic_[i][n]=9;
           //cout<<dic[i][n]<<"  "<<dic_[i][n];
        }
        //cout<<endl;
    }
}
bool cmp(int a[],int b[]){
    for(int i=0;i<NUMM;i++){
        if(a[i]!=b[i])  return false;
    }
    return true;
}
int main(){
    scanf("%s",numc);
    for(int i=0;i<NUMM;i++){
        if(numc[i]!='\0')
        num[i]=numc[i]-'0';
        else num[i]=0;
        
        //cout<<num[i];
    }
    for(int i=0;i<4617;i++){
        cin>>dic[i];
    }
    format();
    //print_dic();
    //sscanf(numc,"%d",num);
    int count=0;
    for(int i=0;i<4617;i++){
        int tmp[NUMM];
        for(int n=0;n<NUMM;n++)   tmp[n]=dic_[i][n];
        //for(int n=0;n<NUMM;n++)   cout<<dic_[i][n];
       // cout<<endl;
        if(cmp(tmp,num)){
            cout<<dic[i]<<endl;
            count++;
        }
    }
    //for(int i=0;i<NUMM;i++)  cout<<num[i];
    if(count == 0){
        cout<<"NONE"<<endl;
    }
    return 0;
}