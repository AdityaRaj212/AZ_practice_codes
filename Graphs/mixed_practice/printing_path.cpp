#include<bits/stdc++.h>
#define F first 
#define S second 
#define MP make_pair

using namespace std;
using state = pair<int,int>;

int n,m;
vector<vector<int>> arr;
vector<vector<int>> vis;
vector<state> members;

bool is_valid(int row, int col){
    return (row>=0 && row<n && col>=0 && col<m && arr[row][col]!=0);
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<state> neighbours(state node){
    vector<state> neighs;
    for(int i=0;i<4;i++){
        int row = node.F + dy[i];
        int col = node.S + dx[i];
        if(is_valid(row,col)){
            neighs.push_back(MP(row,col));
        }
    }
    return neighs;
}

void dfs(state node){
    vis[node.F][node.S] = 1;
    members.push_back(node);
    for(auto v:neighbours(node)){
        if(!vis[v.F][v.S] && arr[v.F][v.S]==1){
            vis[v.F][v.S] = 1;
            dfs(v);
        }
    }
}

/*
5 5
1 1 0 1 1 
0 1 0 0 0
1 1 1 1 0
1 0 1 0 0
0 0 1 0 0
*/

void solve(){
    cin>>n>>m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vis.assign(n,vector<int>(m,0));
    // dfs(MP(0,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && is_valid(i,j)){
                members.clear();
                dfs(MP(i,j));
                for(int i=0;i<members.size();i++){
                    cout<<"("<<members[i].F<<","<<members[i].S<<"), ";
                }
                cout<<endl;
            }
        }
    }

    
}

signed main(){
    members.clear();
    solve();
    return 0;
}