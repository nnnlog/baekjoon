#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

lld max(lld a, lld b, lld c, lld d) {
	return max(max(a, b), max(c, d));
}

struct Node {
	lld left, right, total, middle;
	lld ans() const {
		return max(left, right, total, middle);
	}
};

Node sum(Node l, Node r) {
	return Node{
			max(l.left, max(l.total + r.left, l.total)),
			max(r.right, max(r.total + l.right, r.total)),
			l.total + r.total,
			max(l.right + r.left, l.middle, r.middle, (lld)-1e9)
			//max(max(l.left, l.total + r.left), max(r.right, r.total + l.right), l.total + r.total, -1e9, max(l.right + l.left, r.ans, l.ans, l.total, r.total))
	};
}

vector<int> arr;
vector<Node> seg_tree;

Node init(int node, int start, int end) {
	if (start == end) return seg_tree[node] = Node{arr[start], arr[start], arr[start], arr[start]};
	int mid = (start + end) >> 1;
	return seg_tree[node] = sum(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

Node query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return Node{(int) -1e9, (int) -1e9, (int) -1e9, (int) -1e9};
	if (left <= start && end <= right) return seg_tree[node];
	int mid = (start + end) >> 1;//, l = query(node * 2, start, mid, left, right), r = query(node * 2 + 1, mid + 1, end, left, right);
	//cout << node << ": " << node * 2 << " - " << l << ", " << node * 2 + 1 << " - " << r << endl;
	//return max(l, r);
	return sum(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	arr.assign(n + 1, 0);
	seg_tree.assign(1 << (int) (1 + ceil(log2(n))), Node{(int) -1e9, (int) -1e9, (int) -1e9, (int) -1e9});

	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(1, 1, n);
	//for (int i = 1; i < seg_tree.size(); i++) if (seg_tree[i].ans) cout << i << ": " << seg_tree[i].ans << "\n";


	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << query(1, 1, n, a, b).ans() << "\n";
	}
}

