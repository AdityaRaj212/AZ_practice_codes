#include<bits/stdc++.h>
using namespace std;

int n,m;
int no_of_comp = 0;
vector<vector<int>> g;
vector<int> vis;

void bfs(int node){
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto v:g[x]){
            if(!vis[v]){
                vis[v] = 1;
                bfs(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            no_of_comp++;
            bfs(i);
        }
    }

    cout<<no_of_comp<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}