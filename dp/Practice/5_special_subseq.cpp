#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

string s;
int n;
unordered_set<string> st;

// Custom hash function for the unordered_map
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, string>, int, hash_pair> cache;

int rec(int level, string str){
    // base case
    if (str.size() == 5) {
        return st.find(str) != st.end() ? 1 : 0;
    }
    if (level == n) {
        return 0;
    }

    // cache check
    auto memo_key = make_pair(level, str);
    if (cache.find(memo_key) != cache.end()) {
        return cache[memo_key];
    }

    // transition
    int ans = rec(level + 1, str) % mod;

    str.push_back(s[level]);
    ans = (ans + rec(level + 1, str)) % mod;

    // save and return
    cache[memo_key] = ans;
    return ans;
}

void solve(){
    st.insert("00000");
    st.insert("01010");
    st.insert("10001");
    st.insert("11011");
    st.insert("00100");
    st.insert("01110");
    st.insert("10101");
    st.insert("11111");

    cin >> s;
    n = s.size();
    string str;
    int ans = rec(0, str);

    cout << ans << endl;
}

signed main(){
    solve();
    return 0;
}
