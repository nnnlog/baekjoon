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

struct A {
	ll min, min_idx, sum;
};

struct B {
	ll val, l, r;

	bool operator<(const B &b) const {
		if (val < b.val) return true;
		return false;
	}
};

A merge(A a, A b) {
	if (a.min > b.min) swap(a, b);
	a.sum += b.sum;
	return a;
}

int n;
vi vec;
vector<A> seg;

A init(int node, int start, int end) {
	if (start == end) return seg[node] = {vec[start], start, vec[start]};
	int mid = (start + end) >> 1;
	return seg[node] = merge(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

A get_min(int node, int start, int end, int l, int r) {
	if (start > r || end < l) return {(int) 1e9};
	if (l <= start && end <= r) return seg[node];
	int mid = (start + end) >> 1;
	return merge(get_min(node * 2, start, mid, l, r), get_min(node * 2 + 1, mid + 1, end, l, r));
}

ll get_sum(int node, int start, int end, int l, int r) {
	if (start > r || end < l) return 0;
	if (l <= start && end <= r) return seg[node].sum;
	int mid = (start + end) >> 1;
	return get_sum(node * 2, start, mid, l, r) + get_sum(node * 2 + 1, mid + 1, end, l, r);
}

B solve(int l, int r) {
	if (l > r) return {0, l, r};
	A mn = get_min(1, 1, n, l, r);
	return max({get_sum(1, 1, n, l, r) * mn.min, l, r},
	           max(solve(l, mn.min_idx - 1), solve(mn.min_idx + 1, r)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vec.resize(n + 1), seg.resize(n * 4);
	for (auto &i : vec | views::drop(1)) cin >> i;
	init(1, 1, n);
	B ans = solve(1, n);
	cout << ans.val << "\n" << ans.l << " " << ans.r;
}
