#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> parent;
int dp[101010];

int rec(int level){
    // this return the lis in [0...level]

    // pruning

    // base case
    if(level<0){
        return 0;
    }

    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }

    /*
        3 5 1 7 8
    */

    // transition
    int ans = 0;
    for(int i=0;i<level;i++){
        if(arr[level]>arr[i]){
            int val = 1 + rec(i);
            if(val>ans){
                ans = val;
                parent[level] = i;
            }
        }
    }

    //  save and return
    return dp[level] = ans;
}

void printLis(int endIndex){
    vector<int> lis;
    for(int i=endIndex; i!=-1; i=parent[i]){
        lis.push_back(i);
    }
    reverse(lis.begin(), lis.end());

    for(auto v:lis){
        cout<<arr[v]<<" ";
    }
    cout<<endl;
}

void solve(){
    cin>>n;

    arr.resize(n);
    parent.assign(n,-1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int endIndex = -1;
    int maxLen = 1;

    memset(dp, -1, sizeof(dp));

    for(int i=0;i<n;i++){
        int len = rec(i);
        if(len>maxLen){
            maxLen = len;
            endIndex = i;
        }
    }

    cout<<maxLen<<endl;
    printLis(endIndex);
}

signed main(){
    solve();
    return 0;
}