#include<bits/stdc++.h>
using namespace std;

int n,s,x;
int arr[1001];
int dp[2][1001];

void solve(){
    cin>>n>>s>>x;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=n;i>=0;i--){
        for(int sum_left=0;sum_left<=s;sum_left++){
            if(i==n){
                if(sum_left==0){
                    dp[i&1][sum_left] = 1;
                }else{
                    dp[i&1][sum_left] = 0;
                }
                continue;
            }
            dp[i&1][sum_left] = dp[(i+1)&1][sum_left];
            if(sum_left-x-1>=0){
                dp[i&1][sum_left] -= dp[(i+1)&1][sum_left-x-1];
            }
        }

        for(int sum_left=1;sum_left<=s;sum_left++){
            dp[i&1][sum_left] += dp[i&1][sum_left-1];
        }
    }

    cout<<dp[0&1][s]-dp[0&1][s-1]<<endl;
}

signed main(){
    solve();
    return 0;
}