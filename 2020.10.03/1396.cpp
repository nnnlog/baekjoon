#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pair<int, pair<int, int>>> nodes;
vector<pii> query, range;

int UF[100000], cnt[100000];
pii ans[100000];

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

void merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y) UF[x] = y, cnt[y] += cnt[x], cnt[x] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		nodes.emplace_back(--c, pii{--a, --b});
	}

	sort(nodes.begin(), nodes.end());

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v;
		query.emplace_back(--u, --v);
		range.emplace_back(0, m);
	}

	while (1) {
		int flag = 0;
		vector<vector<int>> mid(m + 1);
		for (int i = 0; i < q; i++) {
			if (range[i].first != range[i].second) {
				flag = 1;
				mid[range[i].first + range[i].second >> 1].emplace_back(i);
			}
		}
		if (!flag) break;

		for (int i = 0; i < n; i++) UF[i] = i, cnt[i] = 1;

		for (int i = 0; i < m; i++) {
			merge(nodes[i].second.first, nodes[i].second.second);
			for (const auto &k : mid[i]) {
				if (find(query[k].first) == find(query[k].second)) {
					ans[k].first = nodes[i].first;
					ans[k].second = cnt[find(query[k].first)];

					range[k].second = i;
				} else {
					range[k].first = i + 1;
				}
			}
		}
	}

	for (int i = 0; i < q; i++) {
		if (ans[i].second) cout << ans[i].first + 1 << " " << ans[i].second << "\n";
		else cout << "-1\n";
	}
}
