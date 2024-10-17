// Dimensional reduction
// DP Form - 2

#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> arr;
vector<int> dp;

int getBestSubarraySum(int level, vector<int> arr){
    // this returns the max sum of any subarray in an array

    // pruning

    // base case
    if(level<0){
        return 0;
    }

    // cache check

    // transition
    if (level == 0) {
        dp[level] = arr[level];
    } else {
        dp[level] = max(arr[level], arr[level] + getBestSubarraySum(level - 1, arr));
    }

    // save and return 
    return dp[level];
}

void solve(){
    cin>>n>>m;

    arr.resize(n);
    for(int i=0;i<n;i++){
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int ans = INT_MIN;

    if(m<n){
        for(int c1=0;c1<m;c1++){
            vector<int> rowSum(n,0);
            for(int c2=c1;c2<m;c2++){
                for(int r=0;r<n;r++){
                    rowSum[r]+=arr[r][c2];
                }
                dp.assign(n, INT_MIN); // reset dp array for each subarray calculation
                for (int i = 0; i < n; i++) {
                    ans = max(ans, getBestSubarraySum(i, rowSum));
                }
            }
        }
    }else{
        for(int r1=0;r1<n;r1++){
            vector<int> colSum(m,0);
            for(int r2=r1;r2<n;r2++){
                for(int c=0;c<m;c++){
                    colSum[c] += arr[r2][c];
                }
                dp.assign(m, INT_MIN); // reset dp array for each subarray calculation
                for (int i = 0; i < m; i++) {
                    ans = max(ans, getBestSubarraySum(i, colSum));
                }
            }
        }
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