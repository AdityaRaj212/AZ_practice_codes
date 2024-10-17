// Form 1 - Knapsack

#include<bits/stdc++.h>
using namespace std;

int n;
string x = "1011";
int dp[1001][8];

int rec(int level, int lastThree){
    // this returns the number of substrings in [level...n-1] not containing x

    // pruning

    // base case
    if(level==n){
        return 1;
    }

    // cache check
    if(dp[level][lastThree]!=-1){
        return dp[level][lastThree];
    }

    // transition
    int ans;
    if(level>=3 && lastThree==5){ // lastThree = 101
        // don't allow 1
        ans = rec(level+1,(lastThree<<1|0)&7);
    }else{
        // add zero
        ans = rec(level+1,(lastThree<<1|0)&7);
        
        // add one
        ans += rec(level+1,(lastThree<<1|1)&7);
    }

    // save and return
    return dp[level][lastThree] = ans;
}

void solve(){
    cin>>n;
    
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

signed main(){
    solve();
    return 0;
}