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

vl seg, lazy, B;

ll init(int node, int start, int end) {
	if (start == end) return seg[node] = B[start];
	int mid = (start + end) >> 1;
	return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll upd(int node, int start, int end, int l, int r, int val) {
	if (lazy[node]) {
		if (node * 2 < seg.size()) lazy[node * 2] += lazy[node];
		if (node * 2 + 1 < seg.size()) lazy[node * 2 + 1] += lazy[node];
		seg[node] += lazy[node] * (end - start + 1);
		lazy[node] = 0;
	}
	if (end < l || r < start) return seg[node];
	if (l <= start && end <= r) {
		if (node * 2 < seg.size()) lazy[node * 2] += val;
		if (node * 2 + 1 < seg.size()) lazy[node * 2 + 1] += val;
		return seg[node] += val * (end - start + 1);
	}
	int mid = (start + end) >> 1;
	return seg[node] = upd(node * 2, start, mid, l, r, val) + upd(node * 2 + 1, mid + 1, end, l, r, val);
}

ll qry(int node, int start, int end, int l, int r) {
	if (lazy[node]) {
		if (node * 2 < seg.size()) lazy[node * 2] += lazy[node];
		if (node * 2 + 1 < seg.size()) lazy[node * 2 + 1] += lazy[node];
		seg[node] += lazy[node] * (end - start + 1);
		lazy[node] = 0;
	}
	if (end < l || r < start) return 0;
	if (l <= start && end <= r) return seg[node];
	int mid = (start + end) >> 1;
	return qry(node * 2, start, mid, l, r) + qry(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vi A(n + 1);
	B.resize(n + 1);
	seg.resize(n * 4), lazy.resize(n * 4);
	for (int &i : A | views::drop(1)) cin >> i;
	for (int i = 1; i <= n; i++) B[i] = A[i] - A[i - 1];
	init(1, 1, n);
	int m;
	cin >> m;
	while (m--) {
		int a;
		cin >> a;
		if (a == 1) {
			int l, r;
			cin >> l >> r;
			upd(1, 1, n, l, r, 1);
			if (r < n) upd(1, 1, n, r + 1, r + 1, -(r - l + 1));
		} else {
			int x;
			cin >> x;
			cout << qry(1, 1, n, 1, x) << "\n";
		}
	}
}
