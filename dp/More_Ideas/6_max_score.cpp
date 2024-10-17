// Form - 2

#include<bits/stdc++.h>
#define inf 1e9
#define int long long
#define endl "\n"

using namespace std;

int n,m,k;
vector<vector<int>> arr;
int dp[111][111][12];

int rec(int row ,int col, int rem){
    // this returns the maximum score one can achieve by reaching [row,col] with rem as 
    // remainder

    // pruning
    if(row<=0 || col<=0 || col>m){
        return -inf;
    }

    // base case
    if(row==1){
        return arr[row][col];
    }

    // cache check
    if(dp[row][col][rem]!=-1){
        return dp[row][col][rem];
    }

    // transition
    int ans;
    int r = (rem - arr[row][col] % k + k) % k;

    ans = arr[row][col] + rec(row-1,col-1,r);
    ans = max(ans, arr[row][col] + rec(row-1,col+1,r));

    // save and return 
    return dp[row][col][rem] = ans;
}

void solve(){
    cin>>n>>m>>k;

    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        arr[i].resize(m+1);
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j]=s[j-1];
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int l=0;l<=k;l++){
                dp[i][j][l] = -1;
            }
        }
    }

    int ans = -inf;
    for(int col=1;col<=m;col++){
        ans = max(ans,rec(n,col,0));
    }

    cout<<ans<<endl;
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