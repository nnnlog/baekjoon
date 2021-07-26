#include <bits/stdc++.h>

using namespace std;

vector<int> sequence(100001);
vector<vector<int>> seg;

vector<int> init(int node, int start, int end) {
	if (start == end) return seg[node] = {sequence[start]};
	int mid = start + end >> 1;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg[node].resize(seg[node * 2].size() + seg[node * 2 + 1].size());
	merge(
			seg[node * 2].begin(), seg[node * 2].end(),
			seg[node * 2 + 1].begin(), seg[node * 2 + 1].end(),
			seg[node].begin()
	);
	return seg[node];
}

int query(int node, int start, int end, int left, int right, int k) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return upper_bound(seg[node].begin(), seg[node].end(), k) - seg[node].begin();
	int mid = start + end >> 1;
	return query(node * 2, start, mid, left, right, k) + query(node * 2 + 1, mid + 1, end, left, right, k);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> sequence[i];

	seg.resize(n * 4);

	init(1, 1, n);
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;

		int x = -1e9, y = 1e9;
		while (x < y) {
			int mid = x + y >> 1;
			if (query(1, 1, n, l, r, mid) < k) x = mid + 1;
			else y = mid;
		}
		cout << x << "\n";
	}
}
