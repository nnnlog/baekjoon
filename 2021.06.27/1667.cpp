#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

const int SZ = 200000, add = 1e5;
int seg[SZ * 4];

void upd(int node, int start, int end, int l, int r, int k) {
	if (l <= start && end <= r) {
		seg[node] = k;
		return;
	}
	if (seg[node]) {
		if (node * 2 <= SZ * 4) seg[node * 2] = seg[node];
		if (node * 2 + 1 <= SZ * 4) seg[node * 2 + 1] = seg[node];
		seg[node] = 0;
	}
	int mid = (start + end) >> 1;
	if (l <= mid) upd(node * 2, start, mid, l, r, k);
	if (mid < r) upd(node * 2 + 1, mid + 1, end, l, r, k);
}

int qry(int node, int start, int end, int k) {
	if (seg[node] || start == end) return seg[node];
	int mid = (start + end) >> 1;
	if (k <= mid) return qry(node * 2, start, mid, k);
	return qry(node * 2 + 1, mid + 1, end, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, s;
	cin >> n >> s;
	vpii vec(n + 1);
	vpii dp(n + 1, {1e18, 1e18});
	dp[0] = {0, 0};
	for (auto &[a, b] : vec | drop(1)) cin >> a >> b;
	std::reverse(vec.begin() + 1, vec.end());
	for (int i = 1; i <= n; i++) {
		int a = vec[i].first, b = vec[i].second;
		int x = qry(1, 0, SZ, a + add), y = qry(1, 0, SZ, b + add);
		dp[i].first = min(dp[x].first + abs(vec[x].first - a), dp[x].second + abs(vec[x].second - a));
		dp[i].second = min(dp[y].first + abs(vec[y].first - b), dp[y].second + abs(vec[y].second - b));
		upd(1, 0, SZ, a + add, b + add, i);
	}
	cout << min(dp[n].first + abs(s - vec.back().first), dp[n].second + abs(s - vec.back().second));
}
