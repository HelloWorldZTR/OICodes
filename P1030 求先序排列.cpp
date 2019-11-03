#include<iostream>
#include<cstring>

using namespace std;

string zx, hx;//中序便利，后序便利
int tree[1000];

void build(int root, int rootnum, int from, int to);//建树 中序便利（from， to）， 根为 rootnum    存储在root
int findRoot(int l, int r);//在 后序便利 中 寻找 中序便利 (l, r)子树中的根
void xxbl(int root);//输出先序便利

int main() {
    memset(tree, -1, sizeof(tree));
    cin>>zx>>hx;
    build(1, findRoot(0, zx.length()-1), 0, zx.length()-1);
    //for(int i=0; i<100; i++) {
    //    cout<<tree[i]<<" ";
    //}
    xxbl(1);
    cout<<endl;
    return 0;
}



/**
 *  函数
 */ 
void build(int root, int rootnum, int from, int to) {
    //cout<<"build "<<from<<to<<endl;
    //cout<<"root"<<rootnum<<endl;
    tree[root] = rootnum;
    int lchild = root * 2;
    int rchild = root * 2 + 1;
    //if(rootnum == from + 1 || rootnum == to -1){
        if(rootnum == from+1) {
            tree[lchild] = from;
        }
        else {
            int nextrootnum = findRoot(from, rootnum-1);
            if(nextrootnum!=-1)
            build(lchild, nextrootnum, from, rootnum-1);
        }
        if(rootnum == to-1) {
            tree[rchild] = to;
        }
        else {
            int nextrootnum = findRoot(rootnum+1, to);
            if(nextrootnum!=-1)
            build(rchild, nextrootnum, rootnum+1, to);
        }
 //   }
}
int findRoot(int l, int r) {
    int root = -1;
    int maxa = -10;
    for(int i=l; i<=r; i++) {
        if((int)hx.find(zx[i])>maxa) {
            maxa = (int)hx.find(zx[i]);
            root = i;
        }
    }
    return root;
}
void xxbl(int root) {
    int lchild = root * 2;
    int rchild = root * 2 + 1;
    if(tree[root]!=-1) {
        cout<<zx[tree[root]];
    }else
    {
        return;
    }
    
    xxbl(lchild);
    xxbl(rchild);
}
