#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr, tree;

void build(int index, int l, int r){
    if(l==r){
        tree[index] = arr[l];
    }
    int mid = (l+r)/2;
    build(index*2, l, mid);
    build(index*2+1, mid+1, r);
    tree[index] = tree[2*index] + tree[2*index+1];
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
    update(index*2, l, mid, pos, val);
    update(index*2+1, mid+1, r, pos, val);
    tree[index] = tree[index*2] + tree[index*2+1];
}

int query(int index, int l, int r, int lq, int rq){
    if(rq<l || lq>r){
        return 0;
    }

    if(l>=lq && r<=rq){
        return tree[index];
    }

    int mid = (l+r)/2;
    return query(index*2, l, mid, lq, rq) + query(index*2+1, mid+1, r, lq, rq);
}

void solve(){
    cin>>n;

    arr.resize(n);
    tree.resize(4*n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(1, 0, n-1);

    int q;
    cin>>q;

    while(q--){
        int ch;
        cin>>ch;

        if(ch==1){
            // query
            int lq, rq;
            cin>>lq>>rq;
            cout<<query(1, 0, n-1, lq, rq)<<endl;
        }else if(ch==2){
            // update
            int pos, val;
            cin>>pos>>val;
            update(1, 0, n-1, pos, val);
        }
    }
}

signed main(){
    solve();
    return 0;
}