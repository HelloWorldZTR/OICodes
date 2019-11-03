#include<iostream>
using namespace std;
char c[355];
int Next[355];
int Prev[355];
int MAX=-9999999;
bool eql(char a,char b){
if(a=='w'||b=='w'){

//cout<<a<<" eql "<<b<<endl;
return true;
}
if(a==b){

//cout<<a<<"eql"<<b<<endl;
return true;
}
return false;
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        //cin>>c[i];
        c[i]=s[i];
        //cout<<c[i];
        Next[i]=i+1;
        Prev[i]=i-1;
    }
    //cout<<"done";
    Next[n-1]=0;
    Prev[0]=n-1;

    for(int i=0;i<n;i++){
        int count=2;
        int l=Prev[i];
        //int now=i;
        int r=i;
        char nowColA=c[l],nowColB=c[r];
        int lb=l,rb=r;
        int contb=0;
        while(nowColA=='w'||nowColB=='w'){
        if(nowColA=='w') {nowColA=c[Prev[lb]];lb=Prev[lb];contb++;}
        if(nowColB=='w') {nowColB=c[Next[rb]];rb=Next[rb];contb++;}
        if(contb>=n){
            cout<<n<<endl;
            return 0;
        }
        }
        while(true){//
            if(    (eql(nowColB,c[Next[r]]))   ||    (eql(nowColA,c[Prev[l]]))  && l!=r){
                //cout<<nowColA<<"   "<<nowColB<<endl;
                if(eql(nowColA,c[Prev[l]])&&!(count>=n)){
                    l=Prev[l];
                    count++;
                }
                if(eql(nowColB,c[Next[r]])&&!(count>=n)){
                    r=Next[r];
                    count++;
                }
                if(count>=n)   { break;}
            }
            else
            {
               // cout<<i<<"              "<<count<<endl;
                break;
            }
            //if(!(eql(nowColB,c[Next[r]]))&&!(eql(nowColA,c[Prev[l]]))&&r<=l)    break;
        }
        if(count>MAX)   MAX=count;
    }
    cout<<MAX<<endl;
    return 0;
}