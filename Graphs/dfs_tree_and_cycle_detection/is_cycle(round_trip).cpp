#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> col;
vector<int> parent;
bool is_cycle = false;

void dfs(int node, int par){
    parent[node] = par;
    col[node] = 2;
    for(auto v:g[node]){
        if(v==par) continue;
        if(col[v]==1){
            dfs(v,node);  // forward-edge
        }
        else if(col[v]==2){
            is_cycle = true;  // back-edge
        }
        else if(col[v]==3){
            //not of use - cross edge
        }
    }
    col[node] = 3;
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,0);
        }
    }

    if(is_cycle){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}