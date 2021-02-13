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

vl seg, lazy, vec;

ll init(int node, int start, int end) {
	if (start == end) return seg[node] = vec[start];
	int mid = (start + end) >> 1;
	return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int l, int r, ll diff) {
	if (lazy[node]) {
		seg[node] += lazy[node] * (end - start + 1);
		if (start != end)
			lazy[node * 2] += lazy[node], lazy[node * 2 + 1] += lazy[node];
		lazy[node] = 0;
	}
	if (start > r || end < l) return;
	if (l <= start && end <= r) {
		seg[node] += diff * (end - start + 1);
		if (start != end)
			lazy[node * 2] += diff, lazy[node * 2 + 1] += diff;
		return;
	}
	int mid = (start + end) >> 1;
	update(node * 2, start, mid, l, r, diff);
	update(node * 2 + 1, mid + 1, end, l, r, diff);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll sum(int node, int start, int end, int l, int r) {
	if (lazy[node]) {
		seg[node] += lazy[node] * (end - start + 1);
		if (start != end)
			lazy[node * 2] += lazy[node], lazy[node * 2 + 1] += lazy[node];
		lazy[node] = 0;
	}
	if (start > r || end < l) return 0;
	if (l <= start && end <= r) return seg[node];
	int mid = (start + end) >> 1;
	return sum(node * 2, start, mid, l, r) + sum(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k; cin >> n >> m >> k;
	seg.resize(n * 4), lazy.resize(n * 4);
	vec.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> vec[i];
	init(1, 1, n);
	//cout << sum(1, 1, n, 2, 5) << "\n";
	for (int i = 0; i < m + k; i++) {
		int h; cin >> h;
		if (h == 1) {
			ll a, b, c; cin >> a >> b >> c;
			update(1, 1, n, a, b, c);
		} else {
			int a, b; cin >> a >> b;
			cout << sum(1, 1, n, a, b) << "\n";
		}
	}
}
