// Form 1 - Knapsack

#include<bits/stdc++.h>
#define endl "\n"
#define inf 1e9
#define int long long

using namespace std;

int n;
string s;
vector<int> cost;

int rec(int level, int match){
    // this returns the min cost for removing any occurence of "hard" as a subseq in s

    // pruning

    // base case
    if(level==n){
        return 0;
    }

    // cache check
    int ans = inf;
    

    // transition

    // save and return
}

void solve(){
    cin>>n;
    cin>>s;

    cost.resize(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
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