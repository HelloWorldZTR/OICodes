#include<iostream>
#include<algorithm>
using namespace std;
struct Time
{
    int starttime;
    int endtime;
    int value;
    Time *next;
}t[5005];
bool cmp(const Time &a,const Time &b){
    if(a.starttime<b.starttime) return true;
    else return false;
}
void catTime(Time &a,Time &b){//a.starttime>b.starttime
    a.endtime=b.endtime;
    a.value=a.endtime-a.starttime;
    a.next=b.next;
}
int main(){
    int n;
    cin>>n;
    int start,end;
    for(int i=0;i<n;i++){
        cin>>start>>end;
        t[i].starttime=start;
        t[i].endtime=end;
        t[i].value=end-start;
        t[i].next=NULL;
    }
    sort(t,t+n,cmp);
    Time *head;
    head=t;
    for(int i=0;i<n;i++){
        t[i].next=&t[i+1];
        cout<<i<<"::::"<<t[i].starttime<<" "<<t[i].endtime<<endl;
    }
    t[n-1].next=NULL;
/*    Time *now2=head;                                                                                                                                                                                  个别情况有点用
    while((*now2).next!=NULL){
            if((*now2).endtime<=(*now2->next).endtime     &&      (*now2).starttime<=(*now2->next).endtime){
                //如果有交集
                catTime(*now2,(*now2->next));//整合，next！！！
            }
            now2=now2->next;
    } */
    int count=0;
    Time *lastCat;                                                                                                                                                                                                      //雕用没有
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(t[i].starttime>=t[j].starttime     &&      t[i].starttime<=t[j].endtime && i!=j && t[i].endtime>=t[j].endtime){
                //如果有交集
                (*lastCat).next=&t[i];
                catTime(t[i],t[j]);//整合，next！！！
                lastCat=&t[i];
                count++;
                cout<<"cating"<<i<<"and"<<j<<endl;
            }
        }
    }


    if(count==0)    (*head).next=NULL;
    Time *now=head;
    int max=-999999;
    int min=-999999;
    while((*now).next!=NULL){
        if((*now).value>max)  max=(*now).value;//查找最大。。。。
        cout<<(*now).endtime<<"~"<<(*now->next).starttime<<endl;
        if((*now->next).starttime-(*now).endtime>min)    min=(*now->next).starttime-(*now).endtime;//查找最小，因为已经合并所有交集，所以可行（对么）
        now=now->next;
        break;
    }
    if(max<0||min<0)    cout<<(*head).value<<" "<<0<<endl;//只有一个
    else    cout<<max<<" "<<min<<endl;
    return 0;
}

