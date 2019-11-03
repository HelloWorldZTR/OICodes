#include<iostream>
#include<cmath>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> used;
int main() {
    int n, r, q;
    cout<<"Please input a n"<<endl;
    cin>>n;

    cout<<"Please input a r"<<endl;
    cin>>r;

    cout<<"Please input a q"<<endl;
    cin>>q;


    freopen("P1309.in", "w", stdout);

    cout<<n<<" "<<r<<" "<<q<<endl;
    for(int i=0; i<2*n; i++)
    cout<<(int) rand()*10 << " ";
    cout<<endl;
    for(int i=0; i<2*n; i++) {
        int t = rand()*10000;
        while(find( used.begin( ), used.end( ), t )!=used.end()) {
            t = (int )rand()*10000;
        }
        used.push_back(t);
        cout<<t<<" ";
    }
    cout<<endl;
    return 0;
}




