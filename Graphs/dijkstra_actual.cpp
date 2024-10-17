#include<bits/stdc++.h>
using namespace std;

int n,m;
int dis[100100];
int vis[100100];
vector<vector<pair<int,int>>> g;

void dijkstra(int source){
    for(int i=0;i<n;i++){
        dis[i] = 1e9;
        vis[i] = 0;
    }

    dis[source] = 0;
    priority_queue<pair<int,int>> pq;

    pq.push({-0,source});

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();

        int curr_dis = x.first;
        int curr_node = x.second;

        if(vis[x.second]) continue;
        vis[x.second] = 1;

        for(auto v:g[curr_node]){
            int neigh = v.first;
            int new_dis = v.second;

            if(dis[neigh]>dis[curr_node]+new_dis){
                dis[neigh] = dis[curr_node]+new_dis;
                pq.push({-dis[neigh],neigh});
            }
        }
    }

}

void solve(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dijkstra(0);

    for(int i=1;i<n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
}

int main(){
    solve();
    return 0;
}