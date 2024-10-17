#include<bits/stdc++.h>
#define inf 1e18 
#define int long long
#define endl "\n"

using namespace std;

int n,m;
vector<int> dis;
vector<int> go_to;
vector<int> vis;

bool is_valid(int node){
    return (node>0 && node<=100 && vis[node]==0);
}

void bfs(int node){
    dis[node] = 0;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i=1;i<=6;i++){
            int v = go_to[curr+i];
            if(is_valid(v)){
                vis[v] = 1;
                dis[v] = dis[curr]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
    go_to.resize(101);
    for(int i=1;i<=100;i++){
        go_to[i] = i;
    }

    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        go_to[a] = b;
    }

    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        go_to[a] = b;
    }

    vis.assign(101,0);
    dis.assign(101,inf);
    bfs(1);

    if(dis[100]==inf){
        dis[100] = -1;
    }
    cout<<dis[100]<<endl;
}

signed main(){
    int T;
    cin>>T;

    while(T--){
        vis.clear();
        dis.clear();
        go_to.clear();
        solve();
    }
    
    return 0;
}