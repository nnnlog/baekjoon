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

vi merge(vi &A, vi &B) {
	vi C = A;
	for (int i = 0; i < C.size(); i++) C[i] += B[i];
	return C;
}

int arr[1025][1025], n, m;
vector<vi> seg;

int init_y(vi &seg_x, int x, int node, int start, int end) {
	if (start == end) return seg_x[node] = arr[x][start];
	int mid = (start + end) >> 1;
	return seg_x[node] = init_y(seg_x, x, node * 2, start, mid) + init_y(seg_x, x, node * 2 + 1, mid + 1, end);
}

vi &init_x(int node, int start, int end) {
	if (start == end) return init_y(seg[node], start, 1, 1, n), seg[node];
	int mid = (start + end) >> 1;
	return seg[node] = merge(init_x(node * 2, start, mid), init_x(node * 2 + 1, mid + 1, end));
}

void upd_y(vi &seg_x, int node, int start, int end, int y, int diff) {
	if (!(start <= y && y <= end)) return;
	seg_x[node] += diff;
	if (start != end) {
		int mid = (start + end) >> 1;
		upd_y(seg_x, node * 2, start, mid, y, diff), upd_y(seg_x, node * 2 + 1, mid + 1, end, y, diff);
	}
}

void upd_x(int node, int start, int end, int x, int y, int diff) {
	if (!(start <= x && x <= end)) return;
	upd_y(seg[node], 1, 1, n, y, diff);
	if (start != end) {
		int mid = (start + end) >> 1;
		upd_x(node * 2, start, mid, x, y, diff), upd_x(node * 2 + 1, mid + 1, end, x, y, diff);
	}
}

int qry_y(vi &seg_x, int node, int start, int end, int l, int r) {
	if (r < start || l > end) return 0;
	if (l <= start && end <= r) return seg_x[node];
	int mid = (start + end) >> 1;
	return qry_y(seg_x, node * 2, start, mid, l, r) + qry_y(seg_x, node * 2 + 1, mid + 1, end, l, r);
}

int qry_x(int node, int start, int end, int l, int r, int _l, int _r) {
	if (r < start || l > end) return 0;
	if (l <= start && end <= r) return qry_y(seg[node], 1, 1, n, _l, _r);
	int mid = (start + end) >> 1;
	return qry_x(node * 2, start, mid, l, r, _l, _r) + qry_x(node * 2 + 1, mid + 1, end, l, r, _l, _r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
	seg.assign(n * 4, vi(n * 4));
	init_x(1, 1, n);
	while (m--) {
		int w;
		cin >> w;
		if (!w) {
			int x, y, c;
			cin >> x >> y >> c;
			upd_x(1, 1, n, x, y, c - arr[x][y]);
			arr[x][y] = c;
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			cout << qry_x(1, 1, n, x1, x2, y1, y2) << "\n";
		}
	}
}
