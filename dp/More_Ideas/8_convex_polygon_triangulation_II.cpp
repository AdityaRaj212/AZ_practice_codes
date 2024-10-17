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

    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r = l+len-1;

            if(len==2){
                dp[l][r] = 0;
            }
            else{
                for(int x=l+1;x<=r-1;x++){
                    int cost = arr[l]*arr[x]*arr[r];
                    dp[l][r] = min(dp[l][r], cost+dp[l][x]+dp[x][r]);
                }
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
        arr.clear();
        solve();
    }

    return 0;
}