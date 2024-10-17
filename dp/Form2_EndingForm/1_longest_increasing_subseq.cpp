#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int dp[10010];

int rec(int level){
    // pruning
    if(level<0){
        return 0;
    }

    // base case

    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }

    // transition
    int ans = 0;
    for(int i=0;i<level;i++){
        if(arr[level]>arr[i]){
            ans = max(ans, 1+rec(i));
        }
    }

    // save and return 
    return dp[level] = ans;
}

void solve(){
    cin>>n;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxLen = 0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        maxLen = max(maxLen,rec(i));
    }

    cout<<maxLen<<endl;
}

signed main(){
    solve();
    return 0;
}