#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<vector<int>> g;
vector<vector<int>> backedge;
vector<int> dp;
vector<int> in_deg;

void kahn(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in_deg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto v:g[curr]){
            in_deg[v]--;
            if(in_deg[v]==0){
                q.push(v);
            }
        }

        for(auto v:backedge[curr]){
            dp[curr] = (dp[v]+dp[curr]) % 1000000007;
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    backedge.resize(n+1);
    in_deg.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        in_deg[b]++;
        backedge[b].push_back(a);
    }
    dp.assign(n+1,0);
    dp[1] = 1;

    kahn();

    cout<<dp[n]<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}