#include<bits/stdc++.h>
#define inf 1e9

using namespace std;

int n;
vector<int> arr;
int dp[1010][1010];

int rec(int l, int r){
    // pruning

    // base case
    if(l>=r){
        return 1;
    }

    // cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    // transition
    int ans = inf;
    if(arr[r]==arr[l]){
        ans = rec(l+1, r-1);
    }
    for(int i=l;i<r;i++){
        ans = min(ans, rec(l,i)+rec(i+1,r));
    }

    // save and return
    return dp[l][r] = ans;
}

void solve(){
    cin>>n;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<rec(0,n-1)<<endl;
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