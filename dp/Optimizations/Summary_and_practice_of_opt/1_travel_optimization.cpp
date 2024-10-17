// DP Form - 2

// Space optimization
// Time optimization using monotone deque

#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define endl "\n"

using namespace std;

struct monotone_deque{
    deque<int> dq;

    void insert(int x){
        while(!dq.empty() && dq.back()>x){
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void erase(int x){
        if(dq.front()==x){
            dq.pop_front();
        }
    }

    int getmin(){
        return dq.front();
    }
};

int n,m,k;
int bus[1010101];
int flight[1010101];
int dp[2][1010101];

void solve(){
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++){
        cin>>bus[i];
    }

    for(int i=1;i<=n;i++){
        cin>>flight[i];
    }

    int ans = inf;

    for(int left=0;left<=m;left++){
        monotone_deque dq;
        for(int i=1;i<=n;i++){
            if(i==1){
                if(left==0){
                    dp[left&1][i] = 0; 
                }else{
                    dp[left&1][i] = inf;
                }
            }else{
                dp[left&1][i] = dp[left&1][i-1]+bus[i-1];
                if(left>0){
                    dq.insert(dp[(left-1)&1][i-1]+flight[i-1]);

                    if(i-k-1>=1){
                        dq.erase(dp[(left-1)&1][i-k-1]+flight[i-k-1]);
                    }

                    dp[left&1][i] = min(dp[left&1][i], dq.getmin()+flight[i]);

                    // for(int x=1;x<=k;x++){
                    //     if(i-x>=1){
                    //         dp[left&1][i] = min(dp[left&1][i], dp[(left-1)&1][i-x]+flight[i-x]+flight[i]);
                    //     }
                    // }
                }
            }
        }
        ans = min(ans, dp[left&1][n]);
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