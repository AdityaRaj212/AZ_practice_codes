#include<bits/stdc++.h>
#define int long long

using namespace std;

struct node{
    int odd;
    int even;
    node(int _odd=0, int _even=0){
        odd = _odd;
        even = _even;
    }
};

int n,q;
vector<int> arr;
vector<node> tree;


node merge(node a, node b){
    return node(a.odd+b.odd, a.even+b.even);
}

void build(int index, int l, int r){
    if(l==r){
        tree[index] = node((arr[l]%2==1), (arr[l]%2==0));
        return;
    }

    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
    tree[index] = merge(tree[2*index],tree[2*index+1]);
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

void update(int index, int l, int r, int pos, int val){
    if(pos<l || pos>r){
        return;
    }

    if(l==r){
        if(val%2){
            // odd
            tree[index] = node(1,0);
        }else{
            tree[index] = node(0,1);
        }
    }else{
        int mid = (l+r)/2;
        if(pos<=mid){
            update(2*index, l, mid, pos, val);
        }else{
            update(2*index+1, mid+1, r, pos, val);
        }
        tree[index] = merge(tree[2*index], tree[2*index+1]);
    }
}

void solve(){
    cin>>n;

    arr.resize(n+1);
    tree.resize(4*n);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    build(1, 1, n);

    cin>>q;
    while(q--){
        int ch;
        cin>>ch;

        if(ch==0){
            int pos, val;
            cin>>pos>>val;
            update(1, 1, n, pos, val);
        }else if(ch==1){
            int l, r;
            cin>>l>>r;

            auto node_ = query(1, 1, n, l, r);
            cout<<node_.even<<endl;
        }else{
            int l, r;
            cin>>l>>r;

            auto node_ = query(1, 1, n, l, r);
            cout<<node_.odd<<endl;
        }
    }
}

signed main(){
    solve();
    return 0;
}