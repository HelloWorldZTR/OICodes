#include<bits/stdc++.h>
using namespace std;

bool check[125010];

struct answer{
	int a;
	int b;
} ans[10010];

bool cmp(answer an, answer bn){
	if(an.b<bn.b)
		return true;
	else if(an.b == bn.b && an.a<bn.a)
		return true;
	else
		return false;
}

int main() {
    int n, m;
    //freopen("ari.txt", "r", stdin);
    cin>>n>>m;
    //init
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= m; j++){
			check[i*i+j*j] = 1;
		}
	}
	//init
    //start
    int limit = 2*m*m, count = 0;
    for(int i = 0;i<=limit;i++) {			//枚举出序列的前两个数 
    	if(check[i])						//<--他们必须是双平方数 
    	for(int j = i+1;j<=limit;j++){		// 
    		if(check[j]){					//——同上—— 
    			int gongcha	= j - i;				//共差
    			int lastone = i + gongcha * (n - 1);//最后一个
				if (lastone > limit)
					break;					//共差太大了
					
				bool flag = true;
				for(int xulie = j + gongcha; xulie <= lastone; xulie+=gongcha){
					if(!check[xulie]){		//枚举序列（从前面算好的第二个开始， 
						flag = false ;		//到最后一个结束）节约一点效率 
						break;
					}
				} 
				if(flag){
					ans[count].a = i;
					ans[count].b = gongcha;
					count++;
				} 
    		}
    	}
    } 
    if(count==0){
    	cout<<"NONE"<<endl;
    	return 0;
    }
    sort(ans, ans+count, cmp);
    for(int i=0;i<count;i++){
    	cout<<ans[i].a<<" "<<ans[i].b<<endl;
    }
    return 0;
}		
