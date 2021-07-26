#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll arr[100001], seg[400001];

ll init(int node, int start, int end) {
	if (start == end) return seg[node] = start;
	int mid = start + end >> 1;
	int a = init(node * 2, start, mid), b = init(node * 2 + 1, mid + 1, end);
	if (arr[a] > arr[b]) return seg[node] = b;
	else return seg[node] = a;
}

ll find(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0; //1e10
	if (left <= start && end <= right) return seg[node];

	int mid = start + end >> 1;
	int a = find(node * 2, start, mid, left, right), b = find(node * 2 + 1, mid + 1, end, left, right);
	if (arr[a] > arr[b]) return seg[node] = b;
	else return seg[node] = a;
}

ll query(int left, int right) {
	if (left >= right) return 0;
	int index = find(1, 1, n, left, right);
	ll ans = (right - left + 1) * arr[index];
	ans = max(ans, query(left, index - 1));
	ans = max(ans, query(index + 1, right));
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	arr[0] = 1e10;

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(1, 1, n);

	cout << query(1, n);
}
