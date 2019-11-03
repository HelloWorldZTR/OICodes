#include<bits/stdc++.h>
using namespace std;
const int maxn = 100100;
struct person {
    int id;
    int s;
    int w;
    //person(int id, int s, int w) : id(id), s(s), w(w){}
};
bool cmp(person a, person b) {
    if(a.s<b.s) {
        return true;
    }
    else if(a.s>b.s) {
        return false;
    }
    else {
        return a.id<b.id;
    }
}
int n, r, q; 
person persons[maxn];
/*void go(int round) {
    int i;
    if(round<r) {
        sort(persons, persons+n, cmp);
        for(i=1; i<=2*n; i+=2) {
            person& a = persons[i-1];
            person& b = persons[i];
            if(a.w>b.w) {
                a.s++;
            }
            else {
                b.s++;
            }
        }
        go(round+1);
    }
}*/
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>r>>q;
    int i, temp;
    for(i=0; i<2*n; i++) {
        persons[i].id = i;
        cin>>persons[i].s;
    }
    for(i=0; i<2*n; i++) {
        cin>>persons[i].w;
    }
    //go(0);
    for(i=0; i<r; i++) {
        sort(persons, persons+n, cmp);
        for(temp=1; temp<=2*n; temp+=2) {
            person& a = persons[i-1];
            person& b = persons[i];
            if(a.w>b.w) {
                a.s++;
            }
            else {
                b.s++;
            }
        }
    }
    cout<<persons[q].id+1<<endl;
    return 0;
}

