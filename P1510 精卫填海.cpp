#include<iostream> 
using namespace std;
/*��С01������ʣ��*/
const int MAXK = 10001;
int v, n, c, f[20010], ans = 233333;

int main() {
	cin>>v>>n>>c;
	for(int i=1; i<=v+MAXK; i++)
		f[i] = 1e9;//����С������� 
	int k, m;
	for(int i=1; i<=n; i++){
		cin>>k>>m;
		for(int j=v+MAXK; j>=k; j--){
			f[j] = min(f[j], f[j-k]+m);
		}
	}
	for(int i=v;i<=v+MAXK;i++)//���ѭ�����Է�������ѭ���� 
		ans = min(ans, f[i]);//�����з��������ķ�Χ������С 
	ans = c - ans; 
	if(ans < 0)
		cout<<"Impossible";
	else
		cout<<ans;
	cout<<endl;
	return 0;
}
