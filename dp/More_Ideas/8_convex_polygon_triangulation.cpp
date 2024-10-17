#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define endl "\n"

using namespace std;

int n;
vector<int> arr;

void solve(){
    cin>>n;

    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, inf));

    for(int len=3;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r = l+len-1;

            if(len==3){
                dp[l][r] = arr[l]*arr[l+1]*arr[l+2];
            }else{
                int ans = inf;
                for(int x=l+1;x<=r-1;x++){
                    int cost = arr[l]*arr[x]*arr[r];
                    if(x==l+1){
                        ans = min(ans,cost+dp[l+1][r]);
                    }else if(x==r-1){
                        ans = min(ans,cost+dp[l][r-1]);
                    }else{
                        ans = min(ans,cost+dp[l][x]+dp[x][r]);
                    }
                }
                dp[l][r] = ans;
            }
        }
    }

    cout<<dp[1][n]<<endl;
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