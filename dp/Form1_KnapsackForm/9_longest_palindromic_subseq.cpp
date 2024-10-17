#include<bits/stdc++.h>
#define inf 1e9
#define endl "\n"

using namespace std;

string a,b;
int n;
int dp[105][105];

int rec(int l1, int l2){
    // pruning
    if(l1>n || l2>n){
        return -inf;
    }

    // base case
    if(l1==n || l2==n){
        return 0;
    }

    // cache check
    if(dp[l1][l2]!=-1){
        return dp[l1][l2];
    }

    // transition
    int ans = max(rec(l1+1,l2),rec(l1,l2+1));
    if(a[l1]==b[l2]){
        ans = max(ans, 1 + rec(l1+1,l2+1));
    }

    // save and return
    return dp[l1][l2] = ans;
}   

int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    n = s.size();
    a = s;
    b = string(s.rbegin(), s.rend());

    memset(dp,-1,sizeof(dp));
    return rec(0,0);
}

void solve(){
    string s;
    cin>>s;
    cout<<longestPalindromeSubsequence(s);
}

signed main(){
    int T;
    cin>>T;

    while(T--){
        solve();
    }

    return 0;
}