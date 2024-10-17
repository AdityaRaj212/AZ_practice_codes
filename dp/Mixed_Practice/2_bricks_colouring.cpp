#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define endl "\n"

using namespace std;

int n,m,k;
int dp[2002][2002];

void solve(){
    cin>>n>>m>>k;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = 0;
        }
    }

    // this dp[i][j] represents the number of ways to colour i bricks such that there are j 
    // different colours

    dp[1][0] = m;
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*(m-1))%mod;
        }
    }

    cout<<dp[n][k]<<endl;
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