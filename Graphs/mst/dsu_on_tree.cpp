#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> val;
vector<vector<int>> g;
vector<set<int>> cols;
vector<int> ans;

int merge(int a, int b){
    if(cols[a].size()<cols[b].size()){
        swap(a,b);
    }

    for(auto v:cols[b]){
        cols[a].insert(v);
    }
    cols[b].clear();
    return a;
}

int dfs(int node, int parent){
    int curr_set = val[node];
    for(auto v:g[node]){
        if(v!=parent){
            curr_set = merge(curr_set,dfs(v,node));
        }
    }
    ans[node] = cols[curr_set].size();
    return curr_set;
}

void solve(){
    cin>>n;

    g.resize(n+1);
    cols.resize(n+1);
    val.resize(n+1);
    ans.resize(n+1);

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cols[i].insert(x);
        val[i] = x;
    }

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}

signed main(){
    solve();
    return 0;
}