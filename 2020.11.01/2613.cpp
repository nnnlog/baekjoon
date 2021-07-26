#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	int l = 0, r = 100 * 300;
	while (l < r) {
		int mid = l + r >> 1;
		int sum = 0, cnt = 0, fail = 0;
		for (const auto &i : vec) {
			if (i > mid) {
				fail = 1;
				break;
			}

			sum += i;
			if (sum > mid) {
				cnt++;
				sum = i;

				if (cnt > m) {
					break;
				}
				if (sum > mid) {
					cnt++;
					sum = 0;
				}
			}
		}

		if (sum) cnt++;
		if (cnt > m || fail) l = mid + 1;
		else r = mid;
	}


	int mid = l + r >> 1;
	vector<vector<int>> ans;
	int sum = 0;
	vector<int> tmp;
	for (const auto &i : vec) {
		int f = 0;

		sum += i;
		if (sum > mid) {
			sum = i;
			ans.push_back(tmp);
			tmp.clear();
			if (sum > mid) {
				f = 1;
				ans.push_back({i});
			}
		}
		if (!f) tmp.push_back(i);
	}

	if (sum) ans.push_back(tmp);

	cout << mid << "\n";
	int diff = m - (int) ans.size();
	for (const auto &comb : ans) {
		for (int i = 0; i < comb.size(); i++) {
			if (!diff || i + 1 == comb.size()) {
				cout << comb.size() - i << " ";
				break;
			} else cout << "1 ", diff--;
		}
	}
}
