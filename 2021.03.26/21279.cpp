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

vl seg, cseg;

ll update(int node, int start, int end, int i, ll k) {
	if (!(start <= i && i <= end)) return seg[node];
	if (start == end) return seg[node] += k;
	int mid = (start + end) >> 1;
	return seg[node] = update(node * 2, start, mid, i, k) + update(node * 2 + 1, mid + 1, end, i, k);
}

ll query(int node, int start, int end, int l, int r) {
	if (start > r || end < l) return 0;
	if (l <= start && end <= r) return seg[node];
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}
ll cupdate(int node, int start, int end, int i) {
	if (!(start <= i && i <= end)) return cseg[node];
	if (start == end) return ++cseg[node];
	int mid = (start + end) >> 1;
	return cseg[node] = cupdate(node * 2, start, mid, i) + cupdate(node * 2 + 1, mid + 1, end, i);
}

ll cquery(int node, int start, int end, ll l, ll r) {
	if (start > r || end < l) return 0;
	if (l <= start && end <= r) return cseg[node];
	int mid = (start + end) >> 1;
	return cquery(node * 2, start, mid, l, r) + cquery(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, c;
	cin >> n >> c;
	seg.resize(100001 * 4), cseg.resize(100001 * 4);
	map<ll, vpll> vec;
	set<ll, greater<>> s;
	for (int i = 0; i < n; i++) {
		ll a, b, d;
		cin >> a >> b >> d;
		++b;
		vec[a].emplace_back(b, d);
		s.insert(b);
	}

	ll ans = 0;
	for (auto &[x, v] : vec) {
		sort(all(v), greater<>());
		for (const auto &[y, v] : v) {
			update(1, 1, 100001, y, v);
			cupdate(1, 1, 100001, y);
			//cout << "A" << query(1, 1, 100001, 1, y) << "\n";
		}
        
			ll s = 0, e = 1e9;
			while (s < e) {
				ll mid = (s + e) >> 1;
				if (cquery(1, 1, 100001, 1, mid) > c) e = mid - 1;
				else s = mid + 1;
			}
			ll k = s;
			if (k < 1 || cquery(1, 1, 100001, 1, k) <= c) ++k;
			if (k > 0 && cquery(1, 1, 100001, 1, k) > c) --k;

			if (cquery(1, 1, 100001, 1, k) > c) break;
			ans = max(ans, query(1, 1, 100001, 1, k));

	}
	cout << ans;
}
