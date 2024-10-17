// Form 1 - Knapsack

#include<bits/stdc++.h>
using namespace std;

int n;
string x = "0110";
int dp[1001][5];

int rec(int i, int match){
    // this returns the number of sub-sequences of s which doesn't contain x

    // pruning
    if(match==4){
        return 0;
    }

    // base case
    if(i==n){
        return 1;
    }


    // cache check
    if(dp[i][match]!=-1){
        return dp[i][match];
    }

    // transition
    int ans = rec(i+1,match+1)+rec(i+1,match);

    // save and return
    return dp[i][match] = ans;
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