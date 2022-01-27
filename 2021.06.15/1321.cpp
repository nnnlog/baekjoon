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

vi seg, vec;

int init(int node, int start, int end) {
	if (start == end) return seg[node] = vec[start];
	int mid = (start + end) >> 1;
	return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int upd(int node, int start, int end, int k) {
	if (!(start <= k && k <= end)) return seg[node];
	if (start == end) return seg[node] = vec[k];
	int mid = (start + end) >> 1;
	return seg[node] = upd(node * 2, start, mid, k) + upd(node * 2 + 1, mid + 1, end, k);
}

int qry(int node, int start, int end, int k) {
	if (start == end) return start;
	int mid = (start + end) >> 1;
	if (seg[node * 2] >= k) return qry(node * 2, start, mid, k);
	else return qry(node * 2 + 1, mid + 1, end, k - seg[node * 2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	seg.resize(n * 4);
	vec.resize(n + 1);
	for (auto &i : vec | views::drop(1)) cin >> i;
	init(1, 1, n);
	int q; cin >> q;
	while (q--) {
		int a; cin >> a;
		if (a == 1) {
			int b, c; cin >> b >> c;
			vec[b] += c;
			upd(1, 1, n, b);
		} else {
			int b; cin >> b;
			cout << qry(1, 1, n, b) << "\n";
		}
	}
}
