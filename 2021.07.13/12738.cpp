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

vi seg;
vpii vec;

int upd(int node, int start, int end, int k, int val) {
	if (!(start <= k && k <= end)) return seg[node];
	if (start == end) return seg[node] = val;
	int mid = (start + end) >> 1;
	return seg[node] = max(upd(node * 2, start, mid, k, val), upd(node * 2 + 1, mid + 1, end, k, val));
}

int qry(int node, int start, int end, int l, int r) {
	if (end < l || r < start) return 0;
	if (l <= start && end <= r) return seg[node];
	int mid = (start + end) >> 1;
	return max(qry(node * 2, start, mid, l, r), qry(node * 2 + 1, mid + 1, end, l, r));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	seg.resize(n * 4), vec.resize(n);
	for (int i = 0; i < n; i++) cin >> vec[i].first, vec[i].second = i + 1;
	sort(all(vec), [&](pii a, pii b) {
		return a.first != b.first ? a.first < b.first : a.second > b.second;
	});
	int ans = 1;
	for (const auto &[_, k] : vec) {
		int mx = qry(1, 1, n, 1, k) + 1;
		ans = max(ans, mx);
		upd(1, 1, n, k, mx);
	}
	cout << ans;
}
