#include<bits/stdc++.h>
#define inf 1e18 
#define int int64_t
#define endl "\n"

using namespace std;

int n;
vector<int> arr;
int dp[1010101];

void solve(){
    cin>>n;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int minProd = 1;
    int maxProd = 1;
    int ans = -inf;

    for(int i=0;i<n;i++){
        int temp = minProd;
        minProd = min({arr[i],minProd*arr[i],maxProd*arr[i]});
        maxProd = max({arr[i],temp*arr[i],maxProd*arr[i]});
        ans = max(ans,maxProd);
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