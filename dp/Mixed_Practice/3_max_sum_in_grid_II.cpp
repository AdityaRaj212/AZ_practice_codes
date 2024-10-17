#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> arr;

int kadane(const vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}

void solve() {
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        arr[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = INT_MIN;

    if (m < n) {
        for (int c1 = 0; c1 < m; ++c1) {
            vector<int> rowSum(n, 0);
            for (int c2 = c1; c2 < m; ++c2) {
                for (int r = 0; r < n; ++r) {
                    rowSum[r] += arr[r][c2];
                }
                ans = max(ans, kadane(rowSum));
            }
        }
    } else {
        for (int r1 = 0; r1 < n; ++r1) {
            vector<int> colSum(m, 0);
            for (int r2 = r1; r2 < n; ++r2) {
                for (int c = 0; c < m; ++c) {
                    colSum[c] += arr[r2][c];
                }
                ans = max(ans, kadane(colSum));
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
