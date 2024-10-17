#include<bits/stdc++.h>
#define endl "\n"
#define MP make_pair
#define inf 1e18
#define F first 
#define S second 
#define int long long

using namespace std;
using state = pair<int,int>;

int n,a,b;
int src;
vector<int> arr;
vector<vector<pair<int,int>>> g;
map<int,vector<int>> mp;
vector<int> dis;
vector<int> vis;

void create_graph(){
    g.resize(n+1+mp.size());

    for(int i=1;i<n;i++){
        g[i].push_back(MP(i+1,b));
        g[i+1].push_back(MP(i,b));
    }

    int Dnode = n+1;
    for(auto v:mp){
        for(auto u:v.second){
            g[Dnode].push_back(MP(u,a));
            g[u].push_back(MP(Dnode,0));
        }
        Dnode++;
    }
}

void dijkstra(int node){
    priority_queue<state> q;
    q.push(MP(-0,node));
    dis[node] = 0;

    while(!q.empty()){
        auto x = q.top();
        int curr = x.S;
        q.pop();

        for(auto v:g[curr]){
            int next_node = v.F;
            int cost = v.S;

            if(vis[next_node]) continue;
    
            if(dis[next_node]>dis[curr]+cost){
                vis[next_node] = 1;
                dis[next_node]=dis[curr]+cost;
                q.push(MP(-dis[next_node],next_node));
            }
        }
    }
}

void solve(){
    cin>>n>>a>>b;

    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mp[arr[i]].push_back(i);
    }

    create_graph();

    cin>>src;
    dis.assign(n+1+mp.size(),inf);
    vis.assign(n+1+mp.size(),0);
    dijkstra(src);

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}