#include<bits/stdc++.h>
#define inf 1e18
#define int long long

using namespace std;

string s1, s2, s3;
int n1, n2, n3;
int dp[105][105][105];

int rec(int l1, int l2, int l3){
    // pruning 
    if(l1<0 || l2<0 || l3<0){
        return -inf;
    }

    // base case
    if(l1==0 || l2==0 || l3==0){
        return 0;
    }

    // cache check
    if(dp[l1][l2][l3]!=-1){
        return dp[l1][l2][l3];
    }

    // transition
    int ans;
    if(s1[l1]==s2[l2] && s1[l1]==s3[l3] && s2[l2]==s3[l3]){
        ans = 1 + rec(l1-1, l2-1, l3-1);
    }else if(s1[l1]!=s2[l2] || s1[l1]!=s3[l3] || s2[l2]!=s3[l3]){
        ans = max(rec(l1,l2,l3-1),max(rec(l1,l2,l3-1),rec(l1-1,l2,l3)));
    }

    // save and return
    return dp[l1][l2][l3] = ans;
}

void solve(){
    cin>>s1>>s2>>s3;
    n1 = s1.size();
    n2 = s2.size();
    n3 = s3.size();

    memset(dp,-1,sizeof(dp));
    cout<<rec(n1-1,n2-1,n3-1)<<endl;
}

signed main(){
    int T;
    cin>>T;

    while(T--){
        solve();
    }

    return 0;
}