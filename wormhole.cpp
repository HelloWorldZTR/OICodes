#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 12 + 1;		//	What
const int HAVE_LOOP = 1;		//	The
const int HAVE_NO_LOOP = 0; 	//	Fuck
struct wormhole{				//	is this!!!!
	int x;
	int y;
}wh[MAXN];
int pairs[MAXN], nextOn[MAXN];

/*bool cmp(const wormhole &a, const wormhole &b){
	if(a.y<b.y)	return true;
	else if(a.y == b.y && a.x<b.x)	return true;
	return false;
}*/
void initarray(int pairs[]){
	for(int i=0;i<MAXN;i++){
		pairs[i]=-1;
	}
}

int judge(int n){
	for(int i = 0; i<n; i++){
		int cur = i;
		for(int j = 0; j<n; j++){
			cur = nextOn[pairs[cur]];
			if(cur == -1)
				break;
		}
		if(cur != -1)
			return HAVE_LOOP;
	}
	return HAVE_NO_LOOP;
}
int solve(int n){
	int i, sum = 0;
	for(i = 0; i<n; i++){
		if(pairs[i] == -1)
			break;
	}
	if(i >= n - 1){
		if(judge(n) == HAVE_LOOP)
			return 1;
		return 0;
	}
	for(int j = i + 1; j<n; j++){
		if(pairs[j] == -1){
			pairs[i] = j;
			pairs[j] = i;
			sum += solve(n);
			pairs[i] = pairs[j] = -1;
		}
	}
	return sum;
}
int main() {
	int N;
	//freopen("wormhole.txt","r",stdin);
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>wh[i].x>>wh[i].y;
	}
	//sort(wh, wh+N, cmp);	//sort wormholes by y and then by x
	initarray(pairs);
	initarray(nextOn);
	
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < N; j ++){
            if (wh[j].y == wh[i].y && wh[j].x > wh[i].x){
                if (nextOn[i] == -1 || wh[nextOn[i]].x > wh[j].x){
                    nextOn[i] = j;
                }
        	}
        }
    }
	cout<<solve(N)<<endl;
	
	return 0;
}
