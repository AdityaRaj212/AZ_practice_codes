#include<bits/stdc++.h>
using namespace std;

int n;
int W;
int weight[3000];
int value[3000];
int dp[3000][3000];

int rec(int level, int weight_left){
    // base case
    if(level==n){
        return 0;
    }

    // pruning

    // cache check
    if(dp[level][weight_left]!=-1){
        return dp[level][weight_left];
    }

    // transition
    int ans = rec(level+1,weight_left);
    if(weight[level]<=weight_left){
        ans = max(ans,value[level] + rec(level,weight_left-weight[level]));
    }

    // save and return 
    return dp[level][weight_left] = ans;
}

void solve(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    for(int i=0;i<n;i++){
        cin>>value[i];
    }

    cin>>W;

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W);
}

signed main(){
    solve();
    return 0;
}