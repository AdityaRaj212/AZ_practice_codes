#include<bits/stdc++.h>
#define inf 1e9
#define endl "\n"
#define int long long

using namespace std;

int n;
vector<int> arr;
int dp[505][505];

int rec(int l, int r){
    // pruning

    // base case
    if(l==r){
        return 0;
    }

    // cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    // transition
    int ans = inf;
    int total = 0;
    int sum = 0;

    for(int i=l;i<=r;i++){
        total += arr[i];
    }

    for(int i=l;i<r;i++){
        sum += arr[i];
        ans = min(ans,rec(l,i)+rec(i+1,r)+(sum%100)*((total-sum)%100));
    }

    // save and return
    return dp[l][r] = ans;
}

void solve(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
}

signed main(){
    solve();
    return 0;
}