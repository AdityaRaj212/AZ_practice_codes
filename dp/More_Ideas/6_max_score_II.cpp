#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<vector<int>> arr;
int dp[110][110][12];

void solve(){
    cin>>n>>m>>k;

    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        arr[i].resize(m+1);
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j]=s[j-1]-'0';
        }
    }

    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=m;i++){
        int rem = arr[n][i]%k;
        dp[n][i][rem] = arr[n][i];
    }

    for(int i=n-1;i>0;i--){
        for(int j=1;j<=m;j++){
            for(int r=0;r<k;r++){
                if(j>1 && dp[i+1][j-1][r]>=0){
                    int cost = dp[i+1][j-1][r]+arr[i][j];
                    if(dp[i][j][cost%k]<cost){
                        dp[i][j][cost%k] = cost; 
                    }
                }
                if(j<=m && dp[i+1][j+1][r]>=0){
                    int cost = dp[i+1][j+1][r]+arr[i][j];
                    if(dp[i][j][cost%k]<cost){
                        dp[i][j][cost%k] = cost;
                    }
                }
            }
        }
    }

    int ans = -1;
    for(int j=1;j<=m;j++){
        ans = max(ans,dp[1][j][0]);
    }

    cout<<ans<<endl;
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