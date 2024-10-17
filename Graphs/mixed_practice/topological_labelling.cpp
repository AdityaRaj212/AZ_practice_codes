#include<bits/stdc++.h>
using namespace std;

int n,m;
int lbl;
vector<vector<int>> g;
vector<int> vis;
vector<int> topo;
vector<int> label;
vector<int> in_deg;
vector<int> out_deg;

void kahn(){
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        if(out_deg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.top();
        q.pop();
        label[curr] = lbl;
        lbl--;
        for(auto v:g[curr]){
            out_deg[v]--;
            if(out_deg[v]==0){
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    in_deg.assign(n+1,0);
    out_deg.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[b].push_back(a);
        in_deg[b]++;
        out_deg[a]++;
    }

    vis.assign(n+1,0);
    label.resize(n+1);
    lbl = n;
    kahn();
    for(int i=1;i<=n;i++){
        // cout<<"Node "<<i<<": "<<label[i]<<endl;
        cout<<label[i]<<" ";
    }
    cout<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}