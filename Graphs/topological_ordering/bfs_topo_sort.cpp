#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> in_deg;
vector<int> topo;

void kahn(){
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        if(in_deg[i]==0){
            q.push(-i);
        }
    }
    while(!q.empty()){
        int curr = -q.top();
        q.pop();
        topo.push_back(curr);
        for(auto v:g[curr]){
            in_deg[v]--;
            if(in_deg[v]==0){
                q.push(-v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    in_deg.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        in_deg[b]++;
    }
    kahn();
    if(topo.size()!=n){
        cout<<-1<<"\n";
    }else{
        for(int i=0;i<n;i++){
            cout<<topo[i]<<" ";
        }
    }
}

signed main(){
    solve();
    return 0;
}