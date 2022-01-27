#include <bits/stdc++.h>

using namespace std;

int UF[1001];

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

int merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x != y) {
		UF[x] = y;
		return 1;
	}
	return 0;
}

struct A {
	int u, v, w;

	bool operator<(const A &other) const {
		return w < other.w;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) UF[i] = i;

	while (m--) {
		int a, b;
		cin >> a >> b;

		merge(a, b);
	}

	vector<A> vec;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int w; cin >> w;
			if (i != 1 && j != 1) vec.push_back(A{i, j, w});
		}
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	vector<pair<int, int>> add;
	for (const auto &a : vec) {
		if (merge(a.u, a.v)) {
			ans += a.w;
			add.emplace_back(a.u, a.v);
		}
	}

	cout << ans << " " << add.size() << "\n";
	for (const auto &a : add) cout << a.first << " " << a.second << "\n";
}
