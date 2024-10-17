#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<node> tree;

struct node{
    int mini;
    int cnt;

    node(int _mini=1e9, int _cnt=0){
        mini = _mini;
        cnt = _cnt;
    }
};

node merge(node a, node b){
    if(a.mini==b.mini){
        return node(a.mini, a.cnt+b.cnt);
    }else if(a.mini<b.mini){
        return a;
    }else{
        return b;
    }
}

void build(int index, int l, int r){
    if(l==r){
        tree[index] = node(arr[l],1);
        return;
    }
    
    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    tree[index] = merge(tree[2*index], tree[2*index+1]);
}

node query(int index, int l, int r, int lq, int rq){
    if(lq>r || rq<l){
        return node();
    }

    if(l>=lq && r<=rq){
        return tree[index];
    }

    int mid = (l+r)/2;
    return merge(query(2*index, l, mid, lq, rq),query(2*index+1, mid+1, r, lq, rq));
}

void solve(){
    cin>>n;

    arr.resize(n);
    tree.resize(4*n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int q;
    cin>>q;

    while(q--){
        // write query logic here
    }
}

signed main(){
    solve();
    return 0;
}