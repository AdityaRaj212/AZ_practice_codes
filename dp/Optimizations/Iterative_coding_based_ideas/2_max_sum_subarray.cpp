// DP Form - 2

#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

void solve(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int dp[n];
    int ans = -inf;

    for(int i=0;i<n;i++){
        if(i==0){
            dp[i] = arr[i];
        }else{
            dp[i] = max(arr[i], arr[i]+dp[i-1]);
        }
        ans = max(ans,dp[i]);
    }

    cout<<ans<<endl;
}

signed main(){
    solve();
    return 0;
}