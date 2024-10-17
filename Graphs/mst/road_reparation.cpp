#include<bits/stdc++.h>
#define endl "\n"
#define MP make_pair
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
        if(x==parent[x]){
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

int n,m;
vector<pair<int,pair<int,int>>> edge;

void solve(){
    cin>>n>>m;

    union_find uf(n);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        edge.push_back(MP(c,MP(a,b)));
        edge.push_back(MP(c,MP(b,a)));
    }

    sort(edge.begin(),edge.end());

    int min_cost  = 0;
    int edges = 0;

    for(auto ele:edge){
        int u = ele.S.F;
        int v = ele.S.S;

        int rootu = uf.find(u);
        int rootv = uf.find(v);

        if(rootu!=rootv){
            uf.merge(rootu,rootv);
            edges++;
            min_cost += ele.F;
        }
    }

    if(edges!=n-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<min_cost<<endl;
    }
}

signed main(){
    solve();
    return 0;
}