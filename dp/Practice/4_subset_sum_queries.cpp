#include <bits/stdc++.h>
#define MP make_pair

using namespace std;


#define ll int64_t

int n;
vector<pair<int, pair<int,int>>> allCombinations;

void genAll(vector<int>& arr){
    vector<int> prefixSum(n+1, 0);
    for(int i=0;i<n;i++){
        prefixSum[i+1] = prefixSum[i] + arr[i];
    }

    allCombinations.resize(n*n);

    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            allCombinations.push_back(prefixSum[r]-prefixSum[l-1]);
        }
    }

    sort(allCombinations.begin(), allCombinations.end());
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    n = arr.size();

    return {};
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
    freopen("input.txt", "r", stdin); \
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
