#include<bits/stdc++.h>
#define inf 1e9
#define int long long

using namespace std;

int n,m;
vector<vector<int>> arr;    
int dp[202][202];
int minCost = inf;

int rec(int row, int col){
    // pruning
    if(row<0 || col<0){
        return -inf;
    }

    // base case
    if(row==0 && col==0){
        return arr[row][col];
    }

    // cache check
    if(dp[row][col]!=-1){
        return dp[row][col];
    }

    // transition
    int ans = arr[row][col] + max(rec(row-1,col),rec(row,col-1));
    if(ans<minCost){
        minCost = ans;
    }

    // save and return
    return dp[row][col] = ans;
}

void solve(){
    cin>>n>>m;

    arr.resize(n);
    for(int i=0;i<n;i++){
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,m-1)<<endl;
    cout<<minCost<<endl;
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