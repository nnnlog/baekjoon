#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> subject;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		subject.emplace_back();
		while (a--) {
			int b;
			cin >> b;
			subject[i].push_back(b);
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, ans = 0;
		cin >> a;

		vector<int> available(51, 0);
		while (a--) {
			int b;
			cin >> b;
			available[b] = 1;
		}

		for (const auto &b : subject) {
			bool flag = false;
			for (const auto &c : b) {
				if (!available[c]) {
					flag = true;
					break;
				}
			}

			if (!flag)ans++;

		}

		cout << ans << "\n";
	}
}