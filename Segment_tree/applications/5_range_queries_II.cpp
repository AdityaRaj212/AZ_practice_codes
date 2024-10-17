#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;

    node(int _val = 0){
        val = _val;
    }
};

int n,q;
vector<int> arr;
vector<node> tree;

void build(int index, int l, int r){
    if(l==r){
        tree[index] = node(arr[l]);
        return;
    }

    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    tree[index] = merge(tree[2*index], tree[2*index+1]);
}

void update(int index, int l, int r, int posl, int posr, int val){
    if(posl<=l && posr>=r){
        
    }
}

void solve(){

}

signed main(){
    solve();
    return 0;
}