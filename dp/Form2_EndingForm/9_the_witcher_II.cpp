#include<bits/stdc++.h>
#define inf 1e9
#define endl "\n"
// #define int long long

using namespace std;

int n,m;
vector<vector<int>> arr;
int dp[202][202];

void solve(){
    cin>>n>>m;
    int minCost = inf;

    arr.resize(n+1);
    for(int i=0;i<=n;i++){
        arr[i].resize(m+1);
        for(int j=0;j<=m;j++){
            if(i==n || j==m){
                arr[i][j] = inf;
                dp[i][j] = inf;
            }else{
                cin>>arr[i][j];
                dp[i][j] = -1;
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1){
                dp[i][j] = max(1,(1-arr[i][j]));
            }else{
                dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1])-arr[i][j]);
            }
        }
    }

    cout<<dp[0][0]<<endl;
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