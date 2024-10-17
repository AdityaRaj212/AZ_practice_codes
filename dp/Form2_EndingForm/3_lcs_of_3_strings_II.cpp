#include<bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

string a,b,c;
int la,lb,lc;
int dp[105][105][105];

int rec(int l, int m, int n){
    // pruning

    // base case
    if(l==la || m==lb || n==lc){
        return 0;
    }

    // cache check
    if(dp[l][m][n]!=-1){
        return dp[l][m][n]; 
    }

    // transition
    int ans = max(rec(l+1,m,n),max(rec(l,m+1,n),rec(l,m,n+1)));
    if(a[l]==b[m] && a[l]==c[n] && b[m]==c[n]){
        ans = max(ans,1 + rec(l+1,m+1,n+1));
    }

    // save and return
    return dp[l][m][n] = ans; 
}

void solve(){
    cin>>a>>b>>c;
    la = a.size();
    lb = b.size();
    lc = c.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl;
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