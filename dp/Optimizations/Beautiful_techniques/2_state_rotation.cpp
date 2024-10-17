#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

int n,w;
int weight[101];
int value[101];

int dp[101][101010];

int rec(int i, int profit){
    // this returns the min weight required in [0...i] to get profit amonunt of value in bag

    // pruning

    // base case
    if(i==n){
        if(profit==0){
            return 0;
        }
        return inf;
    }

    // cache check
    if(dp[i][profit]!=-1){
        return dp[i][profit];
    }

    // transition
    int ans = rec(i+1,profit);
    if(profit>=value[i]){
        ans = min(ans, weight[i]+rec(i+1,profit-value[i]));
    }

    // save and return 
    return dp[i][profit] = ans;
}

void solve(){
    cin>>n>>w;

    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }

    memset(dp,-1,sizeof(dp));

    int ans = 0;
    for(int p=1;p<101010;p++){
        if(rec(0,p)<=w){
            ans = p;
        }
    }

    cout<<ans<<endl;
}

signed main(){
    solve();
    return 0;
}

// #include<bits/stdc++.h>
// #define inf 1e9

// using namespace std;

// int n,w;
// int weight[101];
// int value[101];

// int dp[101][101010];

// int rec(int i, int p){
//     // pruning

//     // base case
//     if(i==n){
//         if(p==0){
//             return 0;
//         }else{
//             return inf;
//         }
//     }

//     // cache check
//     if(dp[i][p]!=-1){
//         return dp[i][p];
//     }

//     // transition
//     int ans = rec(i+1,p);   
//     if(p>=value[i]){
//         ans = min(ans, weight[i]+rec(i+1,p-value[i]));
//     }

//     // save and return 
//     return dp[i][p] = ans;
// }

// void solve(){
//     cin>>n>>w;

//     for(int i=0;i<n;i++){
//         cin>>weight[i]>>value[i];
//     }

//     memset(dp,-1,sizeof(dp));

//     int ans = 0;
//     for(int p=1;p<=100101;p++){
//         if(rec(0,p)<=w){
//             ans = p;
//         }
//     }

//     cout<<ans<<endl;
// }

// signed main(){
//     solve();
//     return 0;
// }