#include<bits/stdc++.h>
#define inf 1e9
#define int long long
#define endl "\n"

using namespace std;

//O(n^3)

int n;
vector<int> arr;
int dp[1001][1001];

int rec(int l, int r){
    // pruning 

    // base case
    if(l+1==r){
        return 0;
    }

    // cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    // transition
    int ans = inf;
    for(int p=l+1;p<=r-1;p++){
        ans = min(ans, arr[r]-arr[l]+rec(l,p)+rec(p,r));
    }

    // save and return 
    return dp[l][r]  = ans;
}

void solve(){
    cin>>n;

    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    arr[0] = 0;

    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n)<<endl;
}   

signed main(){
    solve();
    return 0;
}