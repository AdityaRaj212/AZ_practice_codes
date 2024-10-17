#include<bits/stdc++.h>
using namespace std;

int n;
int arr[101];
int dp[110][110][110];

int rec(int l, int r, int x){
    // this returns the max score in [l...r] where x no of same values are latched to left end

    // pruning

    // base case
    if(l>r){
        return 0;
    }

    // cache check
    if(dp[l][r][x]!=-1){
        return dp[l][r][x];
    }

    // transition
    int ans = 0;
    ans = rec(l+1,r,0) + (x+1)*(x+1);
    for(int mid=l+1;mid<=r;mid++){
        if (arr[mid] == arr[l]) {
            ans = max(ans, rec(l + 1, mid - 1, 0) + rec(mid, r, x + 1));
        }
    }

    // save and return 
    return dp[l][r][x] = ans;
}

void solve(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1,0)<<endl;
}

signed main(){
    solve();
    return 0;
}