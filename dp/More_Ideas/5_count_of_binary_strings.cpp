// ** This is a top down approach which will give tle for large number of test cases
// Form 1

#include<bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

int n;
int dp[1010101][5];

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
    int ans;

    if(match==0){
        ans = rec(level+1,0)+rec(level+1,1);
    }else if(match==1){
        ans = rec(level+1,1)+rec(level+1,2);
    }else if(match==2){
        ans = rec(level+1,3)+rec(level+1,0);
    }else if(match==3){
        ans = rec(level+1,4)+rec(level+1,2);
    }

    // save and return
    return dp[level][match] = ans;
}

void solve(){
    cin>>n;

    for(int i=0;i<=n;i++){
        for(int j=0;j<5;j++){
            dp[i][j] = -1;
        }
    }
    cout<<rec(0,0)<<endl;
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