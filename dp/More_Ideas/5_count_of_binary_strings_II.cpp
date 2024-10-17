// Form 2 
// Bottom-up approach

#include<bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int n;
int dp[1010101][5];

void generateDP(){
    // this dp[level][m] returns the number of req strings in [level...n] with exactly m matches

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;

    for(int i=1;i<1010101;i++){
        for(int j=0;j<5;j++){
            if(j==0){
                dp[i][j] = (dp[i-1][0]+dp[i-1][2])%mod;
            }else if(j==1){
                dp[i][j] = (dp[i-1][0]+dp[i-1][1])%mod;
            }else if(j==2){
                dp[i][j] = (dp[i-1][1]+dp[i-1][3])%mod;
            }else if(j==3){
                dp[i][j] = (dp[i-1][2])%mod;
            }
        }
    }
}

void solve(){
    cin>>n;
    int ans = (dp[n][0]+dp[n][1])%mod;
    ans = (ans+dp[n][2])%mod;
    ans = (ans+dp[n][3])%mod;
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    generateDP();

    while(T--){
        solve();
    }

    return 0;
}