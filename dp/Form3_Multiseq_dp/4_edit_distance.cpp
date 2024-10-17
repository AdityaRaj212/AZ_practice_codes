#include<bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

string a,b;
int n,m;
int dp[505][505];

void solve(){
    cin>>a>>b;
    n = a.size();
    m = b.size();

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j] = j;
            }else if(j==0){
                dp[i][j] = i;
            }else{
                if(a[i-1]==b[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
    }

    cout<<dp[n][m]<<endl;
}

signed main(){
    solve();
    return 0;
}