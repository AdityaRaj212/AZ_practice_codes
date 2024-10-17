#include<bits/stdc++.h>
using namespace std;

struct node{
    int sum, maxm, lazy;

    node(){
        sum = 0;
        maxm = 0;
        lazy = 0;
    }
};

int n;
vector<int> arr;
vector<node> tree(404040);

node merge(node a, node b){
    node temp;
    temp.sum = a.sum + b.sum;
    temp.maxm = max(a.maxm, b.maxm);
    return temp;
}

void push(int index, int l, int r){
    if(tree[index].lazy){
        tree[index].sum = (r-l+1)*tree[index].lazy;
        tree[index].maxm = tree[index].lazy;
        if(l!=r){
            tree[2*index].lazy = tree[index].lazy;
            tree[2*index+1].lazy = tree[index].lazy;
        }
        tree[index].lazy = 0;
    }
}

void update(int index, int l, int r, int lq, int rq, int v){
    push(index, l, r);
    if(lq>r || rq<l){
        return;
    }

    if(lq<=l && rq>=r){
        tree[index].lazy = v;
        push(index, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(2*index, l, mid, lq, rq, v);
    update(2*index+1, mid+1, r, lq, rq, v);
    tree[index] = merge(tree[2*index], tree[2*index+1]);
}

node query(int index, int l, int r, int lq, int rq){
    push(index, l, r);
    if(lq>r || rq<l){
        return node();
    }

    if(lq<=l && rq>=r){
        return tree[index];
    }

    int mid = (l+r)/2;
    return merge(query(2*index, l, mid, lq, rq), query(2*index+1, mid+1, r, lq, rq));
}

void solve(){
    update(1, 0, 9, 0, 5, 3);
    update(1, 0, 9, 6, 9, 4);
    node x = query(1, 0, 9, 3, 6);
    cout<<x.sum<<" "<<x.maxm<<endl;
}

signed main(){
    solve();
    return 0;
}