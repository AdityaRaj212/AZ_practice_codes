// DP Form - 2

#include<bits/stdc++.h>
#define inf 1e9
#define int long long
#define endl "\n"

using namespace std;

int n,k;
int arr[1010];
int prefix[1010];
int dp[1010][1010];
int done[1010][1010];

int rec(int i, int k){
    // pruning
    if(i<=0){
        if(k==0){
            return 0;
        }else{
            return -inf;
        }
    }

    // base case

    // cache check
    if(done[i][k]){
        return dp[i][k];
    }

    // transition
    int ans = rec(i-1,k);
    for(int j=1;j<=i+1;j++){
        ans = max(ans, rec(i-j,k-1)+prefix[i]-prefix[i-j]);
    }
    done[i][k] = 1;

    // save and return 
    return dp[i][k] = ans;
}

/*
9 2
-4 3 2 -5 6 7 -1 3 5
*/

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }

    memset(done, 0, sizeof(done));
    cout<<rec(n,k)<<endl;
}

signed main(){
    solve();
    return 0;
}