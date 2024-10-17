#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;
queue<int> q;

void bfs(int node){
    vis[node] = 1;
    q.push(node);
    while(!q.empty()){
        int x = q.front();
        cout<<x<<" ";
        q.pop();

        for(auto v:g[x]){
            if(!vis[v]){
                vis[v]  = 1;
                q.push(v);
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
    vis.resize(n+1);
    bfs(1);
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}