#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

vl height, t, l, r, seg;

ll init(int node, int start, int end) {
	if (start == end) return seg[node] = height[start];
	int mid = start + end >> 1;
	return seg[node] = max(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

ll query(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (left > end || start > right) return 0;
	int mid = start + end >> 1;
	return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	height.resize(n);
	for (auto &i : height) cin >> i;

	t.resize(n - 1);
	for (auto &i : t) cin >> i;

	l.resize(n), r.resize(n);

	vi sum(n);
	ll curr_time = 0;
	for (int i = 0; i < n; i++) {
		if (i) {
			r[i] = r[i - 1];
			if (r[i] >= i) curr_time -= t[i - 1];
		}
		int f = 0;
		//if (r[i] < i) r[i] = i, curr_time = 0;
		while (r[i] < n && height[r[i]] >= curr_time) {
			if (r[i] + 1 != i) curr_time += t[r[i]];
			++r[i];
			//f = 1;
		}
		if (r[i] > i) {
			//--r[i];
			//curr_time -= t[r[i]];
		}
		//cout << i << " " << r[i] << " " << curr_time << "\n";
	}

	curr_time = 0;
	l[n - 1] = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (i < n - 1) {
			l[i] = l[i + 1];
			if (l[i] <= i) curr_time -= t[i];
		}
		//if (l[i] > i) l[i] = i, curr_time = 0;
		int f = 0;
		while (l[i] >= 0 && height[l[i]] >= curr_time) {
			if (l[i] > 0) curr_time += t[l[i] - 1];
			--l[i];
			f = 1;
		}
		//cout << i << " " << l[i] << " " << curr_time << "\n";
		if (f) {
			//++l[i];
			//curr_time -= t[l[i] - 1];
		}
		//cout << i << " " << l[i] << " " << curr_time << "\n";
	}

	seg.resize(n * 4);
	init(1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		//cout << l[i] << " " << r[i] << "\n";
		cout << query(1, 0, n - 1, l[i] + 1LL, r[i] - 1LL) << " ";
	}
}
