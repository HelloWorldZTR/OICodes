#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

const char NULL_SUB = '*';

const int maxn = 2049;//数组开大

char tree[maxn];

int string_[maxn], n;

void build_tree(int root, int from, int to) {
    //cout<<"building "<<root<<"  from "<<from<<" to "<<to<<endl;
    int left_subtree    = 2 * root;
    int right_subtree = 2 * root + 1;
    int mid = (from + to) / 2;
    if(from==to) {
        switch(string_[from]) {
            case 0:
                tree[root] = 'B';
                break;
            case 1:
                tree[root] = 'I';
                break;
        }
        tree[left_subtree] = NULL_SUB;
        tree[right_subtree] = NULL_SUB;
        return;
    }
    else{
        build_tree(left_subtree, from, mid);
        build_tree(right_subtree, mid + 1, to);
        if(tree[left_subtree]==tree[right_subtree]) {
            if(tree[left_subtree]=='B') {
                tree[root] = 'B';
            }
            else if(tree[left_subtree]=='I'){
                tree[root] = 'I';
            }
            else {
                tree[root] = 'F';
            }
        }
        else {
            tree[root] = 'F';
        }
    }
}

void print_ans(int root) {
    if(tree[root]!=NULL_SUB) {
        //cout<<"printing "<<root<<endl;
        int left_subtree = root * 2;
        int right_subtree = root * 2 + 1;
        print_ans(left_subtree);
        print_ans(right_subtree);
        putchar(tree[root]);
    }
}

int main() {
    cin>>n;
    n = pow(2, n);
    char temp;
    for(int i=0; i<n; i++) {
        //cin>>string_[i];
        cin>>temp;
        string_[i] = temp - '0';
    }
    build_tree(1, 0, n-1);
    print_ans(1);
    putchar('\n');
    return 0;
}