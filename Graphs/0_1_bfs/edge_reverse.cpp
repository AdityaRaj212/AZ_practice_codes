#include<bits/stdc++.h>
#define inf 1e9
#define F first 
#define S second 
#define MP make_pair

using namespace std;

int n,m;
vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> dis;

void _01_bfs(int node){
    vis[node] = 1;
    deque<int> dq;
    dq.push_back(node);
    dis[node] = 0;

    while(!dq.empty()){
        int curr = dq.front();
        dq.pop_front();

        for(auto v:g[curr]){
            int next_node = v.first;
            int cost = v.second;
            if(dis[next_node]>dis[curr]+cost){
                dis[next_node]=dis[curr]+cost;
                vis[next_node] = 1;
                if(cost==0){
                    dq.push_front(next_node);
                }else{
                    dq.push_back(next_node);
                }    
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
        g[a].push_back(MP(b,0));
        g[b].push_back(MP(a,1));
    }

    vis.assign(n+1,0);
    dis.assign(n+1,inf);

    _01_bfs(1);
    if(dis[n]==inf){
        dis[n] = -1;
    }
    cout<<dis[n]<<"\n";
}   

signed main(){
    int T;
    cin>>T;

    while(T--){
        g.clear();
        vis.clear();
        dis.clear();
        solve();
    }
    return 0;
}