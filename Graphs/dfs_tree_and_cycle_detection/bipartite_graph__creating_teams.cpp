#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> colour;

bool possible = true;

void dfs(int node, int col){
    vis[node] = 1;
    colour[node] = col;

    for(auto v:g[node]){
        if(!vis[v]){
            vis[v] = 1;
            // col = !col;
            dfs(v,!col);
        }else{
            if(colour[node]==colour[v]){
                possible = false;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    colour.resize(n+1);
    vis.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }

    if(possible){
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