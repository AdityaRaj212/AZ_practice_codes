#include<bits/stdc++.h>
using namespace std;

int n;

int rec(int level){
    // base case
    if(level==n){
        return 1;
    }

    int ans = 0;

    for(int step=1; step<=3;step++){
        if(level+step<=n){
            int ways = rec(level+step);
            ans += ways;
        }
    }

    return ans;
}

void solve(){
    cin>>n;
    cout<<rec(1);
}

signed main(){
    solve();
    return 0;
}