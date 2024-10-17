// this code is for printing the lis

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> parent;
int dp[10010];

int rec(int level){
    // pruning
    if(level<0){
        return 0;
    }

    // base case

    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }

    // transition
    int ans = 0;
    for(int i=0;i<level;i++){
        if(arr[level]>arr[i]){
            int val = 1+rec(i);
            if(val>ans){
                ans = val;
                parent[level] = i;
            }
            ans = max(ans, 1+rec(i));
        }
    }

    // save and return 
    return dp[level] = ans;
}

void printLis(int endIndex){
    vector<int> lis;
    for(int i=endIndex;i!=-0;i=parent[i]){
        lis.push_back(arr[i]);
    }

    reverse(lis.begin(), lis.end());

    for(int num: lis){
        cout<<num<<" ";
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

    int maxLen = 0;
    int endIndex = -1;
    memset(dp,-1,sizeof(dp));
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