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

vi seg, lazy;

int upd(int node, int start, int end, int l, int r) {
	if (lazy[node] % 2) {
		if (start != end) ++lazy[node * 2], ++lazy[node * 2 + 1];
		seg[node] = (end - start + 1) - seg[node];
	}
	lazy[node] = 0;
	if (start > r || end < l) return seg[node];
	if (l <= start && end <= r) {
		seg[node] = (end - start + 1) - seg[node];
		if (start != end) ++lazy[node * 2], ++lazy[node * 2 + 1];
		return seg[node];
	}
	int mid = (start + end) >> 1;
	return seg[node] = upd(node * 2, start, mid, l, r) + upd(node * 2 + 1, mid + 1, end, l, r);
}

int qry(int node, int start, int end, int l, int r) {
	if (lazy[node] % 2) {
		if (start != end) ++lazy[node * 2], ++lazy[node * 2 + 1];
		seg[node] = (end - start + 1) - seg[node];
	}
	lazy[node] = 0;
	if (start > r || end < l) return 0;
	if (l <= start && end <= r) return seg[node];
	int mid = (start + end) >> 1;
	return qry(node * 2, start, mid, l, r) + qry(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	seg.resize(n * 4);
	lazy.resize(n * 4);

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (!a) upd(1, 1, n, b, c);
		else cout << qry(1, 1, n, b, c) << "\n";
	}
}
