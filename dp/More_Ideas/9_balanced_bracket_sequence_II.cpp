// Iterative approach

#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define mod 1000000007

using namespace std;

string s;
int n;
int dp[1010][1010];

void solve(){
    cin>>s;
    n = s.size();

    for(int i=0;i<1010;i++){
        for(int j=0;j<1010;j++){
            dp[i][j] = 0;
        }
    }
    
    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(s[i]=='?'){
                if(j+1<=n){
                    dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j])%mod;
                }
                if(j-1>=0){
                    dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j])%mod;
                }
            }else if(s[i]=='('){
                if(j+1<=n){
                    dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j])%mod;
                }
            }else if(s[i]==')'){
                if(j-1>=0){
                    dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j])%mod;
                }
            }
        }
    }

    cout<<dp[n][0]<<endl;
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