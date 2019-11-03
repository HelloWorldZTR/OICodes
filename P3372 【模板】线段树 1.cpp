#include<iostream>
/*
*	δʹ�������£�30%���Ե�TLE 
*/
using namespace std;

typedef long long ll;

struct node{
	int l;
	int r;
	ll sum;
}; 
ll arr[100000];
node tr[100000*4];

/*������arrΪԭֵ�� rootΪ��ǰ�ڵ㣬 start/end Ϊ��ǰ����*/
void build_tree(node tree[], ll arr[], int root, int start, int end) {
	tree[root].l = start;
	tree[root].r = end;
	if(start == end) {
		tree[root].sum = arr[start];
		return;
	}
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	int mid = (start + end) /2;
	
	build_tree(tree, arr, left_child  , start, mid);//������ 
	build_tree(tree, arr, right_child , mid+1, end);//������ 
	tree[root].sum = tree[left_child].sum + tree[right_child].sum;//��¼�� 
}
/*���£� rootΪ��ǰ�ڵ㣬 start/endΪ�������䣬 kΪ�޸�ʱ���ϵ�ֵ*/ 
void update(node tree[], int root, int start, int end, int k) {
	if(tree[root].l == tree[root].r) {
		if(tree[root].l>=start && tree[root].r<=end) {//���·��������Ľڵ� 
			tree[root].sum +=k;
		}
		return;
	}
	if(tree[root].r<start || tree[root].l>end) {//���� 
		return;
	}
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	
	update(tree, left_child , start, end, k);
	update(tree, right_child, start, end, k);
	tree[root].sum = tree[left_child].sum + tree[right_child].sum;//����һ�� 
}
/*�����£� rootΪ��ǰ�ڵ㣬 start/endΪ�������䣬 kΪ�޸�ʱ���ϵ�ֵ 
void lazy_update(node tree[], int root, int start, int end, int k) {
	if(tree[root].r<start || tree[root].l>end) {//���� 
		return;
	}else if(tree[root].l>=start && tree[root].r<=end){//���������� 
		tree[root].laz += (tree[root].r - tree[root].l) * k;
		tree[root].il = true;
		return;
	}else{ //�������� 
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	
	update(tree, left_child , start, end, k);
	update(tree, right_child, start, end, k);
	tree[root].sum = tree[left_child].sum + tree[right_child].sum;//����һ�� 
	} 
}*/
/*��ѯ�� rootΪ��ǰ�ڵ㣬 start/endΪ��ѯ����*/ 
ll query(node tree[], int root, int start, int end) {
	if(tree[root].r<start || tree[root].l>end) {//���� 
		return 0;
	}else if(tree[root].l>=start && tree[root].r<=end){
		return tree[root].sum;
	}
	ll ans = 0;
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	ans += query(tree, left_child , start, end);
	ans += query(tree, right_child, start, end);
	return ans;
}
/*����ѯ�� rootΪ��ǰ�ڵ㣬 start/endΪ��ѯ���� 
ll lazy_query(node tree[], int root, int start, int end) {
	if(tree[root].r<start || tree[root].l>end) {//���� 
		return 0;
	}else if(tree[root].l>=start && tree[root].r<=end){
		if(tree[root].il){
			return tree[root].sum + tree[root].laz;
		}else{
			return tree[root].sum;
		}
	}
	ll ans = 0;
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	ans += lazy_query(tree, left_child , start, end);
	ans += lazy_query(tree, right_child, start, end);
	return ans;
}*/
int main() {
	/*ll arr[1000] = {1, 5, 4, 2, 3};
	build_tree(tr, arr, 0, 0, 4);
	update(tr, 0, 0, 1, 1);
	for(int i=0; i<9; i++) {
		cout<<tr[i].sum<<endl;
	}
	cout<<endl<<query(tr, 0, 0, 3)<<endl;*/ 
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	} 
	build_tree(tr, arr, 0, 0, n-1);
	int temp, x, y, k;
	ll ans = 0;
	for(int i=0; i<m; i++) {
		cin>>temp;
		if(temp == 1) {
			cin>>x>>y>>k;
			update(tr, 0, x-1, y-1, k);//���Σ�����д����0~n-1��ʽ 
		}
		if(temp == 2) {
			cin>>x>>y;
			ans = query(tr, 0, x-1, y-1);//���ø��� 
			cout<<ans<<endl;
		}
	}
	
	return 0;
}

