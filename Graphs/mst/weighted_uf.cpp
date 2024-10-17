#include<bits/stdc++.h>
#define endl "\n"
#define F first 
#define S second 
#define MP make_pair
#define int long long

using namespace std;
using state = pair<int,int>;

struct weighted_uf{
    int n,set_size;
    vector<state> parent;
    vector<int> rank;
    vector<int> cost;

    weighted_uf(int a){
        n = a;
        set_size = a;
        parent.resize(n+1);
        rank.resize(n+1);
        cost.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = MP(i,0);
            rank[i] = 1;
            cost[i] = 0;
        }
    }

    state find(int node){
        if (node != parent[node].F) {
            int orig_parent = parent[node].F;
            state root = find(orig_parent);
            parent[node].F = root.F;
            cost[node] += parent[orig_parent].S;
            parent[node].S = cost[node];
        }
        return parent[node];
    }

    void merge(int x, int y, int c){
        state rootx = find(x);
        state rooty = find(y);

        if(rootx.F==rooty.F){
            //they are part of same component
        }else{
            if(rank[rootx.F]>rank[rooty.F]){
                parent[rooty.F] = MP(rootx.F,-c+rootx.S-rooty.S);
                rank[rootx.F] += rank[rooty.F];
                cost[rooty.F] = -c+rootx.S-rooty.S;
            }else{
                parent[rootx.F] = MP(rooty.F,c-rootx.S+rooty.S);
                rank[rooty.F] += rank[rootx.F];
                cost[rootx.F] = c-rootx.S+rooty.S;
                if (rank[rootx.F] == rank[rooty.F]) {
                    rank[rooty.F]++;
                }
            }
            set_size--;
        }
    }

    int size(){
        return set_size;
    }
};

int n,q;

void solve(){
    cin>>n>>q;

    weighted_uf wuf(n);

    for(int i=0;i<q;i++){
        int op;
        cin>>op;

        if(op==0){
            int x,y,z;
            cin>>x>>y>>z;
            wuf.merge(y,x,z);
        }else{ 
            int x,y;
            cin>>x>>y;

            state rootx = wuf.find(x);
            state rooty = wuf.find(y);

            if(rootx.F!=rooty.F){
                cout<<"?"<<endl;
            }else{
                cout<<wuf.parent[y].S-wuf.parent[x].S<<endl;
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