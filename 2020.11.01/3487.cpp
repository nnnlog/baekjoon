#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void print(vector<ll> &vec, int start, int sz) {
	for (int i = 0; i < sz; i++) cout << vec[i + start] << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<ll> vec(n);
		for (int i = 0; i < n; i++) cin >> vec[i];

		ll l = 0, r = 5000000000;
		while (l < r) {
			ll mid = l + r >> 1;
			ll sum = 0, cnt = 0, fail = 0;
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

		ll mid = l + r >> 1;
		vector<vector<ll>> ans;
		ll sum = 0;
		vector<ll> tmp;
		reverse(vec.begin(), vec.end());
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

		int diff = m - (int) ans.size();
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			if (i) cout << "/ ";
			auto &comb = ans[i];
			reverse(comb.begin(), comb.end());
			for (int j = 0; j < comb.size(); j++) {
				if (j) cout << "/ ";
				if (!diff || j + 1 == comb.size()) {
					//cout << comb.size() - j << " ";
					print(comb, j, comb.size() - j);
					break;
				} else print(comb, j, 1), diff--;
			}
		}
		cout << "\n";
	}
}
