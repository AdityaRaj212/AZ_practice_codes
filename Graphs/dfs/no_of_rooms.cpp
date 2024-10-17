#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> g;
vector<vector<bool>> vis;

int n,m;

void dfs(int i, int j){
    vis[i][j] = true;
    if(i+1<n){
        if(!vis[i+1][j] && g[i+1][j]=='.'){
            dfs(i+1,j);
        }
    }
    if(i-1>=0){
        if(!vis[i-1][j] && g[i-1][j]=='.'){
            dfs(i-1,j);
        }
    }
    if(j+1<m){
        if(!vis[i][j+1] && g[i][j+1]=='.'){
            dfs(i,j+1);
        }
    }
    if(j-1>=0){
        if(!vis[i][j-1] && g[i][j-1]=='.'){
            dfs(i,j-1);
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<n;i++){
        g[i].resize(m+1);
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }

    vis.resize(n+1);
    for(int i=0;i<=n;i++){
        vis[i].resize(m+1);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j] = false;
        }
    }

    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && g[i][j]=='.'){
                count++;
                dfs(i,j);
            }
        }
    }

    cout<<count<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}