// DP Form - 2

#include<bits/stdc++.h>
#define inf 1e18 
#define int long long
#define endl "\n"

using namespace std;

string a,b;
int n,m;
int dp[1010][1010];

int rec(int i, int j){
    // this returns the shortes uncommon subseq in [0...i] and [0...j]

    // pruning

    // base case
    if(i==-1){
        return inf;
    }else if(j==-1){
        return 1;
    }

    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // transition
    int ans = inf;
    int k = j;
    while (k >= 0 && b[k] != a[i]) {
        k--;
    }

    if(k<0){
        return dp[i][j] = 1;
    }else{
        ans = min(1+rec(i-1,k-1),rec(i-1,j));
    }

    // save and return 
    return dp[i][j] = ans;
}

void solve(){
    cin>>a>>b;
    n = a.size();
    m = b.size();

    memset(dp,-1,sizeof(dp));
    int ans = rec(n-1,m-1);

    if(ans==inf){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
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