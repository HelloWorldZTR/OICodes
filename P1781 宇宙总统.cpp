#include<iostream>
using namespace std;

const int maxn = 22;
const int maxw = 110;

int m[maxw], nowmax=0, nowans, n; 
string ans = "";

int main() {
	cin>>n;
	int i, j;string tmp;
	for(i=0; i<n; i++) {
		cin>>tmp;
		int tlen = tmp.length() - 1;
		//Case 1:��ǰ����֪���� 
		if(tmp.length()>nowmax)	 {
			nowmax = tmp.length();
			nowans = i + 1;
			ans = tmp;
			//������֪ 
			for(j=0; j<tmp.length(); j++) {
				m[j] = max(m[j], tmp[tlen - j] - '0');
			}
		}
		//Case 2����ǰ����֪�ȳ� 
		else if(tmp.length()==nowmax) {
			bool needChange = false;
			for(j=nowmax-1; j>=0; j--) {
				if(m[j]>tmp[tlen - j]-'0') {
					needChange = false;
					break;
				}
				else if(m[j]<tmp[tlen - j]-'0') {
					needChange = true;
					break;
				}
			}
			//������֪ 
			if(needChange)	{
				nowans = i + 1;
				ans = tmp; 
				for(j=0; j<tmp.length(); j++) {
					m[j] = max(m[j], tmp[tlen - j] - '0');
				}
			}
		}
	}
	cout<<nowans<<endl;
	cout<<ans<<endl;
	return 0;
}
