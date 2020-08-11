#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, Q;

vector<int> root(2000001);
vector<int> parent(2000001);
stack<pii> query;
stack<string> ans;

int find(int a) {
	return root[a] = (root[a] == a ? a : find(root[a]));
}

void merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y) {
		root[min(x, y)] = max(x, y);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> Q;

	parent[1] = root[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin >> parent[i];
		root[i] = i;
	}

	for (int i = 1; i < N + Q; i++) {
		int head;
		cin >> head;
		if (head) { //질의
			int a, b;
			cin >> a >> b;
			query.push(pii(a, b));
		} else { //에지 제거
			int a;
			cin >> a;
			query.push(pii(-1, a));
		}
	}

	while (!query.empty()) {
		pii c = query.top();
		query.pop();

		if (c.first != -1) {
			ans.push(find(c.first) == find(c.second) ? "YES" : "NO");
		} else {
			merge(c.second, parent[c.second]);
		}
	}

	while (!ans.empty()) {
		cout << ans.top() << "\n";
		ans.pop();
	}

}
