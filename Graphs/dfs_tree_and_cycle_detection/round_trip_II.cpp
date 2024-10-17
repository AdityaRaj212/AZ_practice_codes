#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> colour;
bool is_cycle = false;

void dfs(int node){
    colour[node] = 2;

    for(auto v:g[node]){
        if(colour[v]==1){
            //forward-edge
            colour[v]=2;
            dfs(v);
        }else if(colour[v]==2){
            //back-edge
            is_cycle = true;
        }else if(colour[v]==3){
            //cross-edge;
        }
    }

    colour[node] = 3;
}

void solve(){
    cin>>n>>m;

    g.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;  
        g[a].push_back(b);
    }

    colour.assign(n+1,1);

    for(int i=1;i<=n;i++){
        if(colour[i]==1){
            dfs(i);
        }
    }

    if(is_cycle){
        cout<<"Yes"<<"\n";
    }else{
        cout<<"No"<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;
    while(T--){
        g.clear();
        colour.clear();
        is_cycle = false;
        solve();
    }
    return 0;
}