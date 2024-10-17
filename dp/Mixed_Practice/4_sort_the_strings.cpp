#include<bits/stdc++.h>
#define inf 1e18 
#define int long long
#define endl "\n"

using namespace std;

int n;
vector<int> arr;
vector<string> s;

bool isSorted(const string& a, const string& b) {
    int minSize = min(a.size(), b.size());
    for (int i = 0; i < minSize; ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return a.size() <= b.size();
}

void solve(){
    cin>>n;

    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    s.resize(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, inf));
    dp[0][0] = 0;
    dp[0][1] = arr[0];

    for(int i=1;i<n;i++){
        string curr = s[i];
        string curr_rev = s[i];
        reverse(curr_rev.begin(), curr_rev.end());

        string prev = s[i-1];
        string prev_rev = prev;
        reverse(prev_rev.begin(), prev_rev.end());

        if(isSorted(prev,curr)){
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        }
        if(isSorted(prev_rev,curr)){
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }
        if(isSorted(prev,curr_rev)){
            dp[i][1] = min(dp[i][1], dp[i-1][0]+arr[i]);
        }
        if(isSorted(prev_rev,curr_rev)){
            dp[i][1] = min(dp[i][1], dp[i-1][1]+arr[i]);
        }
    }

    int ans = min(dp[n-1][0],dp[n-1][1]);
    if(ans == inf){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    while(T--){
        arr.clear();
        s.clear();
        solve();
    }

    return 0;
}