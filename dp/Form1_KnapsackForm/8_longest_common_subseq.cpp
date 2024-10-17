#include<bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

string s,t;
int m,n;
int dp[1010][1010];

int rec(int indS, int indT){
    // pruning

    // base case
    if(indS==m || indT==n){
        return 0;
    }

    // cache check
    if(dp[indS][indT]!=-1){
        return dp[indS][indT];
    }

    // transition

    int ans;
    if(s[indS]==t[indT]){
        ans = 1 + rec(indS+1, indT+1);
    }else{
        // don't take
        // ans = rec(indS+1,indT+1);
        
        // take any one
        ans = max(rec(indS+1,indT),rec(indS,indT+1));
    } 

    // save and return 
    return dp[indS][indT] = ans;
}

void solve(){
    cin>>s>>t;
    m = s.size();
    n = t.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

signed main(){
    solve();
    return 0;
}