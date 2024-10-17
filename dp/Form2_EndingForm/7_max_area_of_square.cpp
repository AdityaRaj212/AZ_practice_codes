#include<bits/stdc++.h>
#define inf 1e9
#define endl "\n"
#define int long long

using namespace std;

int n,m;
vector<vector<int>> grid;
int dp[1005][1005];

int rec(int row, int col){
    // pruning
    if(row<0 || col<0){
        return inf;
    }

    // base case
    if(row==0 || col==0){
        return grid[row][col];
    }

    // cache check
    if(dp[row][col]!=-1){
        return dp[row][col];
    }

    // transition
    int ans;
    if(grid[row][col]==1){
        ans = 1 + min(rec(row-1,col),min(rec(row,col-1),rec(row-1,col-1)));
    }else{  
        ans = 0;
    }

    // save and return 
    return dp[row][col] = ans;
}

void solve(){
    cin>>n>>m;

    grid.resize(n);
    for(int i=0;i<n;i++){
        grid[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    int maxSide = -inf;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rec(i,j)>maxSide){
                maxSide = rec(i,j);
            }
        }
    }

    cout<<maxSide*maxSide<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    while(T--){
        solve();
    }

    return 0;
}