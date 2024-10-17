#include<bits/stdc++.h>
#define endl "\n"
#define int long long
#define mod 1000000007

using namespace std;

int n,m,k;
vector<vector<int>> grid;
int dp[202][202][404];

int rec(int row, int col, int left){
    // cout<<"yo"<<endl;
    // pruning
    if(left==0){
        if(grid[row][col]!=0){
            return 0;
        }
    }
    if(left<0){
        return 0;
    }
    if(row<=0 || col<=0){
        return 0;
    }

    // base case
    if(row==1 && col==1){
        if(grid[row][col]!=0){
            if(left>0){
                return 1;
            }else{
                return 0;
            }
        }
        return 1;
    }

    // cache check
    if(dp[row][col][left]!=-1){
        return dp[row][col][left];
    }

    // transition
    int ans;
    if(grid[row][col]==0){
        ans= (rec(row-1,col,left)+rec(row,col-1,left))%mod;
    }else{
        ans = (rec(row-1,col,left-1)+rec(row,col-1,left-1))%mod;
    }

    // save and return 
    return dp[row][col][left] = ans;
}

void solve(){
    cin>>n>>m>>k;

    grid.resize(n+1);
    for(int i=0;i<=n;i++){
        grid[i].resize(m+1);
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                grid[i][j]=1;
            else
                cin>>grid[i][j];
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int l = 0; l <= k; ++l) {
                dp[i][j][l] = -1;
            }
        }
    }

    // cout<<"yo"<<endl;
    cout<<rec(n,m,k)<<endl;
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