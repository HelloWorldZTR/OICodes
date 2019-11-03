#include<iostream>
/*
*	未使用懒更新，30%测试点TLE 
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

/*建树：arr为原值， root为当前节点， start/end 为当前区间*/
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
	
	build_tree(tree, arr, left_child  , start, mid);//建左树 
	build_tree(tree, arr, right_child , mid+1, end);//建右树 
	tree[root].sum = tree[left_child].sum + tree[right_child].sum;//记录和 
}
/*更新： root为当前节点， start/end为更新区间， k为修改时加上的值*/ 
void update(node tree[], int root, int start, int end, int k) {
	if(tree[root].l == tree[root].r) {
		if(tree[root].l>=start && tree[root].r<=end) {//更新符合条件的节点 
			tree[root].sum +=k;
		}
		return;
	}
	if(tree[root].r<start || tree[root].l>end) {//出界 
		return;
	}
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	
	update(tree, left_child , start, end, k);
	update(tree, right_child, start, end, k);
	tree[root].sum = tree[left_child].sum + tree[right_child].sum;//更新一下 
}
/*懒更新： root为当前节点， start/end为更新区间， k为修改时加上的值 
void lazy_update(node tree[], int root, int start, int end, int k) {
	if(tree[root].r<start || tree[root].l>end) {//出界 
		return;
	}else if(tree[root].l>=start && tree[root].r<=end){//可以懒更新 
		tree[root].laz += (tree[root].r - tree[root].l) * k;
		tree[root].il = true;
		return;
	}else{ //正常更新 
	int left_child = 2 * root + 1;
	int right_child = 2 * root + 2; 
	
	update(tree, left_child , start, end, k);
	update(tree, right_child, start, end, k);
	tree[root].sum = tree[left_child].sum + tree[right_child].sum;//更新一下 
	} 
}*/
/*查询： root为当前节点， start/end为查询区间*/ 
ll query(node tree[], int root, int start, int end) {
	if(tree[root].r<start || tree[root].l>end) {//出界 
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
/*懒查询： root为当前节点， start/end为查询区间 
ll lazy_query(node tree[], int root, int start, int end) {
	if(tree[root].r<start || tree[root].l>end) {//出界 
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
			update(tr, 0, x-1, y-1, k);//无奈，区间写成了0~n-1格式 
		}
		if(temp == 2) {
			cin>>x>>y;
			ans = query(tr, 0, x-1, y-1);//懒得改了 
			cout<<ans<<endl;
		}
	}
	
	return 0;
}

