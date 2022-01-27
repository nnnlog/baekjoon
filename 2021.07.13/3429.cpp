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
int n;

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

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		vpii vec(n);
		for (int i = 0; i < n; i++) cin >> vec[i].first, vec[i].second = i;
		sort(all(vec), [&](pii a, pii b) {
			return a.first != b.first ? a.first < b.first : a.second > b.second;
		});
		vi info(n);
		for (int i = 0; i < n; i++) info[vec[i].second] = i;

		seg.assign(n * 4, 0);

		vector<vi> dp(n, vi(2, 0));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int pos = vec[i].second;
			dp[i][0] = 1;
			if (pos && vec[info[pos - 1]] < vec[i]) dp[i][0] = dp[info[pos - 1]][0] + 1, dp[i][1] = dp[info[pos - 1]][1] + 1;
			dp[i][1] = max(dp[i][1], qry(1, 0, n - 1, 0, pos) + 1);
			ans = max(ans, max(dp[i][0], dp[i][1]));
			upd(1, 0, n - 1, pos, dp[i][0]);
		}
		cout << ans << "\n";
	}
}
