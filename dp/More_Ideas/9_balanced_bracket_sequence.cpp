// DP Form - 1 Knapsack

#include<bits/stdc++.h>
#define inf 1e9
#define int long long
#define endl "\n"
#define mod 1000000007

using namespace std;

string s;
int n;
int dp[1010][1010];

int rec(int level, int cnt){
    // this returns the number of options possible

    // pruning
    if(level>n){
        return 0;
    }
    if(cnt<0){
        return 0;
    }

    // base case
    if(level==n){
        if(cnt==0){
            return 1;
        }else{
            return 0;
        }
    }

    // cache check
    if(dp[level][cnt]!=-1){
        return dp[level][cnt];
    }

    // transition
    int ans = 0;
    if(s[level]=='?'){
        ans = (rec(level+1,cnt+1)%mod + rec(level+1,cnt-1)%mod)%mod;
    }else if(s[level]=='('){
        ans = rec(level+1,cnt+1)%mod;
    }else if(s[level]==')'){
        ans = rec(level+1,cnt-1)%mod;
    }
    

    // save and return 
    return dp[level][cnt] = ans;
}

void solve(){
    cin>>s;
    n = s.size();

    memset(dp,-1,sizeof(dp));
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