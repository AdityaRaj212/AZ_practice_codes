#include <bits/stdc++.h>
#define int long long

using namespace std;

struct node {
    int lsum, rsum, msum, totsum;

    node(int _lsum = INT_MIN, int _rsum = INT_MIN, int _msum = INT_MIN, int _totsum = 0) {
        lsum = _lsum;
        rsum = _rsum;
        msum = _msum;
        totsum = _totsum;
    }
};

int n, m;
vector<int> arr;
vector<node> tree;

node merge(node a, node b) {
    int lsum = max(a.lsum, a.totsum + b.lsum);
    int rsum = max(b.rsum, b.totsum + a.rsum);
    int msum = max({a.msum, b.msum, a.rsum + b.lsum});
    int totsum = a.totsum + b.totsum;
    return node(lsum, rsum, msum, totsum);
}

void build(int index, int l, int r) {
    if (l == r) {
        tree[index] = node(arr[l], arr[l], arr[l], arr[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

node query(int index, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return node();
    }
    if (ql <= l && qr >= r) {
        return tree[index];
    }

    int mid = (l + r) / 2;
    node left = query(2 * index, l, mid, ql, qr);
    node right = query(2 * index + 1, mid + 1, r, ql, qr);
    return merge(left, right);
}

void update(int index, int l, int r, int pos, int val) {
    if (pos < l || pos > r) {
        return;
    }

    if (l == r) {
        arr[l] = val;
        tree[index] = node(val, val, val, val);
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * index, l, mid, pos, val);
    } else {
        update(2 * index + 1, mid + 1, r, pos, val);
    }
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

void solve() {
    cin >> n >> m;

    arr.resize(n + 1);
    tree.resize(4 * n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (m--) {
        int pos, val;
        cin >> pos >> val;
        update(1, 1, n, pos, val);
        cout << query(1, 1, n, 1, n).msum << endl;
    }
}

signed main() {
    solve();
    return 0;
}
