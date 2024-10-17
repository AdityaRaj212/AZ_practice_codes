// Form 1 - Knapsack with state space model

#include<bits/stdc++.h>
using namespace std;

int n;
string x = "1011";
int dp[10010][5];

int rec(int level, int match){
    // pruning
    if(match==4){
        return 0;
    }

    // base case
    if(level==n){
        return 1;
    }

    // cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }

    // transition
    int ans = 0;
    if(match==0){
        ans = rec(level+1,0)+rec(level+1,1);
    }else if(match==1){
        ans = rec(level+1,2)+rec(level+1,1);
    }else if(match==2){
        ans = rec(level+1,0)+rec(level+1,3);
    }else if(match==3){
        ans = rec(level+1,2)+rec(level+1,4);
    }

    // save and return 
    return dp[level][match] = ans;
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