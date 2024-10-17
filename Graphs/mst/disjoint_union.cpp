#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

struct union_find{
    int n, set_size, *parent, *rank;

    union_find(int a){
        n = a;
        set_size = a;
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i=1;i<=n;i++){
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return (parent[x] = find(parent[x]));
    }

    void merge(int x, int y){
        int par_x = find(x);
        int par_y = find(y);

        if(par_x!=par_y){
            if(rank[par_x]>=rank[par_y]){
                parent[par_y] = par_x;
                rank[par_x] += rank[par_y];
            }else{
                parent[par_x] = par_y;
                rank[par_y] += rank[par_x];
            }
            set_size--;
        }
    }

    void reset(){
        set_size = n;
        for(int i=1;i<=n;i++){
            rank[i] = 1;
            parent[i] = i;
        }
    }

    int size(){
        return set_size;
    }
};

void solve(){
    int n;
    cin>>n;

    union_find uf(n);

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        int op,x,y;
        cin>>op>>x>>y;

        if(op==0){
            uf.merge(x,y);
        }else{
            int rootx = uf.find(x);
            int rooty = uf.find(y);
            if(rootx==rooty){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    solve();
    return 0;
}