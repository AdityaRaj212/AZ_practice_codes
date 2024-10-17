#include<bits/stdc++.h>
#define MP make_pair
#define F first 
#define S second 
#define inf 1e18

using namespace std;
using state = pair<int,int>;

int n,m;
int a,b,c;
vector<vector<pair<int,int>>> g;
vector<int> p;
vector<int> dis;
vector<int> vis;

void dijkstra(state node){
    priority_queue<pair<int,state>> q;
    q.push(MP(0,node));
    dis[node.F] = 0;

    while(!q.empty()){
        auto curr = q.top();
        q.pop();

        int dis = curr.F;
        int curr_node = curr.S.F;
        int fuel = curr.S.S;

        for(auto v:g[curr_node]){
            if(vis[v.F]) continue;
            vis[v.F] = 1;

            if(dis[v.F]>dis[curr_node]){
                
            }
        }
    }

}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;

        g[u].push_back(MP(v,d));
        g[v].push_back(MP(u,d));
    }

    p.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    cin>>a>>b>>c;
    dis.assign(n+1,inf);
    vis.assign(n+1,0);
    dijkstra(MP(a,0));
}

signed main(){
    solve();
    return 0;
}