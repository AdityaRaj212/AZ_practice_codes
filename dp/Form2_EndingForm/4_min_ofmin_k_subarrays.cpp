#include<bits/stdc++.h>
#define int long long
#define inf 1e9

using namespace std;

int n,k;
vector<int> arr;
int dp[1001][1001];

int rec(int i, int x){
    // i represents last index and x represents the number of subarrays we need to make 
    // till ith index

    // pruning
    if(x<0){
        return inf;
    }

    // base case
    if(i==-1){
        if(x==0){
            return 0;
        }else{
            return inf;
        }
    }

    // cache check
    if(dp[i][x]!=-1){
        return dp[i][x];
    }

    // transition
    int ans = inf;
    int min_seen = arr[i];
    for(int j=i-1;j>=-1;j--){
        ans = min(ans, rec(j,x-1)+min_seen);
        min_seen = min(min_seen,arr[j]);
    }

    // save and return 
    return dp[i][x] = ans;
}

void solve(){
    cin>>n>>k;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,k)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}