#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,q;
vector<int> arr, tree;

void build(int index, int l, int r){
    if(l==r){
        tree[index] = arr[l];
        return;
    }

    int mid = (l+r)/2;
    build(index*2, l, mid);
    build(index*2+1, mid+1, r);
    tree[index] = tree[index*2] + tree[index*2+1];
}

void update(int index, int l, int r, int pos, int val){
    if(pos<l || pos>r){
        return;
    }

    if(l==r){
        tree[index] = val;
        arr[l] = val;
        return;
    }

    int mid = (l+r)/2;
    update(2*index, l, mid, pos, val);
    update(2*index+1, mid+1, r, pos, val);
    tree[index] = tree[2*index] + tree[2*index+1];
}

int query(int index, int l, int r, int lq, int rq){
    if(rq<l || lq>r){
        return 0;
    }

    if(l>=lq && r<=rq){
        return tree[index];
    }

    int mid = (l+r)/2;
    return query(2*index, l, mid, lq, rq) + query(2*index+1, mid+1, r,  lq, rq);
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
        int ch;
        cin>>ch;

        if(ch==1){
            // update
            int pos, val;
            cin>>pos>>val;
            update(1, 1, n, pos, val);
        }else if(ch==2){
            int lq ,rq;
            cin>>lq>>rq;
            cout<<query(1, 1, n, lq, rq)<<endl;
        }
    }
}

signed main(){
    solve();
    return 0;
}