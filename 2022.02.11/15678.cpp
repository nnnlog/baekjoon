#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

vl seg;

ll upd(int node, int start, int end, int k, ll v) {
    if (!(start <= k && k <= end)) return seg[node];
    if (start == end) return seg[node] = v;
    int mid = (start + end) >> 1;
    return seg[node] = max(upd(node * 2, start, mid, k, v), upd(node * 2 + 1, mid + 1, end, k, v));
}

ll qry(int node, int start, int end, int l, int r) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return seg[node];
    int mid = (start + end) >> 1;
    return max(qry(node * 2, start, mid, l, r), qry(node * 2 + 1, mid + 1, end, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k; cin >> n >> k;
    seg.resize(4 * n);

    vi vec(n + 1);
    for (int &i : vec | views::drop(1)) cin >> i;

    ll ans = -1e18;
    for (int i = 1; i <= n; i++) {
        ll ok = qry(1, 1, n, max(1, i - k), i - 1) + vec[i];
        ans = max(ans, ok);
        upd(1, 1, n, i, ok);
    }
    cout << ans;
}
