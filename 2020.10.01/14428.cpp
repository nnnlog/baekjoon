#include <bits/stdc++.h>

using namespace std;

int arr[100001], seg[400001];

int init(int node, int start, int end) {
	if (start == end) return seg[node] = start;
	int mid = start + end >> 1;
	int a = init(node * 2, start, mid), b = init(node * 2 + 1, mid + 1, end);
	if (arr[a] == arr[b]) return seg[node] = min(a, b);
	if (arr[a] > arr[b]) swap(a, b);
	return seg[node] = a;
}

int query(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return seg[node];
	if (left > end || right < start) return 0;

	int mid = start + end >> 1;
	int a = query(node * 2, start, mid, left, right), b = query(node * 2 + 1, mid + 1, end, left, right);
	if (arr[a] == arr[b]) return min(a, b);
	if (arr[a] > arr[b]) return b;
	else return a;
}

int update(int node, int start, int end, int index) {
	if (!(start <= index && index <= end)) return seg[node];
	if (start == end) return index;
	int mid = start + end >> 1;
	int a = update(node * 2, start, mid, index), b = update(node * 2 + 1, mid + 1, end, index);
	if (arr[a] == arr[b]) return seg[node] = min(a, b);
	if (arr[a] > arr[b]) swap(a, b);
	return seg[node] = a;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	arr[0] = 1e9 + 1;

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(1, 1, n);

	int m; cin >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 1) { //update
			arr[b] = c;
			update(1, 1, n, b);
		} else {
			cout << query(1, 1, n, b, c) << "\n";
		}
	}
}
