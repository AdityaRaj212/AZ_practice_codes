#include<bits/stdc++.h>
#define endl "\n"
#define int long long 

using namespace std;

string a,b;
int n,m;
int dp[1010][1010];

int rec(int l1, int l2){
    // pruning

    // base case
    if(l1>=n || l2>=m){
        return 0;
    }

    // cache check
    if(dp[l1][l2]!=-1){
        return dp[l1][l2];
    }

    // transition
    int ans = 0;
    if(a[l1]==b[l2]){
        ans = max(ans,1+rec(l1+1,l2+1));
    }

    // save and return
    return dp[l1][l2] = ans;
}

void solve(){
    cin>>a>>b;
    n = a.size();
    m = b.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = -1;
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans,rec(i,j));
        }
    }
    cout<<ans<<endl;
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