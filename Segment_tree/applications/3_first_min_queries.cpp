#include<bits/stdc++.h>
using namespace std;

struct node{
    int maxm;

    node(int _maxm=-1){
        maxm = _maxm;
    }
};

int n,q;
vector<int> arr;
vector<node> tree;


node merge(node a, node b){
    return node(max(a.maxm, b.maxm));
}

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

int query(int index, int l, int r, int val){
    if(tree[index].maxm<val){
        return 0;
    }

    if(l==r){
        return l;
    }

    int mid = (l+r)/2;
    int left = query(2*index, l, mid, val);
    if(left!=0){
        return left;
    }else{
        return query(2*index+1, mid+1, r, val);
    }
}

void update(int index, int l, int r, int pos, int val){
    if(l==r){
        arr[l] -= val;
        tree[index] = node(arr[l]);
        return;
    }

    int mid = (l+r)/2;
    if(pos<=mid){
        update(2*index, l, mid, pos, val);
    }else{
        update(2*index+1, mid+1, r, pos, val);
    }

    tree[index] = merge(tree[2*index], tree[2*index+1]);
}

void solve(){
    cin>>n>>q;

    arr.resize(n+1);
    tree.resize(4*n);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(1, 1, n);

    while(q--){
        int x;
        cin>>x;

        int ind = query(1, 1, n, x);

        if(ind!=0){
            cout<<ind<<" ";
            update(1, 1, n, ind, x);
        }else{
            cout<<0<<" ";
        }
    }
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}