#include<bits/stdc++.h>
#define MP make_pair
#define F first
#define S second 
#define inf 1e9 
#define int long long

using namespace std;

int n,m;
vector<vector<pair<int,int>>> g;
vector<pair<pair<int,int>,int>> edges;
vector<int> dis;

void bellman_ford(int sc_node){
    dis[sc_node] = 0;
    for(int i=1;i<=n;i++){
        for(auto it:edges){
            int u = it.F.F;
            int v = it.F.S;
            int cost = it.S;
            if(dis[u] != inf)
                dis[v] = min(dis[v],dis[u]+cost);
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(MP(b,-c));
        edges.push_back(MP(MP(a,b),-c));
    }

    dis.assign(n+1,inf);

    bellman_ford(1);

    bool neg_cycle = false;

    for(auto it:edges){
        int u = it.F.F;
        int v = it.F.S;
        int cost = it.S;

        if(dis[u]!=inf && dis[v]>dis[u]+cost){
            neg_cycle = true;
            break;
        }
    }
    
    if(neg_cycle){
        cout<<-1<<"\n";
    }else{
        cout<<-dis[n]<<"\n";
    }
}

signed main(){
    solve();
    return 0;
}