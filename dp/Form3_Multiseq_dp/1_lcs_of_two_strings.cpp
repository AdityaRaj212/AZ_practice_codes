#include<bits/stdc++.h>
using namespace std;

int n,m;
string a,b;
int dp[1001][1001];

int rec(int i, int j){
    // this rec returns the length of the longest lcs in [i...n-1] and [j...m-1]

    // pruning

    // base case
    if(i>=n || j>=m){
        return 0;
    }

    // caching
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // transition
    int ans = 0;
    ans = max(ans, rec(i+1,j));
    ans = max(ans, rec(i,j+1));
    if(a[i]==b[j]){
        ans = max(ans, 1 + rec(i+1,j+1));
    }

    // save and return 
    return dp[i][j] = ans;
}

void solve(){
    cin>>a>>b;
    n = a.size();
    m = b.size();

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

signed main(){
    solve();
    return 0;
}