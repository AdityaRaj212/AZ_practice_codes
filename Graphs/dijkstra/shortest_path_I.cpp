#include<bits/stdc++.h>
#define MP make_pair
#define F first 
#define S second 
#define inf 1e15
#define int long long

using namespace std;
using state = pair<int,int>;

int n,m;
vector<vector<state>> g;
vector<int> dis;

void dijkstra(int node){
    priority_queue<state> pq;
    dis[node] = 0;
    pq.push(MP(-0,node));

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int curr_node = curr.S;

        for(auto v:g[curr_node]){
            if(dis[v.F]>dis[curr_node]+v.S){
                dis[v.F]=dis[curr_node]+v.S;
                pq.push(MP(-dis[v.F],v.F));
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(MP(b,c));
        g[b].push_back(MP(a,c));
    }

    dis.assign(n+1,inf);
    dijkstra(1);

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<' ';
    }
    cout<<"\n";
}

signed main(){
    solve();
    return 0;
}