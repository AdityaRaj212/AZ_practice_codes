// Form - 5 - Game DP

#include<bits/stdc++.h>
using namespace std;

int a,b;
int dp[1001][1001];

int rec(int x, int y){
    // this returns if the current player wins or lose

    // pruning

    // base case
    if(x==0 && y==0){
        return 0;
    }

    // cache check
    if(dp[x][y] != -1){
        return dp[x][y];
    }

    // transition
    int ans = 0;
    for(int z=0;z<x;z++){
        if(rec(z,y)==0){
            ans = 1;
            break;
        }
    }
    for(int z=1;z<y;z++){
        if(rec(x,z)==0){
            ans = 1;
            break;
        }
    }
    for(int z=1;z<=min(x,y);z++){
        if(rec(x-z,y-z)==0){
            ans = 1;
            break;
        }
    }

    // save and return 
    return dp[x][y] = ans;
}

void solve(){
    cin>>a>>b;

    memset(dp,-1,sizeof(dp));

    cout<<rec(a,b)<<endl;

    // Iterative approach

    for(int x=0;x<=a;x++){
        for(int y=0;y<=b;y++){
            // base case
            if(x==0 && y==0){
                dp[x][y] = 0;
            }

            // transition
            int ans = 0;
            for(int z=0;z<x;z++){
                if(dp[z][y]==0){
                    ans = 1;
                    break;
                }
            }
            for(int z=1;z<y;z++){
                if(dp[x][z]==0){
                    ans = 1;
                    break;
                }
            }
            for(int z=1;z<=min(x,y);z++){
                if(dp[x-z][y-z]==0){
                    ans = 1;
                    break;
                }
            }

            // save and return 
            dp[x][y] = ans;
        }
    }

    cout<<dp[a][b]<<endl;
}

signed main(){
    solve();
    return 0;
}