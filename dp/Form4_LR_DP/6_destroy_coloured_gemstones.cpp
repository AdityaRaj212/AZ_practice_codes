#include<bits/stdc++.h>
#define inf 1e9
#define endl  "\n"
#define int long long

using namespace std;

int n;
vector<int> arr;
int dp1[111][111];
int dp2[111];

int palindromeCheck(int l, int r){
    // pruning

    // base case
    if(l>=r){
        return 1;
    }

    // cache check
    if(dp1[l][r]!=-1){
        return dp1[l][r];
    }

    // transition
    int ans = 0;
    if(arr[l]==arr[r] && palindromeCheck(l+1,r-1)){
        ans = 1;
    }

    // save and return 
    return dp1[l][r] = ans;
}

int rec(int ind){
    // this returns the min no of palindromes in [0...ind]

    // pruning
    if(ind<0){
        return 0;
    }

    // base case
    if(ind==0){
        return 1;
    }

    // cache check
    if(dp2[ind]!=-1){
        return dp2[ind];
    }

    // transition
    int ans = inf;
    for(int i=0;i<=ind;i++){
        if(palindromeCheck(i,ind)){
            ans = min(ans,1+rec(i-1));
        }
    }

    // save and return
    return dp2[ind] = ans;
}

void solve(){
    cin>>n;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cout<<rec(n-1)<<endl;
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