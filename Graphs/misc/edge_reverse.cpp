#include<bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define INF 1e9
using namespace std;

int n,m;
vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> dis;

void sssp(int sc){
    deque<int> q;
    q.push_back(sc);
    dis[sc] = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop_front();

        if(vis[x]) continue;
        vis[x] = 1;

        for(auto v:g[x]){
            if(dis[v.F]>dis[x]+v.S){
                dis[v.F] = dis[x]+v.S;
                if(v.S==0){
                    q.push_front(v.F);
                }
                else{
                    q.push_back(v.F);
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;

    g.resize(n+1);
    vis.assign(n+1,0);
    dis.assign(n+1,INF);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        g[a].push_back(MP(b,0));
        g[b].push_back(MP(a,1));
    }

    sssp(1);

    if(dis[n]==INF) dis[n] = -1;
    cout<<dis[n]<<endl;
}

int main(){
    int T;
    cin>>T;

    while(T--){
        g.clear();
        solve();
    }
    return 0;
}