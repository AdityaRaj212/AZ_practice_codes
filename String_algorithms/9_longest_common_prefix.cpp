#include <bits/stdc++.h>
using namespace std;

int calculateLCP(const string& s1, const string& s2, int n) {
    int lcp = 0;
    while (lcp < n && s1[lcp] == s2[lcp]) {
        ++lcp;
    }
    return lcp;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int initialLCP = calculateLCP(s, t, n);
    int maxLCP = initialLCP;

    if (initialLCP == n) {
        cout << n << endl;
        return;
    }

    // Check for all mismatching pairs around the LCP
    for (int i = initialLCP; i < n; ++i) {
        for (int j = 0; j < initialLCP; ++j) {
            if (s[j] == t[i] && s[i] == t[j]) {
                int newLCP = initialLCP + 1;
                maxLCP = max(maxLCP, newLCP);
            } else if (s[j] == t[i] || s[i] == t[j]) {
                int newLCP = initialLCP + 1;
                maxLCP = max(maxLCP, newLCP);
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == t[initialLCP]) {
                swap(s[i], s[j]);
                int newLCP = calculateLCP(s, t, n);
                maxLCP = max(maxLCP, newLCP);
                swap(s[i], s[j]);
            }
        }
    }

    cout << maxLCP << endl;
}

int main() {
    solve();
    return 0;
}
