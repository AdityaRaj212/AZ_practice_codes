/*
There are N bags each having a certain value arr[i], in each step you are allowed to merge
two adjacent bags and the value of the resultant bag will be sum of the value of two bags and 
upon doing this you get a benefit of x*y (x and y are values of the bag). Find the maximum
benefit possible after merging all the bags.
*/

#include<bits/stdc++.h>
#define inf 1e9
#define endl "\n"
#define int long long

using namespace std;

int n;
vector<int> arr;
int dp[101][101];

int rec(int l, int r){
    // pruning

    // base case
    if(l==r){
        return 0;
    }

    // cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    // transition
    int ans = -inf;
    int tot = 0;
    int sum = 0;
    for(int i=l;i<=r;i++){
        tot += arr[i];
    }

    for(int i=l;i<r;i++){
        sum += arr[i];
        ans = max(ans,rec(l,i)+rec(i+1,r)+(sum%100)*((tot-sum)%100));
    }

    // save and return 
    return dp[l][r] = ans;
}

void solve(){
    cin>>n;
    
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

signed main(){
    solve();
    return 0;
}