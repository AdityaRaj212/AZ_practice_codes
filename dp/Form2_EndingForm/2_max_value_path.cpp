#include<bits/stdc++.h>
#define endl "\n"
#define inf 1e18 
#define ing long long

using namespace std;

int n,m;
vector<vector<int>> arr;
int dp[1001][1001];

int rec(int row, int col){
    // pruning
    if(row<0 || col<0){
        return -inf;
    }

    // base case
    if(row==0 && col==0){
        return arr[0][0];
    }

    // cache check
    if(dp[row][col]!=-1){
        return dp[row][col];
    }

    // transition
    int ans = max(arr[row][col]+rec(row,col-1),arr[row][col]+rec(row-1,col));

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
}

signed main(){
    solve();
    return 0;
}