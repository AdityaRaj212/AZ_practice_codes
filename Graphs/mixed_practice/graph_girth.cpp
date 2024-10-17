#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

int n,m;
int lvl;
int girth = inf;
vector<vector<int>> g;
vector<int> vis;
vector<int> level;

void bfs(int node){
    queue<int> q;
    vis[node] = 1;
    level[node] = 0;
    q.push(node);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto v:g[curr]){
            if(!vis[v]){
                vis[v] = 1;
                level[v] = level[curr]+1;
                q.push(v);
            }else if (level[curr]-level[v]<1) {
                girth = min(girth, level[curr]+level[v]+1);
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

    // vis.assign(n+1,0);
    // level.resize(n+1);
    for(int i=1;i<=n;i++){
        // lvl = 0;
        vis.assign(n+1,0);
        level.clear();
        level.resize(n+1);
        bfs(i);
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<": "<<level[i]<<endl;
    // }
    // cout<<"Girth: "<<girth+1<<endl;
    
    if(girth==inf){
        cout<<-1<<"\n";
    }else{
        cout<<girth<<"\n";
    }
}

signed main(){
    solve();
    return 0;
}