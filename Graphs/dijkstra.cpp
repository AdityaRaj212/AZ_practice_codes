#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
using state = pair<int,int>;

int n,m,a,b,c;
vector<vector<pair<int,int>>> g;
int p[100100];
int dis[100100][101];
int vis[100100][101];

void dijkstra(int sc){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=c;j++){
            dis[i][j] = 1e9;
            vis[i][j] = 0;
        }
    }
    priority_queue<pair<int,state>> pq;

    dis[sc][0] = 0;
    pq.push(MP(0,MP(sc,0)));

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();

        state curr_state = x.second;
        int curr_dis = -x.first;

        if(vis[curr_state.first][curr_state.second]) continue;
        vis[curr_state.first][curr_state.second]=1;

        // refuel
        if(curr_state.second<c && dis[curr_state.first][curr_state.second+1]>curr_dis+p[curr_state.first]){
            dis[curr_state.first][curr_state.second+1]=curr_dis+p[curr_state.first];
            pq.push(MP(-dis[curr_state.first][curr_state.second+1],MP(curr_state.first,curr_state.second+1)));
        }

        // change city 
        for(auto v:g[curr_state.first]){
            if(curr_state.second>=v.second && dis[curr_state.first][curr_state.second-v.second]>curr_dis){
              dis[curr_state.first][curr_state.second-v.second]=curr_dis;  
              pq.push(MP(-dis[curr_state.first][curr_state.second-v.second],MP(v.first,curr_state.second-v.second)));
            }
        }
    }

}

void solve(){
    cin>>n>>m;
    g.resize(n+1);

    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }

    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    cin>>a>>b>>c;

    dijkstra(a);

    cout<<dis[b][0]<<endl;
}

int main(){
    solve();
    return 0;
}