#include<bits/stdc++.h>
#define endl "\n"
#define MP make_pair 
#define F first 
#define S second 

using namespace std;

struct union_find{
    int n, set_size, *parent, *rank;

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
            if(rank[rootx]>=rank[rooty]){
                parent[rooty] = rootx;
                rank[rootx] += rank[rooty];
            }else{
                parent[rootx] = rooty;
                rank[rooty] += rank[rootx];
            }
            set_size--;
        }
    }

    void reset(){
        set_size = n;
        for(int i=1;i<=n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int size(){
        return set_size;
    }
};

int n,m,q;
vector<pair<int,int>> g;

void solve(){
    cin>>n>>m>>q;
    g.resize(m+1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[i] = MP(a,b);
    }

    union_find uf(n);
    stack<pair<int,int>> order;
    priority_queue<int> deletion_order;

    for(int i=0;i<q;i++){
        int op;
        cin>>op;

        if(op==1){
            int x;
            cin>>x;
            order.push(MP(op,x));
            deletion_order.push(-x);
        }else{
            order.push(MP(op,-1));
        }
    }

    for(int i=1;i<=m;i++){
        if(i==-deletion_order.top()){
            deletion_order.pop();
        }else{
            int u = g[i].F;
            int v = g[i].S;
            uf.merge(u,v);
        }
    }

    stack<int> ans;
    for(int i=0;i<q;i++){
        auto curr = order.top();
        int op = curr.F;
        int x = curr.S;
        order.pop();

        if(op==1){
            int u = g[x].F;
            int v = g[x].S;
            uf.merge(u,v);
        }else{
            ans.push(uf.size());
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans.top()<<endl;
        ans.pop();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}