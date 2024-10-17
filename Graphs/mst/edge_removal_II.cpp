#include<bits/stdc++.h>
#define MP make_pair
#define endl "\n"
#define F first 
#define S second 
#define int long long

using namespace std;

struct union_find{
    int n,set_size,*parent,*rank;

    union_find(int a){
        n = a;
        set_size = a;
        parent = new int[n+1];
        rank = new int[n+1];
        
        for(int i=1;i<=n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return (parent[x] = find(parent[x]));
    }

    void merge(int x, int y){
        int rootx = find(x);
        int rooty = find(y);

        if(rootx!=rooty){
            if(rank[rootx]>rank[rooty]){
                parent[rooty] = rootx;
                rank[rootx] += rank[rooty];
            }else{
                parent[rootx] = rooty;
                rank[rooty] += rank[rootx];
            }
            set_size--;
        }
    }

    int size(){
        return set_size;
    }

    void reset(){
        set_size = n;
        for(int i=1;i<=n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
};

int n,m,q;
vector<pair<int,int>> edge;
vector<pair<int,int>> order;

void solve(){
    cin>>n>>m>>q;

    union_find uf(n);

    edge.resize(m+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edge[i] = MP(u,v);
    }


    vector<bool> to_delete(m+1,false);
    for(int i=0;i<q;i++){
        int op;
        cin>>op;

        if(op==1){
            int x;
            cin>>x;
            order.push_back(MP(op,x));
            to_delete[x] = true;
        }else{
            order.push_back(MP(op,-1));
        }
    }

    for(int i=1;i<=m;i++){
        if(!to_delete[i]){
            int u = edge[i].F;
            int v = edge[i].S;
            uf.merge(u,v);
        }
    }

    vector<int> ans;

    for(int i=q-1;i>=0;i--){
        int op = order[i].F;

        if(op==1){
            int x = order[i].S;
            int u = edge[x].F;
            int v = edge[x].S;
            uf.merge(u,v);
        }else{
            ans.push_back(uf.size());
        }
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}