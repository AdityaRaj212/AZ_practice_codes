#include<bits/stdc++.h>
using namespace std;

int dp[1000000];

int rec(int chips){
    // pruning

    // base case
    if(chips==0){
        return 0;
    }

    // cache check
    if(dp[chips]!=-1){
        return dp[chips];
    }

    // transition
    int ans = 0;
    for(int i=0;(1<<i)<=chips;i++){
        if(rec(chips-(1<<i))==0){
            ans = 1;
            break;
        }
    }

    // save and return
    return dp[chips] = ans;
}

void solve(){
    int x;
    cin>>x;
    memset(dp,-1,sizeof(dp));
    if(x%3){
        cout<<"Vivek"<<endl;
    }else{
        cout<<"Abhishek"<<endl;
    }
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