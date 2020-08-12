#include <bits/stdc++.h>

using namespace std;

int test[10000] = {2};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	vector<pair<int, int>> l;

	int sum = 0;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		l.emplace_back(a, i);
		sum += a;
	}

	sort(l.begin(), l.end(), greater<>());
	unordered_map<int, vector<int>> record;
	int ans = 0;
	record[0].push_back(-1);

	for (const auto &info : l) {
		for (int base = sum / 2; base >= 0; base--) {
			int after = info.first + base;
			if (!record[base].empty() && record[after].empty()) {
				ans = max(ans, after);
				record[after] = record[base];
				record[after].push_back(info.second);
			}
		}
	}

	cout << record[ans].size() - 1 << "\n";
	for (const auto &i : record[ans]) if (i > 0) cout << i << " ";
}
