#include <bits/stdc++.h>
using namespace std;


#define ll int64_t

int dp[102][100100];

int rec(int level, int left, vector<int>& arr){
    int n = arr.size();
    //  pruning

    // base case
    if(level==n){
        if(left==0){
            return 1;
        }else{
            return 0;
        }
    }

    // cache check
    if(dp[level][left]!=-1){
        return dp[level][left];
    }

    // transition
    int ans = 0;
    ans = rec(level+1,left,arr);
    if(arr[level]<=left){
        ans = rec(level+1,left-arr[level],arr);
    }

    // save and return 
    return dp[level][left] = ans;
}

void generate(int level, int left, vector<int>& arr, vector<int>& ansVector){
    int n = arr.size();

    if(level==n){
        return;
    }

    int ans = 0;
    ans = rec(level+1,left,arr);
    if(ans){
        generate(level+1,left,arr,ansVector);
    }else{
        if(arr[level]<=left){
            ans = rec(level+1,left-arr[level],arr);
            if(ans){
                ansVector.push_back(level);
                generate(level+1,left-arr[level],arr,ansVector);
            }
            else{
                ansVector.push_back(-1);
                return;
            }
        }
    }

    
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    vector<vector<int>> ans;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<queries.size();i++){
        int q = queries[i];
        vector<int> v;
        generate(0,q,arr,v);
        ans.push_back(v);
    }

    return ans;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
