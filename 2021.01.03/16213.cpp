#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

unordered_map<int, vector<pair<int, int>>> edges;
vector<pair<int, vector<pair<int, int>>>> nodes;
vector<pii> query, range;

int UF[200000];

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

void merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y) UF[x] = y;
}

vector<int> idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, m, q; cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges[c].emplace_back(--a, --b);
		idx.push_back(c);
	}

	sort(idx.begin(), idx.end(), greater<>());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	for (const auto &[w, vec] : edges) {
		nodes.emplace_back(lower_bound(idx.begin(), idx.end(), w, greater<>()) - idx.begin(), vec);
	}
	sort(nodes.begin(), nodes.end());

	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v;
		query.emplace_back(--u, --v);
		range.emplace_back(0, idx.size());
	}

	while (1) {
		int flag = 0;
		vector<vector<int>> mid(idx.size() + 1);
		for (int i = 0; i < q; i++) {
			if (range[i].first < range[i].second) {
				flag = 1;
				mid[(range[i].first + range[i].second) >> 1].emplace_back(i);
			}
		}
		if (!flag) break;

		for (int i = 0; i < n; i++) UF[i] = i;

		for (int i = 0; i < idx.size(); i++) {
			for (const auto &[a, b] : nodes[i].second) merge(a, b);
			for (const auto &k : mid[i]) {
				if (find(query[k].first) == find(query[k].second)) {
					range[k].second = i;
				} else {
					range[k].first = i + 1;
				}
			}
		}
	}

	for (int i = 0; i < q; i++) {
		cout << idx[(range[i].first + range[i].second) >> 1] << "\n";
	}
}
