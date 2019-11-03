/*
This Program Has Been Accepted
 */
#include<iostream>
using namespace std;
int np;
struct person
{
    /* data */
    string  name;
    int money;
}p[15];
int serch_person(string name){
    for(int i=0;i<np;i++){
        if(p[i].name.compare(name)==0)  return i;
    }
    return -1;
}
int main(){
    
    cin>>np;
    for(int i=0;i<np;i++){
        cin>>p[i].name;
    }
    for(int i=0;i<np;i++){
        string name;
        cin>>name;
        int money,givers;
        cin>>money>>givers;
        if(givers!=0)        p[serch_person(name)].money+=money%givers-money;//剩下的
        for(int i=1;i<=givers;i++){
            string giver_name;
            cin>>giver_name;
            p[serch_person(giver_name)].money+=money/givers;
        }
    }
    for(int i=0;i<np;i++){
        cout<<p[i].name<<" "<<p[i].money<<endl;
    }
    return 0;
}