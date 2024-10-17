#include<bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int n,m;
vector<vector<int>> grid(1010, vector<int>(1010));
int dp[1010][1010];

void solve(){
    cin>>n>>m;

    // grid.resize(n);
    for(int i=0;i<n;i++){
        // grid[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            dp[i][j] = 0;
        }
    }

    // memset(dp,0,sizeof(dp));
    // don't use memset it's a costly operation

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0){
                dp[i][j] = grid[i][j];
            }
            else if(grid[i][j]){
                dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
            ans = max(ans,dp[i][j]);
        }
    }

    cout<<ans*ans<<endl;
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