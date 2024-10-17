#include<bits/stdc++.h>
#define MP make_pair
#define F first 
#define S second
#define int long long
#define endl "\n"
#define inf 1e18

using namespace std;

int n,m;
vector<vector<int>> arr;

void solve(){
    cin>>n>>m;

    arr.resize(n+1);
    for(int i=0;i<=n;i++){
        arr[i].resize(m+1);
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                arr[i][j] = 0;
            }else{
                cin>>arr[i][j];
            }
        }
    }

    int ans = -inf;

    pair<int,int> dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = MP(0,0);
            }else if(i==1 && j==1){
                dp[i][j] = MP(1,1);   
            }else{
                int h,h1,h2,h3;
                int w,w1,w2,w3;

                h1 = dp[i][j-1].F;
                w1 = dp[i][j-1].S;

                h2 = dp[i-1][j-1].F;
                w2 = dp[i-1][j-1].S;

                h3 = dp[i-1][j].F;
                w3 = dp[i-1][j].S;

                

                h = 1 + min({h1-1,h2,h3});
                w = 1 + min({w1,w2,w3-1});

                dp[i][j] = MP(h,w);

                ans = max(ans,h*w);
            }
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